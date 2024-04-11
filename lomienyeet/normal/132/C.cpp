// toxic q
// or maybe i overcomplicated?

#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,dp[2][105][55][205]; // {dir, cmd pos, changes, turtle pos}
string s;
int eat(int a,int b,int c,int d){
    if(b==s.length()){
        if(c==n)return abs(d-100);
        else return -1e18;
    }
    if(dp[a][b][c][d]!=-1)return dp[a][b][c][d];
    int ans=0;
    for(int i=0;i<n-c+1;i++){
        if(i&1){
            if(s[b]=='F')ans=max(ans,eat(1-a,b+1,c+i,d));
            else{
                if(a==1)ans=max(ans,eat(a,b+1,c+i,d+1));
                else ans=max(ans,eat(a,b+1,c+i,d-1));
            }
        }
        else{
            if(s[b]=='T')ans=max(ans,eat(1-a,b+1,c+i,d));
            else{
                if(a==1)ans=max(ans,eat(a,b+1,c+i,d+1));
                else ans=max(ans,eat(a,b+1,c+i,d-1));
            }
        }
    }
    return dp[a][b][c][d]=ans;
}
signed main(){
    cin>>s>>n;
    memset(dp,-1,sizeof dp);
    cout<<eat(1,0,0,100)<<"\n";
}