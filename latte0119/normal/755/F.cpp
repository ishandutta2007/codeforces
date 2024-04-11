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
    vector<int>par,sz;
    void init(int n){
        par.resize(n);
        sz.resize(n);
        for(int i=0;i<n;i++){
            par[i]=i;
            sz[i]=1;
        }
    }
    int find(int x){
        return x==par[x]?x:par[x]=find(par[x]);
    }
    void unite(int x,int y){
        x=find(x);y=find(y);
        if(x==y)return;
        sz[x]+=sz[y];
        par[y]=x;
    }
    bool same(int x,int y){
        return find(x)==find(y);
    }
    int size(int x){
        return sz[find(x)];
    }
};

int N,K;
int cnt[1000010];
int dp[1000010];

bool solve(vint &v,int K){
    rep(i,v.size())cnt[v[i]]++;
    memset(dp,-1,sizeof(dp));
    dp[0]=0;
    int r=0;
    for(int i=1;i<=K;i++){
        if(cnt[i]==0)continue;
        r+=cnt[i]*i;
        chmin(r,K);
        for(int j=0;j<i;j++)if(dp[j]>=0)dp[j]=cnt[i];
        for(int j=i;j<=r;j++){
            dp[j]=dp[j]>=0?cnt[i]:(dp[j-i]-1);
        }
    }
    return dp[K]>=0;
}

signed main(){
    scanf("%lld%lld",&N,&K);
    vint p(N);
    rep(i,N)scanf("%lld",&p[i]),p[i]--;

    /*
    N=1000000;
    K=114514;
    srand((unsigned)time(NULL));
    vint p(N);rep(i,N)p[i]=i;
    random_shuffle(all(p));
    */


    UF uf;uf.init(N);
    rep(i,N)uf.unite(i,p[i]);

    vint v;
    rep(i,N)if(uf.find(i)==i)v.pb(uf.size(i));
    sort(all(v));

    if(solve(v,min(K,N-K)))cout<<K;
    else cout<<K+1;

    int sum=0,cnt=0;
    for(int i=v.size()-1;i>=0;i--){
        int tmp=min(v[i]/2,K-cnt);
        v[i]-=tmp*2;
        sum+=tmp*2;
        cnt+=tmp;
        if(cnt==K)break;
    }
    for(int i=0;i<v.size()&&cnt<K;i++){
        if(v[i]){
            sum++;cnt++;
        }
    }

    cout<<" "<<sum<<endl;
    return 0;
}