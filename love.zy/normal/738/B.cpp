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
  
int a[1005][2],b[1005][2];
int s[1005][1005];
int i,j,k,l,m,n;
int ans=0;

int main()
{
    scan2(n,m);
    for(i=1;i<=n;i++)a[i][0]=1005;
    for(i=1;i<=m;i++)b[i][0]=1005;
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
        {
            scan(s[i][j]);
            if(s[i][j]==1)
            {
                a[i][0]=min(j,a[i][0]);
                a[i][1]=max(j,a[i][1]);
                b[j][0]=min(i,b[j][0]);
                b[j][1]=max(i,b[j][1]);
            }
        }
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
        {
            if(s[i][j]>0)continue;
            if(a[i][0]<j)ans++;
            if(a[i][1]>j)ans++;
            if(b[j][0]<i)ans++;
            if(b[j][1]>i)ans++;
        }
    printf("%d",ans);
    return 0;
}