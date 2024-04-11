#include<bits/stdc++.h>
using namespace std;
const int nmax=52;
int n;
char inp[nmax][nmax];
int dp[nmax][nmax][nmax][nmax],sums[nmax][nmax];
int area(int x1,int y1,int x2,int y2)
{
    return sums[x2][y2]-sums[x1-1][y2]-sums[x2][y1-1]+sums[x1-1][y1-1];
}
int rec(int x1,int y1,int x2,int y2)
{
    //cout<<"rec "<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<endl;
    if(dp[x1][y1][x2][y2]!=-1)return dp[x1][y1][x2][y2];
    if(area(x1,y1,x2,y2)==0)return 0;

    int ret=max(x2-x1+1,y2-y1+1);

    for(int i=x1;i<x2;i++)
        ret=min(ret,rec(x1,y1,i,y2)+rec(i+1,y1,x2,y2));

    for(int j=y1;j<y2;j++)
        ret=min(ret,rec(x1,y1,x2,j)+rec(x1,j+1,x2,y2));

    dp[x1][y1][x2][y2]=ret;

    //cout<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<" -> "<<ret<<endl;
    return ret;
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        {
            cin>>inp[i][j];
        }

    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            {
                sums[i][j]=sums[i][j-1]+sums[i-1][j]-sums[i-1][j-1]+(inp[i][j]=='#');
                //cout<<i<<" "<<j<<" -> "<<sums[i][j]<<endl;
            }
    memset(dp,-1,sizeof(dp));

    cout<<rec(1,1,n,n)<<endl;

    return 0;
}