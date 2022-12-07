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

struct course
{
    int now,pos;
    course(int now=0,int pos=0):now(now),pos(pos){};
}cou[maxn];

int a[maxn],b[maxn];
int i,m,n;

bool pd(int x)
{
    int tot=0;
    bool vis[maxn];
    for(int i=1;i<=m;i++)vis[i]=false;
    for(int i=x;i>=1;i--)
    {
        if(b[i]==0 || vis[b[i]])continue;
        cou[++tot]=course(b[i],i);
        vis[b[i]]=true;
    }
    if(tot<m)return false;
    cou[tot+1]=course(0,0);
    int t=0;
    for(int i=tot;i>=1;i--)
    {
        t+=cou[i].pos-cou[i+1].pos-1;
        if(t<a[cou[i].now])return false;
        t-=a[cou[i].now];
    }
    return true;
}

int main()
{
    scan2(n,m);
    for(i=1;i<=n;i++)scan(b[i]);
    for(i=1;i<=m;i++)scan(a[i]);
    if(!pd(n))
    {
        printf("-1");
        return 0;
    }
    int ll=1,rr=n;
    while(rr-ll>1)
    {
        int mid=(ll+rr)>>1;
        if(pd(mid))rr=mid;else ll=mid;
    }
    if(!pd(ll))ll++;
    printf("%d",ll);
    return 0;
}