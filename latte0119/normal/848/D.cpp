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

int fact[11111],inv[11111];
int mpow(int n,int m){
    int ret=1;
    while(m){
        if(m&1)ret=ret*n%mod;
        n=n*n%mod;
        m>>=1;
    }
    return ret;
}
int s[55][55],d[55][55];

int N,M;

inline void add(int &a,int b){
    a+=b;
    if(a>=mod)a-=mod;
}

int dp[55][55];

signed main(){
    fact[0]=1;
    for(int i=1;i<11111;i++)fact[i]=fact[i-1]*i%mod;
    inv[11111-1]=mpow(fact[11111-1],mod-2);
    for(int i=11111-2;i>=0;i--)inv[i]=inv[i+1]*(i+1)%mod;

    cin>>N>>M;
    d[0][0]=1;
    for(int i=1;i<=N;i++){
        for(int j=0;j<i;j++){
            for(int k=0;k<=j;k++){
                int l=i-j-1;
                for(int m=0;m<=l;m++){
                    add(s[i][min(k,m)+1],d[j][k]*d[l][m]%mod);
                }
            }
        }

        memset(dp,0,sizeof(dp));
        dp[0][0]=1;
        for(int j=1;j<=i;j++){
            for(int k=0;k<=j;k++){
                if(s[j][k]==0)continue;
                for(int l=i;l>=0;l--){
                    for(int m=l;m>=0;m--){
                        int t=1;
                        for(int x=1;j*x+l<=i&&k*x+m<=i;x++){
                            t=t*(s[j][k]+x-1)%mod;

                            add(dp[l+j*x][m+k*x],dp[l][m]*t%mod*inv[x]%mod);
                        }
                    }
                }
            }
        }

        for(int j=0;j<=i;j++)d[i][j]=dp[i][j];
    }



    cout<<d[N][M-1]<<endl;
    return 0;
}