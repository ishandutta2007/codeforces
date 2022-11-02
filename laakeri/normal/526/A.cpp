#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long ll;

int dp[1000][1000];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    string s;
    cin>>n>>s;
    int ma=0;
    for (int i=0;i<n;i++){
        for (int ii=1;ii<n;ii++){
            ma=max(dp[i][ii], ma);
            if (i+ii<n&&s[i]=='*'&&s[i+ii]=='*') dp[i+ii][ii]=max(dp[i][ii]+1, dp[i+ii][ii]);
        }
    }
    if (ma>3) cout<<"yes"<<endl;
    else cout<<"no"<<endl;
}