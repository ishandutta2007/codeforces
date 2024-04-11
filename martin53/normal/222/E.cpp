#include<bits/stdc++.h>
using namespace std;
const int mmax=55,mod=1e9+7;
long long n,m,k;
bool blocked[mmax][mmax];
int where(char x)
{
if('a'<=x&&x<='z')return x-'a'+1;
return x-'A'+1+26;
}
long long result[mmax][mmax],help[mmax][mmax];
long long mem[mmax][mmax];
void mult_result()
{
    memset(mem,0,sizeof(mem));
    for(int i=1;i<=m;i++)
        for(int j=1;j<=m;j++)
        {
            for(int p=1;p<=m;p++)
                mem[i][j]=(mem[i][j]+result[i][p]*help[p][j])%mod;
        }
     for(int i=1;i<=m;i++)
        for(int j=1;j<=m;j++)
            result[i][j]=mem[i][j];
}
void mult_help()
{
    memset(mem,0,sizeof(mem));
    for(int i=1;i<=m;i++)
        for(int j=1;j<=m;j++)
        {
            for(int p=1;p<=m;p++)
                mem[i][j]=(mem[i][j]+help[i][p]*help[p][j])%mod;
        }
     for(int i=1;i<=m;i++)
        for(int j=1;j<=m;j++)
            help[i][j]=mem[i][j];

    /*
    cout<<"help squared: "<<endl;
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=m;j++)cout<<help[i][j]<<" ";cout<<endl;
    }
    */
}
int main()
{
cin>>n>>m>>k;
char c1,c2;
for(int i=1;i<=k;i++)
{
cin>>c1>>c2;
blocked[where(c1)][where(c2)]=1;
}
n--;
for(int i=1;i<=m;i++)
    for(int j=1;j<=m;j++)
    {
    if(i==j)result[i][j]=1;
    else result[i][j]=0;
    help[i][j]=1-blocked[i][j];
    }

while(n)
{
    if(n%2==1)
        mult_result();
    mult_help();
    n=n/2;
}
long long ans=0;
for(int i=1;i<=m;i++)
    for(int j=1;j<=m;j++)
        ans=(ans+result[i][j])%mod;
cout<<ans<<endl;
return 0;
}