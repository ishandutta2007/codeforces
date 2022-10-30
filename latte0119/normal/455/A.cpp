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

int N;
int cnt[111111];

int dp[111111];
signed main(){
    cin>>N;
    rep(i,N){
        int a;cin>>a;
        a--;
        cnt[a]++;
    }

    for(int i=0;i<100000;i++){
        chmax(dp[i+2],dp[i]+cnt[i]*(i+1));
        chmax(dp[i+1],dp[i]);
    }
    cout<<max(dp[100000],dp[100001])<<endl;
    return 0;
}