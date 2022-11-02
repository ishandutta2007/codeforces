#include<bits/stdc++.h>
using namespace std;
int main(){
    string str;
    cin>>str;
    reverse(str.begin(),str.end());
    long long  ans=0;
    long long  dp[40];
    dp[0]=1;
    for(int i=1;i<=35;i++)dp[i]=dp[i-1]*2;
    for(int i=0;i<str.size();i++){
        if(str[i]=='4')ans+=dp[i];
        else ans+=dp[i]*2;
    }
    cout<<ans<<endl;
    return 0;
}