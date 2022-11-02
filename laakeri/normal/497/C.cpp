#include <iostream>
#include <vector>
#include <set>
#include <map>
#define F first
#define S second

using namespace std;

int v[100001];

set<int> its;

map<int, int> cc;//iso->pieni
map<int, int> ivcc;//pieni->iso

int rpa[100001];
int rpb[100001];

int aa[100001];
int ab[100001];
int ak[100001];

vector<pair<int, int> > pe[500001];

vector<pair<pair<int, int>, int> > ae[500001];

const int N=500010;

int st[2*N];
int f[2*N];

vector<int> of[500001];

void add(int i, int ff){
    st[i+N]++;
    f[i+N]=i;
    of[i].push_back(ff);
    for (i=(i+N)/2;i;i/=2){
        st[i]=st[i*2]+st[i*2+1];
        if (st[i*2]>0) f[i]=f[i*2];
        else f[i]=f[i*2+1];
    }
}

int take(int i){
    int r=of[i].back();
    of[i].pop_back();
    st[i+N]--;
    for (i=(i+N)/2;i;i/=2){
        st[i]=st[i*2]+st[i*2+1];
        if (st[i*2]>0) f[i]=f[i*2];
        else f[i]=f[i*2+1];
    }
    return r;
}

int get(int a, int b){
    a+=N;
    b+=N;
    int s=0;
    int fo=1e9;
    while (a<=b){
        if (a%2){
            if (st[a]){
                fo=min(fo, f[a]);
                s+=st[a];
            }
            a++;
        }
        if (!(b%2)){
            if (st[b]){
                fo=min(fo, f[b]);
                s+=st[b];
            }
            b--;
        }
        a/=2;
        b/=2;
    }
    if (s==0) return -1;
    return fo;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    for (int i=0;i<n;i++){
        cin>>rpa[i]>>rpb[i];
        its.insert(rpa[i]);
        its.insert(rpb[i]);
    }
    int m;
    cin>>m;
    for (int i=0;i<m;i++){
        cin>>aa[i]>>ab[i]>>ak[i];
        its.insert(aa[i]);
        its.insert(ab[i]);
    }
    int it=1;
    for (int i:its){
        cc[i]=it;
        ivcc[it]=i;
        it++;
    }
    for (int i=0;i<n;i++){
        pe[cc[rpb[i]]].push_back({cc[rpa[i]], i});
    }
    for (int i=0;i<m;i++){
        ae[cc[ab[i]]].push_back({{cc[aa[i]], i}, ak[i]});
    }
    int fo=0;
    for (int i=0;i<=it;i++){
        for (auto lol:pe[i]){
            add(lol.F, lol.S);
        }
        for (auto lol:ae[i]){
            int tt=lol.S;
            while (1){
                int a=get(lol.F.F, i);
                if (a==-1) break;
                fo++;
                int tv=take(a);
                v[tv]=lol.F.S;
                tt--;
                if (tt<=0) break;
            }
        }
    }
    if (fo<n){
        cout<<"NO"<<endl;
        return 0;
    }
    else{
        cout<<"YES"<<endl;
        for (int i=0;i<n;i++){
            cout<<v[i]+1<<" ";
        }
    }
}