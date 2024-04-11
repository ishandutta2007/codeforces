#include<bits/stdc++.h>
using namespace std;

#define int long long

#define rep(i,n) for(int i=0;i<(n);i++)
#define pb push_back
#define all(v) (v).begin(),(v).end()
typedef vector<int>vint;
typedef pair<int,int>pint;

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

int fact[100000],inv[100000];

int comb(int n,int k){
    return fact[n]*inv[k]%mod*inv[n-k]%mod;
}

int N;
int A[500];

map<int,int>M;


signed main(){
    fact[0]=inv[0]=1;
    for(int i=1;i<100000;i++){
        fact[i]=fact[i-1]*i%mod;
        inv[i]=mpow(fact[i],mod-2);
    }

    scanf("%lld",&N);
    rep(i,N)scanf("%lld",&A[i]);

    rep(i,N){
        int a=A[i];
        for(int j=2;j*j<=A[i];j++){
            while(a%j==0){
                M[j]++;
                a/=j;
            }
        }
        if(a!=1)M[a]++;
    }

    int ans=1;
    for(map<int,int>::iterator it=M.begin();it!=M.end();it++){
        int c=it->second;
        ans=ans*comb(c+N-1,N-1)%mod;
    }
    printf("%lld\n",ans);
    return 0;
}