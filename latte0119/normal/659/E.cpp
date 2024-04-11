#include<bits/stdc++.h>
using namespace std;

#define int long long
typedef pair<int,int>pint;
typedef vector<int>vint;
typedef vector<pint>vpint;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(v) (v).begin(),(v).end()
#define rep(i,n) for(int i=0;i<(n);i++)
#define reps(i,f,n) for(int i=(f);i<(n);i++)
#define each(it,v) for(__typeof((v).begin()) it=(v).begin();it!=(v).end();it++)
template<class T,class U>inline void chmin(T &t,U f){if(t>f)t=f;}
template<class T,class U>inline void chmax(T &t,U f){if(t<f)t=f;}

struct UF{
    int N;
    vint par,f;
    void init(int n){
        N=n;
        par.resize(N);f.resize(N);
        rep(i,N)par[i]=i,f[i]=0;
    }
    int find(int x){
        return x==par[x]?x:par[x]=find(par[x]);
    }
    void unite(int x,int y){
        x=find(x);y=find(y);
        if(x==y){
            f[x]=1;
        }
        else{
            f[x]|=f[y];
            par[y]=x;
        }
    }
};

int N,M;
signed main(){
    scanf("%lld%lld",&N,&M);
    UF uf;uf.init(N);
    rep(i,M){
        int a,b;
        scanf("%lld%lld",&a,&b);
        a--;b--;
        uf.unite(a,b);
    }

    int cnt=0;
    rep(i,N)if(uf.find(i)==i&&uf.f[i]==0)cnt++;
    cout<<cnt<<endl;
    return 0;
}