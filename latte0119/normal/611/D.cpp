#include<bits/stdc++.h>
using namespace std;

//#define int long long

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
template<class T,class U>void chmin(T &t,U f){if(t>f)t=f;}
template<class T,class U>void chmax(T &t,U f){if(t<f)t=f;}

typedef unsigned long long ull;

const ull p=1000000007;

int N;
string S;

const int mod=1000000007;

ull power[5001],H[5001];

int dp[5001][5001];

bool ok(int i,int j,int len){
    int lb=0,ub=len+1;
    while(ub-lb>1){
        int mid=(ub+lb)/2;
        ull h1=H[i+mid]-H[i]*power[mid];
        ull h2=H[j+mid]-H[j]*power[mid];
        if(h1==h2)lb=mid;
        else ub=mid;
    }
    if(lb==len)return false;
    return S[i+lb]<S[j+lb];
}

signed main(){
    cin>>N>>S;
    power[0]=1;
    rep(i,N){
        power[i+1]=power[i]*p;
        H[i+1]=H[i]*p+S[i];
    }


    rep(i,N+1)dp[0][i]=1;
    rep(i,N){
        for(int j=1;j<=N;j++){
            dp[i+1][j]=dp[i+1][j-1];
            if(j-1>i)continue;
            if(S[i-(j-1)]=='0')continue;
            int k=i-j;
            if(k+1<j){
                dp[i+1][j]=(dp[i+1][j]+dp[k+1][k+1])%mod;
            }
            else if(ok(k-(j-1),i-(j-1),j)){
                dp[i+1][j]=(dp[i+1][j]+dp[k+1][j])%mod;
            }
            else{
                dp[i+1][j]=(dp[i+1][j]+dp[k+1][j-1])%mod;
            }
        }
    }


    printf("%d\n",dp[N][N]);
    return 0;
}