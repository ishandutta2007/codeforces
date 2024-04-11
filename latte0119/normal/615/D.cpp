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
template<class T,class U>void chmin(T &t,U f){if(t>f)t=f;}
template<class T,class U>void chmax(T &t,U f){if(t<f)t=f;}

const int mod=1000000007;

int mpow(int n,int m){
    int ret=1;
    while(m){
        if(m&1)ret=ret*n%mod;
        n=n*n%mod;
        m>>=1;
    }
    return ret;
}

int cnt[200000];

signed main(){
    int M;scanf("%lld",&M);
    int N=1;
    rep(i,M){
        int p;scanf("%lld",&p);cnt[p]++;
        N=N*p%mod;
    }

    int c=1;
    rep(i,200000)c=c*(cnt[i]+1)%(2*mod-2);

    if(c&1){
        N=1;
        rep(i,200000)N=N*mpow(i,cnt[i]/2)%mod;
        printf("%lld\n",mpow(N,c));
    }
    else{
        printf("%lld\n",mpow(N,c/2));
    }
    return 0;
}