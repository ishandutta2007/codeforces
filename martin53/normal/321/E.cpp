#include<bits/stdc++.h>
using namespace std;
const int nmax=4e3+42,kmax=800+42;
int dp[nmax][kmax];
int n,k;
int inp[nmax][nmax];
int sums[nmax][nmax];
int cost(int l,int r)
{
//cout<<"cost "<<l<<" "<<r<<" -> "<<sums[r][r]+sums[l-1][l-1]-sums[l-1][r]-sums[r][l-1]<<endl;
return sums[r][r]+sums[l-1][l-1]-sums[l-1][r]-sums[r][l-1];
}
int brute_force(int groups,int pos,int l_possible,int r_possible)
{
    dp[pos][groups]=1e9;
    int best=0;
    r_possible=min(r_possible,pos);
    for(int j=l_possible;j<=r_possible;j++)
    {
        int now=dp[j-1][groups-1]+cost(j,pos);
        if(now<dp[pos][groups])
        {
        dp[pos][groups]=now;
        best=j;
        }
    }
    //cout<<"pos= "<<pos<<" groups= "<<groups<<" -> "<<dp[pos][groups]<<endl;
    return best;
}
void solve(int groups,int l,int r,int l_possible,int r_possible)
{
    //cout<<"solve "<<groups<<" "<<l<<" "<<r<<" "<<l_possible<<" "<<r_possible<<endl;
    if(l>r)return;
    r_possible=min(r_possible,r);
    if(l_possible==r_possible)
    {
        for(int j=l;j<=r;j++)
            dp[j][groups]=dp[l_possible-1][groups-1]+cost(l_possible,j);
        return;
    }
    if(l==r)
    {
    brute_force(groups,l,l_possible,r_possible);
    return;
    }
    int av=(l+r)/2;
    int where=brute_force(groups,av,l_possible,r_possible);
    solve(groups,l,av-1,l_possible,where);
    solve(groups,av+1,r,where,r_possible);
}
int main()
{
scanf("%i%i",&n,&k);
for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++)
    {
    char c=getchar();
    if('0'<=c&&c<='9')
        inp[i][j]=c-'0';
    else j--;
    }
for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++)
    sums[i][j]=sums[i-1][j]+sums[i][j-1]-sums[i-1][j-1]+inp[i][j];
dp[0][0]=0;
for(int j=1;j<=n;j++)
    dp[j][0]=1e9;

for(int i=1;i<=k;i++)
    {
    solve(i,1,n,1,n);
    //cout<<"i= "<<i<<endl;
    //for(int j=1;j<=n;j++)cout<<j<<" -> "<<dp[j][i]<<" , ";cout<<endl;
    }
printf("%i\n",dp[n][k]/2);
return 0;
}