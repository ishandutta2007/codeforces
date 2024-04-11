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

int N;

int X[555555],Y[555555],L[555555];
char tmp[111];
signed main(){
    scanf("%lld",&N);
    rep(i,N){
        scanf("%s",tmp);
        int l=strlen(tmp);
        X[i]=tmp[0]-'a';
        Y[i]=tmp[l-1]-'a';
        L[i]=l;
    }

    int dp[26];

    int ans=0;
    for(int i=0;i<26;i++){
        fill_n(dp,26,-100);
        dp[i]=0;

        for(int i=0;i<N;i++){
            chmax(dp[Y[i]],dp[X[i]]+L[i]);
        }
        chmax(ans,dp[i]);
    }

    cout<<ans<<endl;
    return 0;
}