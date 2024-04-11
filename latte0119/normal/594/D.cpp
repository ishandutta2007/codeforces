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

const int mod=1000000007;
struct segtree{
    static const int N=1<<18;
    vint dat;
    segtree():dat(N*2,1){}
    void update(int a,int b,int x,int k=0,int l=0,int r=N){
        if(r<=a||b<=l)return;
        if(a<=l&&r<=b){
            dat[k]=dat[k]*x%mod;
            return;
        }
        update(a,b,x,k*2+1,l,(l+r)/2);
        update(a,b,x,k*2+2,(l+r)/2,r);
    }
    int query(int k){
        k+=N-1;
        int ret=dat[k];
        while(k){
            k=(k-1)/2;
            ret=ret*dat[k]%mod;
        }
        return ret;
    }
};

struct action{
    int left,right,mul;
    action(int lf,int rg,int ml):left(lf),right(rg),mul(ml){}
};

int modpow(int n,int m){
    int ret=1;
    while(m){
        if(m&1)ret=ret*n%mod;
        n=n*n%mod;
        m>>=1;
    }
    return ret;
}

int N;
int A[200000];
int inv[1111111];
int accmul[200000+1],accinv[200000+1];

vint ps;
int f[1000];
vector<action>acts[200000];
vector<pint>qs[200000];
int last_pos[1000000];
int ans[200000];
signed main(){
    for(int i=1;i<1111111;i++)inv[i]=modpow(i,mod-2);

    scanf("%lld",&N);
    rep(i,N)scanf("%lld",&A[i]);
    accmul[0]=accinv[0]=1;
    for(int i=0;i<N;i++){
        accmul[i+1]=accmul[i]*A[i]%mod;
        accinv[i+1]=modpow(accmul[i+1],mod-2);
    }

    fill_n(f,1000,1);f[0]=f[1]=0;
    for(int i=2;i<1000;i++){
        if(!f[i])continue;
        ps.pb(i);
        for(int j=i*2;j<1000;j+=i)f[j]=0;
    }

    memset(last_pos,-1,sizeof(last_pos));
    for(int i=0;i<N;i++){
        vector<int>fs;
        for(int j=0;j<ps.size();j++){
            if(A[i]%ps[j])continue;
            fs.push_back(ps[j]);
            while(A[i]%ps[j]==0)A[i]/=ps[j];
        }
        if(A[i]!=1)fs.push_back(A[i]);
        for(auto p:fs){
            acts[last_pos[p]+1].push_back(action(i,N,(p-1)*inv[p]%mod));
            if(i+1<N)acts[i+1].push_back(action(i,N,inv[p-1]*p%mod));
            last_pos[p]=i;
        }
    }

    int Q;scanf("%lld",&Q);
    rep(i,Q){
        int l,r;
        scanf("%lld%lld",&l,&r);
        l--;
        qs[l].push_back(pint(r,i));
    }

    segtree seg;

    rep(l,N){
        for(auto a:acts[l]){
            seg.update(a.left,a.right,a.mul);
        }
        rep(i,qs[l].size()){
            int r=qs[l][i].first;
            ans[qs[l][i].second]=accmul[r]*accinv[l]%mod*seg.query(r-1)%mod;
        }
    }
    for(int i=0;i<Q;i++)printf("%lld\n",ans[i]);
    return 0;
}