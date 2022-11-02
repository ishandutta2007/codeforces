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

const int mod=1000003;
//2^60>10^18

int mpow(int n,int m){
    int ret=1;
    while(m){
        if(m&1)ret=ret*n%mod;
        n=n*n%mod;
        m>>=1;
    }
    return ret;
}

signed main(){
    int N,K;
    cin>>N>>K;

    if(N<60&&(1ll<<N)<K){
        cout<<1<<" "<<1<<endl;
        return 0;
    }

    if(K>=mod){
        int cnt=0;
        for(int i=2;i<K;i*=2){
            cnt+=(K-1)/i%(mod-1);
        }
        cnt=(cnt+N)%(mod-1);
        int t=(K%(mod-1))*(N%(mod-1))%(mod-1);
        t=(t-cnt%(mod-1)+mod-1)%(mod-1);
        cout<<mpow(2,t)<<" "<<mpow(2,t)<<endl;
        return 0;
    }

    int cnt=N;
    for(int i=1;i<K;i++){
        int n=i;
        while(n%2==0){
            n/=2;
            cnt++;
        }
    }


    int t=mpow(2,N);
    int p=1;
    for(int i=0;i<K;i++){
        p=p*t%mod;
        t=(t-1+mod)%mod;
    }

    int tt=mpow(2,(N%(mod-1))*(K%(mod-1))%(mod-1));
    t=(tt-p+mod)%mod;

    int inv=mpow(2,mod-2);
    t=t*mpow(inv,cnt)%mod;
    tt=tt*mpow(inv,cnt)%mod;

    cout<<t<<" "<<tt<<endl;
    return 0;
}