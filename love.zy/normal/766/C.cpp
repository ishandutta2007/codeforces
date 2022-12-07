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

const int mod=1e9+7;

int st[1005][11];
int num[27];
int a[1005];
char s[1005];
int i,j,k,n;
int ma;
int dp[1005];
int ds[1005];
int lo[1005];

void mkST()
{
    for(int i=1;i<=n;i++)st[i][0]=a[i];
    for(int j=1;(1<<j)<=n;j++)
        for(int i=1;i<=n-(1<<j)+1;i++)
            st[i][j]=min(st[i][j-1],st[i+(1<<(j-1))][j-1]);
}

int find(int x,int y)
{
    int u=lo[y-x+1];
    return min(st[x][u],st[y-(1<<u)+1][u]);
}

int main()
{
    lo[1]=0;
    for(i=2;i<=1000;i++)lo[i]=lo[i/2]+1;
    scanf("%d\n",&n);
    gets(s+1);
    for(i=1;i<=26;i++)scanf("%d",&num[i]);
    for(i=1;i<=n;i++)a[i]=num[s[i]-96];
    dp[0]=dp[1]=1;ma=1;ds[1]=1;
    mkST();
    for(i=2;i<=n;i++)
    {
        for(j=i;i>=1;j--)
        {
            if(i-j+1>find(j,i))break;
            dp[i]=(dp[i]+dp[j-1])%mod;
            ds[i]=ds[j-1]+1;
            ma=max(ma,i-j+1);
        }
    }
    printf("%d\n%d\n%d",dp[n],ma,ds[n]);
    return 0;
}