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
struct node
{
    LL pos,cost;
    bool operator < (const struct node p)const
    {return cost>p.cost;}
};
priority_queue<node> q;
LL a[maxn],w[maxn],res[maxn],now;
LL ans=0;
int n;

int main()
{
    scanf("%d%lld",&n,&now);
    for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
    for(int i=1;i<=n;i++)scanf("%lld",&w[i]);
    for(int i=1;i<=n;i++)
    {
        if(a[i]%100==0){res[i]=0;continue;}
        LL t=a[i]%100;
        now-=t;
        struct node temp={i,(LL)(100-t)*w[i]};
        q.push(temp);
        if(now<0)
        {
            struct node k=q.top();q.pop();
            now+=100;
            ans+=(LL)k.cost;
            res[k.pos]=1;
        }
    }
    printf("%lld\n",ans);
    for(int i=1;i<=n;i++)
        if(res[i])printf("%lld %lld\n",a[i]/100+1,0);
        else printf("%lld %lld\n",a[i]/100,a[i]%100);
    return 0;
}