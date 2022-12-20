#include<bits/stdc++.h>
using namespace std;
const int nmax=3e2+5,mod=1e9+7,lim=1e5+42;
int n,q,t;
int in[nmax],out[nmax];
int coin[nmax];
bool been[nmax];
int values[nmax];
int dp[2][lim];
int main()
{
cin>>n>>q>>t;
for(int i=1;i<=n;i++)cin>>coin[i];
int b,c;
for(int i=1;i<=q;i++)
{
cin>>b>>c;
out[b]=c;
in[c]=b;
}

for(int i=1;i<=n;i++)
{
    memset(been,0,sizeof(been));
    int where=out[i];
    while(where)
    {
        if(been[where])
        {
            cout<<0<<endl;
            return 0;
        }
        been[where]=1;
        where=out[where];
    }

}
//no cycles
/*
cout<<"in:  ";for(int i=1;i<=n;i++)cout<<in[i]<<" ";cout<<endl;
cout<<"out: ";for(int i=1;i<=n;i++)cout<<out[i]<<" ";cout<<endl;
*/
int p=0;
for(int i=1;i<=n;i++)
    if(in[i]==0)
    {
        //cout<<"i= "<<i<<endl;
        int where=i,cyc=0,s=0;
        while(where)
        {
            t=t-s;
            if(t<0)
            {
                cout<<0<<endl;
                return 0;
            }
            s=s+coin[where];
            cyc++;
            where=out[where];
        }
        s=0;
        where=i;
        //cout<<"where= "<<where<<endl;
        while(where)
        {
            p++;
            s=s+coin[where];
            values[p]=s;
            where=out[where];
        }
    }
/*
cout<<"t= "<<t<<endl;
for(int i=1;i<=p;i++)cout<<values[i]<<" ";cout<<endl;
*/
dp[0][0]=1;
for(int pos=1;pos<=n;pos++)
{
    dp[pos&1][0]=1;
    for(int sum=1;sum<=t;sum++)
    {
        dp[pos&1][sum]=dp[!(pos&1)][sum];
        if(sum>=values[pos])
            dp[pos&1][sum]=dp[pos&1][sum]+dp[pos&1][sum-values[pos]];
        if(dp[pos&1][sum]>=mod)dp[pos&1][sum]=dp[pos&1][sum]-mod;
        //cout<<pos<<" "<<sum<<" -> "<<dp[pos&1][sum]<<endl;
    }
}

cout<<dp[n&1][t]<<endl;
return 0;
}