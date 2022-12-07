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

const int maxn=100005;

LL ma;
int i,j,k,m,n;
LL l,r;
struct node
{
    LL num;
    int pos;
    bool operator < (const struct node p)const
    {return num<p.num;}
}c[maxn];
LL a[maxn],b[maxn];

int main()
{
    scanf("%d%lld%lld",&n,&l,&r);
    for(i=1;i<=n;i++)scanf("%lld",&a[i]);
    for(i=1;i<=n;i++)
    {
        scanf("%lld",&c[i].num);
        c[i].pos=i;
    }
    sort(c+1,c+n+1);
    ma=-2e9-1;j=0;
    for(i=1;i<=n;i++)
    {
        k=c[i].pos;
        ma++;
        b[k]=a[k]+ma;
        if(b[k]>r){j=1;break;}
        b[k]=max(b[k],l);
        ma=max(ma,b[k]-a[k]);
    }
    if(j>0){printf("-1");return 0;}
    for(i=1;i<=n;i++)
    {
        if(i>1)printf(" ");
        printf("%lld",b[i]);
    }
    return 0;
}