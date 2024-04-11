#include<bits/stdc++.h>
using namespace std;

#define int long long

#define rep(i,n) for(int i=0;i<(n);i++)
#define pb push_back
#define all(v) (v).begin(),(v).end()
#define fi first
#define se second
typedef vector<int>vint;
typedef pair<int,int>pint;
typedef vector<pint>vpint;

template<typename A,typename B>inline void chmin(A &a,B b){if(a>b)a=b;}
template<typename A,typename B>inline void chmax(A &a,B b){if(a<b)a=b;}

const int ISPRIME_SIZE=2222222;
bool isprime[ISPRIME_SIZE];
int cnt[ISPRIME_SIZE];
struct isprime_exec{
    isprime_exec(){
        for(int i=0;i<ISPRIME_SIZE;i++)isprime[i]=true;
        isprime[0]=isprime[1]=false;
        for(int i=2;i<ISPRIME_SIZE;i++){
            if(!isprime[i])continue;
            cnt[i]=1;
            for(int j=i+i,k=2;j<ISPRIME_SIZE;j+=i,k++){
                isprime[j]=false;
                if(k%i==0)cnt[j]=INT_MIN;
                else cnt[j]++;
            }
        }
    }
}isprimeexec;

int N,K;
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
int po[2222222];
int b[2222222];
signed main(){
    cin>>N>>K;
    for(int i=1;i<2222222;i++)po[i]=mpow(i,N);

    for(int i=1;i<=K;i++){
        if(cnt[i]<0)continue;
        int k=1;if(cnt[i]&1)k=-1;
        for(int j=1;i*j<=K;j++){
            b[i*j]+=k*(po[j]-po[j-1]);
        }
    }

    rep(i,2222222-1)b[i+1]+=b[i];

    int ans=0;
    for(int i=1;i<=K;i++){
        b[i]=(b[i]+1000000000*mod)%mod;
        ans=(ans+(b[i]^i))%mod;
    }
    cout<<ans<<endl;
    return 0;
}