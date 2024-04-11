#include<bits/stdc++.h>
using namespace std;
const int LIM=1e6+42;
int n,m;
int seen[LIM];
int dp[LIM][3][3];
int rec(int pos,int rem_1,int rem_2)
{
    if(pos>m)return 0;
    if(dp[pos][rem_1][rem_2]!=-1)return dp[pos][rem_1][rem_2];
    int ret=0;
    for(int i=0;i<3;i++)
        if(seen[pos]>=rem_1+rem_2+i&&
           seen[pos+1]>=rem_2+i&&
           seen[pos+2]>=i
           )ret=max(ret,i+rec(pos+1,rem_2,i)+(seen[pos]-rem_1-rem_2-i)/3);
    //cout<<pos<<" "<<rem_1<<" "<<rem_2<<" -> "<<ret<<endl;
    dp[pos][rem_1][rem_2]=ret;
    return ret;
}
int main()
{
memset(dp,-1,sizeof(dp));
ios_base::sync_with_stdio(false);
cin.tie();
cin>>n>>m;
int x;
for(int i=1;i<=n;i++)
{
    cin>>x;
    seen[x]++;
}
cout<<rec(1,0,0)<<endl;
return 0;
}