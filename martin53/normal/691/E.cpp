#include<bits/stdc++.h>
using namespace std;
const int nmax=100+5,mod=1e9+7;
int n;
long long k;
long long arr[nmax];
long long matt[nmax][nmax],path[nmax][nmax],help[nmax][nmax];
bool ask(long long x)
{
    int bits=0;
    while(x)
    {
        bits=bits+(x%2);
        x=x/2;
    }
    return bits%3==0;
}
int main()
{
cin>>n>>k;
for(int i=1;i<=n;i++)cin>>arr[i];
for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++)
    path[i][j]=ask(arr[i]^arr[j]);

for(int i=1;i<=n;i++)matt[i][i]=1;

k--;
while(k)
{
    if(k%2==1)
    {
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)help[i][j]=0;

        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                for(int p=1;p<=n;p++)
                help[i][j]=(help[i][j]+matt[i][p]*path[p][j])%mod;

        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                matt[i][j]=help[i][j];
    }

        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)help[i][j]=0;

        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                for(int p=1;p<=n;p++)
                help[i][j]=(help[i][j]+path[i][p]*path[p][j])%mod;

        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                path[i][j]=help[i][j];
        k=k/2;
}
long long ans=0;
for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++)
    ans=(ans+matt[i][j])%mod;
cout<<ans<<endl;
return 0;
}