#include <iostream>
#include <vector>
#define F first
#define S second

using namespace std;

int v[300001];

int N=1<<20;

int st[1<<21];

int add (int i){
    for (i+=N;i;i/=2) st[i]++;
}

int sum (int a, int b){
    a+=N;
    b+=N;
    int s=0;
    while (a<=b){
        if (a%2) s+=st[a++];
        if (!(b%2)) s+=st[b--];
        a/=2;
        b/=2;
    }
    return s;
}

vector<pair<int,int> > qs[1000001];
vector<int> is[1000001];

int main(){
    int n,m;
    cin>>n>>m;
    for (int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        is[b].push_back(a);
    }
    for (int i=0;i<m;i++){
        int nn;
        cin>>nn;
        int edc=0;
        for (int ii=0;ii<nn;ii++){
            int c;
            cin>>c;
            qs[c-1].push_back(make_pair(edc+1,i));
            edc=c;
        }
        if (edc<1e6){
            qs[(int)1e6].push_back(make_pair(edc+1, i));
        }
    }
    int s=0;
    for (int i=1;i<=1e6;i++){
        for (int ii=0;ii<is[i].size();ii++){
            s++;
            add(is[i][ii]);
            //cout<<i<<" "<<is[i][ii]<<endl;
        }
        for (auto q:qs[i]){
            v[q.S]+=s;
            v[q.S]-=sum(0, q.F-1);
            //cout<<i<<" "<<q.S<<" "<<q.F<<" "<<s<<" "<<sum(0, q.F-1)<<endl;
        }
    }
    for (int i=0;i<m;i++){
        cout<<n-v[i]<<endl;
    }
}