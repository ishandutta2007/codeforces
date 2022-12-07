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

struct node
{
    int u,d,l,r;
    bool operator < (const struct node p)const
    {return l<p.l || (l==p.l && r<p.r);}
}a[500005];
int i,j,k,m,n;

int main()
{
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        int x1,x2,y1,y2;
        scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
        a[i].u=max(y1,y2);
        a[i].d=min(y1,y2);
        a[i].l=min(x1,x2);
        a[i].r=max(x1,x2);
    }
    printf("YES\n");
    for(i=1;i<=n;i++)
        printf("%d\n",2*(abs(a[i].u)%2)+abs(a[i].l)%2+1);
    return 0;
}