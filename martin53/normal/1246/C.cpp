#include<bits/stdc++.h>
using namespace std;
const int nmax=2e3+42,mod=1e9+7;
int n,m;
char inp[nmax][nmax];
int dp[nmax][nmax][2],pref_dp[nmax][nmax][2];
int pref_table[nmax][nmax];

int rocks(int x1,int y1,int x2,int y2)
{
    return pref_table[x2][y2]+pref_table[x1-1][y1-1]-pref_table[x1-1][y2]-pref_table[x2][y1-1];
}

int proper(int num)
{
    if(num>=mod)num=num-mod;
    if(num<0)num=num+mod;
    return num;
}
void update(int x,int y)
{
    pref_dp[x][y][0]=proper(pref_dp[x+1][y][0]+pref_dp[x][y+1][0]);
    pref_dp[x][y][0]=proper(pref_dp[x][y][0]-pref_dp[x+1][y+1][0]);
    pref_dp[x][y][0]=proper(pref_dp[x][y][0]+dp[x][y][0]);


    pref_dp[x][y][1]=proper(pref_dp[x+1][y][1]+pref_dp[x][y+1][1]);
    pref_dp[x][y][1]=proper(pref_dp[x][y][1]-pref_dp[x+1][y+1][1]);
    pref_dp[x][y][1]=proper(pref_dp[x][y][1]+dp[x][y][1]);
}

int pref_sums(int x1,int y1,int x2,int y2,int state)
{
    int ret=proper(pref_dp[x1][y1][state]+pref_dp[x2+1][y2+1][state]);
    ret=proper(ret-pref_dp[x1][y2+1][state]);
    ret=proper(ret-pref_dp[x2+1][y1][state]);
    return ret;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();

    cin>>n>>m;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)cin>>inp[i][j];

    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        pref_table[i][j]=pref_table[i-1][j]+pref_table[i][j-1]-pref_table[i-1][j-1]+(inp[i][j]=='R');

    if(inp[n][m]=='R')
    {
        cout<<0<<endl;
        return 0;
    }

    if(n==1&&m==1)
    {
        cout<<1<<endl;
        return 0;
    }
    dp[n][m][0]=1;
    dp[n][m][1]=1;

    update(n,m);

    for(int x=n;x>=1;x--)
        for(int y=m;y>=1;y--)
        {
        if(x==n&&y==m)continue;

        //type 0 - go down
        int stop_x=rocks(x+1,y,n,y);
        int x_=n-stop_x;
        dp[x][y][0]=pref_sums(x+1,y,x_,y,1);

        //type 1 - go right
        int stop_y=rocks(x,y+1,x,m);
        int y_=m-stop_y;
        dp[x][y][1]=pref_sums(x,y+1,x,y_,0);

        update(x,y);
        }

    cout<<(dp[1][1][0]+dp[1][1][1])%mod<<endl;
    return 0;
}