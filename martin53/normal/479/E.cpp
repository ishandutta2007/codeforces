#include<bits/stdc++.h>
using namespace std;
const int nmax=5e3+42,mod=1e9+7;
int prefix[nmax][2],dp[nmax][2];
int add(int x,int y)
{
x=x+y;
if(x>=mod)x=x-mod;
return x;
}
int b_;
int sum(int l,int r,bool where)
{
//cout<<"sum "<<l<<" "<<r<<" "<<where<<endl;
if(l>r)return 0;
if(l>=b_)return 0;
if(r>=b_)r=b_-1;
if(l<=0)l=1;
//cout<<prefix[r][where]-prefix[l-1][where]<<endl;
return add(prefix[r][where]-prefix[l-1][where],mod);
}
int solve(int n,int a,int b,int k)
{
if(a>b)return solve(n,n+1-a,n+1-b,k);
//a<b
b_=b;
dp[a][0]=1;
for(int i=1;i<b;i++)
    prefix[i][0]=prefix[i-1][0]+dp[i][0];

for(int trip=1;trip<=k;trip++)
{
    for(int y=1;y<b;y++)
    {
        dp[y][trip&1]=add(sum(1,y-1,!(trip&1)),sum(y+1,(b+y-1)/2,!(trip&1)));
        prefix[y][trip&1]=add(prefix[y-1][trip&1],dp[y][trip&1]);
        //cout<<y<<" "<<trip<<" -> "<<dp[y][trip&1]<<endl;
    }
    //cout<<"---"<<endl;
}
int ans=0;
for(int x=1;x<b;x++)ans=add(ans,dp[x][k&1]);
return ans;
}
int main()
{
int n,a,b,k;
cin>>n>>a>>b>>k;
cout<<solve(n,a,b,k)<<endl;
return 0;
}