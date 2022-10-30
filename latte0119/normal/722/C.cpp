#include<bits/stdc++.h>
using namespace std;

#define int long long
typedef vector<int>vint;
typedef pair<int,int>pint;
typedef vector<pint>vpint;
#define rep(i,n) for(int i=0;i<(n);i++)
#define reps(i,f,n) for(int i=(f);i<(n);i++)
#define all(v) (v).begin(),(v).end()
#define each(it,v) for(__typeof((v).begin()) it=(v).begin();it!=(v).end();it++)
#define pb push_back
#define fi first
#define se second
template<typename A,typename B>inline void chmin(A &a,B b){if(a>b)a=b;}
template<typename A,typename B>inline void chmax(A &a,B b){if(a<b)a=b;}

struct UF{
    int N;
    vint par,sum;
    void init(int n,vint A){
        N=n;
        par.resize(N);sum.resize(N);
        rep(i,N){
            par[i]=i;
            sum[i]=A[i];
        }
    }
    int find(int x){
        return x==par[x]?x:par[x]=find(par[x]);
    }
    void unite(int x,int y){
        x=find(x);y=find(y);
        if(x==y)return;
        par[y]=x;
        sum[x]+=sum[y];
    }
};

bool flag[100000];
int ans[100000];
signed main(){
    int N;scanf("%lld",&N);
    vint A(N),B(N);
    rep(i,N)scanf("%lld",&A[i]);
    rep(i,N)scanf("%lld",&B[i]),B[i]--;

    UF uf;
    uf.init(N,A);

    int ma=0;
    for(int i=N-1;i>=0;i--){
        ans[i]=ma;
        flag[B[i]]=true;
        if(B[i]>0&&flag[B[i]-1]){
            uf.unite(B[i],B[i]-1);
        }
        if(B[i]+1<N&&flag[B[i]+1]){
            uf.unite(B[i],B[i]+1);
        }
        chmax(ma,uf.sum[uf.find(B[i])]);
    }

    rep(i,N)printf("%lld\n",ans[i]);
    return 0;
}