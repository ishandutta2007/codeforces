#include<bits/stdc++.h>
using namespace std;
const int nmax=50+5;
int n,h,m;
struct req
{
    int l,r,x,c;
};
req inp[nmax];

int dp[nmax][nmax][nmax];

int solve(int l,int r,int h)
{
    if(l>r||h==0)return 0;
    if(dp[l][r][h]!=-1)return dp[l][r][h];
    int ret=solve(l,r,h-1);

    for(int current=l;current<=r;current++)//height h
    {
        int tax=0;
        for(int i=1;i<=m;i++)
            if(l<=inp[i].l&&inp[i].l<=current&&current<=inp[i].r&&inp[i].r<=r&&inp[i].x<h)tax=tax+inp[i].c;

        ret=max(ret,solve(l,current-1,h)+h*h-tax+solve(current+1,r,h));
    }

    dp[l][r][h]=ret;
    return ret;
}
int main()
{
    scanf("%i%i%i",&n,&h,&m);
    for(int i=1;i<=m;i++)
        scanf("%i%i%i%i",&inp[i].l,&inp[i].r,&inp[i].x,&inp[i].c);

    memset(dp,-1,sizeof(dp));
    printf("%i\n",solve(1,n,h));

    return 0;
}