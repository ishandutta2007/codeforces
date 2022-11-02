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

int dp[2222][2222];

int M,N;
string S;

signed main(){
    dp[0][0]=1;
    rep(i,2000){
        rep(j,2000){
            dp[i+1][j+1]=(dp[i+1][j+1]+dp[i][j])%mod;
            if(j)dp[i+1][j-1]=(dp[i+1][j-1]+dp[i][j])%mod;
        }
    }

    cin>>M>>N>>S;
    int L=M-N;
    int pre=0,suf=0,sta=0;
    rep(i,N){
        if(S[i]=='('){
                sta++;
        }
        else{
            if(sta>0)sta--;
            else{
                pre++;
            }
        }
    }
    suf=sta;

    int ans=0;
    for(int i=0;i<=L;i++){
        int j=L-i;
        for(int k=0;pre+k<=i&&suf+k<=j;k++){
            ans=(ans+dp[i][pre+k]*dp[j][suf+k])%mod;
        }
    }

    cout<<ans<<endl;
    return 0;
}