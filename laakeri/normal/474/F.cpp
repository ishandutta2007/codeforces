#include <iostream>
#include <map>
#include <vector>
#define F first
#define S second

using namespace std;

map<int, vector<int> > ls;

const int N=101010;

int sp[2*N];

int gcd(int m, int n) {
    if (m%n==0) return n;
    return gcd(n, m%n);
}

int get(int a, int b){
    a+=N;
    b+=N;
    int v=0;
    while (a<=b){
        if (a%2){
            if (v==0){
                v=sp[a];
            }
            else if(sp[a]) {
                v=gcd(v, sp[a]);
            }
            a++;
        }
        if (!(b%2)){
            if (v==0){
                v=sp[b];
            }
            else if(sp[b]) {
                v=gcd(v, sp[b]);
            }
            b--;
        }
        a/=2;
        b/=2;
    }
    return v;
}

int v=0;

vector<int> ps;

void ds(int x, vector<pair<int, int> >&ats, int l, int r, int id){
    int mi=0;
    int ma=ls[x].size()-1;
    while (mi<=ma){
        int m=(mi+ma)/2;
        if (ls[x][m]<l){
            mi=m+1;
        }
        else{
            ma=m-1;
        }
    }
    int mimi=mi;
    mi=mimi;
    ma=ls[x].size()-1;
    while (mi<=ma){
        int m=(mi+ma)/2;
        if (ls[x][m]>r){
            ma=m-1;
        }
        else{
            mi=m+1;
        }
    }
    if (mimi<=ma){
        v+=ma-mimi+1;
    }
    for (int i=id;i<ats.size();i++){
        int xx=x;
        for (int ii=0;ii<ats[i].S;ii++){
            xx*=ats[i].F;
            ds(xx, ats, l, r, i+1);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    for (int i=2;i*i<=1e9;i++){
        int f=0;
        for (int p:ps){
            if (i%p==0){
                f=1;
                break;
            }
            if (p*p>i) break;
        }
        if (!f){
            ps.push_back(i);
        }
    }
    int n;
    cin>>n;
    for (int i=0;i<n;i++){
        int a;
        cin>>a;
        sp[i+N]=a;
        ls[a].push_back(i+1);
    }
    for (int i=N-1;i;i--){
        if (sp[i*2]&&sp[i*2+1]) sp[i]=gcd(sp[i*2], sp[i*2+1]);
        else if (sp[i*2]) sp[i]=sp[i*2];
        else if (sp[i*2+1]) sp[i]=sp[i*2+1];
    }
    int q;
    cin>>q;
    for (int i=0;i<q;i++){
        int a,b;
        cin>>a>>b;
        int d=get(a-1, b-1);
        v=0;
        vector<pair<int, int> > ats;
        for (int p:ps){
            if (d%p==0){
                ats.push_back(make_pair(p, 1));
                d/=p;
            }
            while (d%p==0){
                ats.back().S++;
                d/=p;
            }
            if (p*p>d) break;
        }
        if (d>1){
            ats.push_back(make_pair(d, 1));
        }
        ds(1, ats, a, b, 0);
        cout<<b-a+1-v<<'\n';
    }
}