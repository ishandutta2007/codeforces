#include<bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int>pint;
typedef vector<int>vint;
typedef vector<pint>vpint;
#define pb push_back
#define eb emplace_back
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
int fact[555555],inv[555555];
int mpow(int n,int m){
    int ret=1;
    while(m){
        if(m&1)ret=ret*n%mod;
        n=n*n%mod;
        m>>=1;
    }
    return ret;
}
int C(int n,int k){
    return fact[n]*inv[k]%mod*inv[n-k]%mod;
}

int N,K;
int L[222222],R[222222];

int sum[555555];

signed main(){
    fact[0]=inv[0]=1;
    for(int i=1;i<555555;i++){
        fact[i]=fact[i-1]*i%mod;
        inv[i]=mpow(fact[i],mod-2);
    }

    vint xs;
    scanf("%lld%lld",&N,&K);
    rep(i,N){
        scanf("%lld%lld",&L[i],&R[i]);
        R[i]++;
        xs.pb(L[i]);
        xs.pb(R[i]);
    }
    sort(all(xs));
    xs.erase(unique(all(xs)),xs.end());
    rep(i,N){
        L[i]=lower_bound(all(xs),L[i])-xs.begin();
        R[i]=lower_bound(all(xs),R[i])-xs.begin();
        sum[L[i]]++;
        sum[R[i]]--;
    }

    int ans=0;
    rep(i,xs.size()-1){
        sum[i+1]+=sum[i];
        int tmp=xs[i+1]-xs[i];
        if(sum[i]<K)continue;
        ans=(ans+C(sum[i],K)*tmp)%mod;
    }
    printf("%lld\n",ans);

    return 0;
}