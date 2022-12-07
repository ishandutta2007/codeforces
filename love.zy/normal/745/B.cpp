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

char s[505][505];
int l,r,u,d;
int i,j,n,m;

bool judge()
{
    for(i=u;i<=d;i++)
        for(j=l;j<=r;j++)
            if(s[i][j]=='.')return false;
    return true;
}

int main()
{
    scanf("%d %d\n",&n,&m);
    for(i=1;i<=n;i++)gets(s[i]+1);
    l=m+1,u=n+1;
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
        {
            if(s[i][j]=='.')continue;
            l=min(l,j);r=max(r,j);
            u=min(u,i);d=max(d,i);
        }
    if(judge())printf("YES");else printf("NO");
    return 0;
}