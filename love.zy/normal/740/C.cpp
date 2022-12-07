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
  
struct qj
{
    int l,r;
    bool operator < (const struct qj p)const
    {
        return (r-l<p.r-p.l);
    }
}a[100005];
int b[100005];
int i,j,k,m,n;

int main()
{
    scan2(n,m);
    for(i=1;i<=m;i++)scan2(a[i].l,a[i].r);
    sort(a+1,a+m+1);
    printf("%d\n",k=a[1].r-a[1].l+1);
    for(i=a[1].l;i<=a[1].r;i++)b[i]=i-a[1].l;
    for(i=a[1].l-1;i>=1;i--)b[i]=b[i+k];
    for(i=a[1].r+1;i<=n;i++)b[i]=b[i-k];
    for(i=1;i<=n;i++)
    {
        if(i>1)printf(" ");
        printf("%d",b[i]);
    }
    return 0;
}