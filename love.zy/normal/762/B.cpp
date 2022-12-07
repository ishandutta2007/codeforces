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

struct mouse
{
    LL val;
    char s[10];
    bool operator < (const struct mouse p)const
    {return val<p.val;}
}m[300005];
LL a,b,c;
int n,i,j,k;
LL ans;

int main()
{
    scanf("%lld%lld%lld",&a,&b,&c);
    scanf("%d",&n);k=ans=0;
    for(i=1;i<=n;i++)
    {
        scanf("%lld %s",&m[i].val,m[i].s);
    }
    sort(m+1,m+n+1);
    for(i=1;i<=n;i++)
    {
        if(m[i].s[0]=='U' && a>0)
        {
            a--;k++;
            ans+=m[i].val;
            continue;
        }
        if(m[i].s[0]=='U' && c>0)
        {
            c--;k++;
            ans+=m[i].val;
            continue;
        }
        if(m[i].s[0]=='P' && b>0)
        {
            b--;k++;
            ans+=m[i].val;
            continue;
        }
        if(m[i].s[0]=='P' && c>0)
        {
            c--;k++;
            ans+=m[i].val;
            continue;
        }
    }
    printf("%d %lld",k,ans);
    return 0;
}