#include <iostream>
#include <cstring>
#include <stack>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <queue>
#include <cstdio>
#include <cstdlib>
#include <climits>
#include <deque>
#include <bitset>
#include <algorithm>
  
using namespace std;
  
const double eps=1e-10;
const double pi=3.1415926535897932384626433832795;
const double eln=2.718281828459045235360287471352;
  
#define LL long long
#define IN freopen("in.txt", "r", stdin)
#define OUT freopen("out.txt", "w", stdout)
#define scan(x) scanf("%d", &x)
#define scan2(x, y) scanf("%d%d", &x, &y)
#define scan3(x, y, z) scanf("%d%d%d", &x, &y, &z)
#define sqr(x) (x) * (x)
#define pr(x) printf("Case %d: ",x)
#define prn(x) printf("Case %d:\n",x)
#define prr(x) printf("Case #%d: ",x)
#define prrn(x) printf("Case #%d:\n",x)
#define lowbit(x) (x&(-x))

int a[4005][4005];
int sum[4005][4005];
int dp[4005][805];
int i,j,k,l,m,n;

int cal(int x,int y)
{
    x--;
    int temp=sum[y][y]-sum[x][y]+sum[x][x]-sum[y][x];
    return temp/2;
}

void solve(int hl,int hr,int ll,int lr)
{
    if(hl>hr)return;
    int mid=(hl+hr)>>1;
    dp[mid][k]=2e9+7;
    int ju;
    for(int u=ll;u<=min(lr,mid-1);u++)
    {
        int now=dp[u][k-1]+cal(u+1,mid);
        if(now<dp[mid][k])
        {
            dp[mid][k]=now;
            ju=u;
        }
    }
    if(hl<mid)solve(hl,mid-1,ll,ju);
    if(hr>mid)solve(mid+1,hr,ju,lr);
}

inline void read(int &x) {
    char ch=getchar();
    while(ch<'0'||ch>'9') ch=getchar();
    x=0;
    while(ch<='9'&&ch>='0'){
        x=x*10+ch-'0';
        ch=getchar();
    }
}

int main()
{
    read(n);read(m);
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)read(a[i][j]);
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)sum[i][j]=sum[i][j-1]+a[i][j];
    for(j=1;j<=n;j++)
        for(i=1;i<=n;i++)sum[i][j]+=sum[i-1][j];
    for(i=1;i<=n;i++)dp[i][1]=cal(1,i);
    for(k=2;k<=m;k++)solve(k,n,k-1,n-1);
    printf("%d",dp[n][m]);
    return 0;
}