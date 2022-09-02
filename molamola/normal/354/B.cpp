#include<stdio.h>
#include<algorithm>
using namespace std;

int dp[44][1<<20];
int a[44][26],n;
char ch[22][22];
bool chk[44][1<<20];

int solve(int x,int t)
{
    if(x==2*n-1)return 0;
    if(chk[x][t])return dp[x][t];
    int i,ret=(x&1)?1e9:-1e9;
    int s=1;
    if(t)s=t|(t<<1);
    for(i=0;i<26;i++){
        int r = a[x][i] & s;
        if(!r)continue;
        if(x&1)ret=min(ret,(i!=0?i!=1?0:-1:1)+solve(x+1,r));
        else ret=max(ret,(i!=0?i!=1?0:-1:1)+solve(x+1,r));
    }
    chk[x][t]=1;
    return dp[x][t]=ret;
}

int main()
{
    int i,j;
    scanf("%d",&n);
    for(i=0;i<n;i++)scanf("%s",ch[i]);
    for(int p=0;p<26;p++){
        for(i=0;i<2*n-1;i++){
            for(j=max(0,i-n+1);j<min(n,i+1);j++)if(ch[i-j][j]==p+'a')a[i][p]|=(1<<j);
        }
    }
    int t = solve(0,0);
    printf("%s",t>=0?t==0?"DRAW":"FIRST":"SECOND");
    return 0;
}