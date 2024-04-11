#include<bits/stdc++.h>
using namespace std;
const int nmax=200+5,mod=1e9+7;
int n;
string s;
int go[nmax][2];
int dp[nmax][nmax][nmax][2],SZ;
int rec(int pos,int open,int pos_in_s,bool done)
{
    if(pos_in_s==SZ)return rec(pos,open,nmax-1,1);
    if(pos>n)return (done&&open==0);
    if(dp[pos][open][pos_in_s][done]!=-1)return dp[pos][open][pos_in_s][done];
    int ans=0;
    //add '('
    ans=ans+rec(pos+1,open+1,go[pos_in_s][0],done);
    //add ')'
    if(open)ans=ans+rec(pos+1,open-1,go[pos_in_s][1],done);
    if(ans>=mod)ans=ans-mod;
    dp[pos][open][pos_in_s][done]=ans;
    //cout<<pos<<" "<<open<<" "<<pos_in_s<<" "<<done<<" -> "<<ans<<endl;
    return ans;
}
int main()
{
go[nmax-1][0]=nmax-1;
go[nmax-1][1]=nmax-1;

memset(dp,-1,sizeof(dp));
cin>>n>>s;
SZ=s.size();
s=" "+s;
for(int i=0;i<=SZ;i++)
    for(int which=0;which<2;which++)
    {
        string now="";
        for(int j=1;j<=i;j++)
            now.push_back(s[j]);
        if(which==0)now=now+"(";
        else now=now+")";
        for(int j=0;j<=i;j++)
        {
            bool eq=1;
            for(int k=j;k<=i;k++)
                if(now[k]!=s[k-j+1]){eq=0;break;}
            if(eq)
            {
            go[i][which]=i-j+1;
            break;
            }
        }
        //cout<<i<<" "<<which<<" -> "<<now<<" "<<go[i][which]<<endl;
    }
n=n*2;
cout<<rec(1,0,0,0)<<endl;
return 0;
}