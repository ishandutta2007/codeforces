#include<bits/stdc++.h>
using namespace std;
const int nmax=55;
long long dp[nmax][10];
string inp;
bool eq(int a,int b,int c)
{
    if((a+b)%2==0)return (a+b)/2==c;
    return (a+b)/2==c||(a+b)/2+1==c;
}
int main()
{
cin>>inp;
int n=inp.size();
inp=" "+inp;

for(int j=0;j<=9;j++)
    dp[1][j]=1;

for(int i=2;i<=n;i++)
    for(int dig=0;dig<=9;dig++)
        for(int prev=0;prev<=9;prev++)
            if(eq(prev,inp[i]-'0',dig))
            {
            dp[i][dig]+=dp[i-1][prev];
            //cout<<"\t "<<i<<" "<<dig<<" -> "<<prev<<endl;
            }
long long ans=0;
for(int i=0;i<=9;i++)
    {
    ans=ans+dp[n][i];
    //cout<<n<<" "<<i<<" -> "<<dp[n][i]<<endl;
    }
bool rem=1;
for(int i=2;i<=n;i++)
    if(eq(inp[i-1]-'0',inp[i]-'0',inp[i]-'0')==0)rem=0;

printf("%lld\n",ans-rem);
return 0;
}