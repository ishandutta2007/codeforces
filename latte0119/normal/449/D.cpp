
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

const int mod=1000000007;

int N;
int A[1<<20];

int f[1<<20];

int po[1<<20];
signed main(){
    scanf("%lld",&N);
    rep(i,N)scanf("%lld",&A[i]);

    rep(i,N)f[A[i]]++;
    rep(i,20)rep(j,1<<20)if(!(j&(1<<i)))f[j]+=f[j|(1<<i)];

    po[0]=1;
    for(int i=1;i<1<<20;i++)po[i]=po[i-1]*2%mod;

    int val=0;
    for(int i=0;i<1<<20;i++){
        int c=__builtin_popcount(i);
        int tmp=po[f[i]];
        tmp=(tmp-1+mod)%mod;
        if(c&1)val=(val-tmp+mod)%mod;
        else val=(val+tmp+mod)%mod;
    }
    cout<<val<<endl;
    return 0;
}