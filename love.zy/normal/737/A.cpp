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

const int maxn=200005;
int i,j,m,n,s;
LL t;
struct car
{
    int cost,v;
}c[maxn];
int kk[maxn];

bool check(LL x)
{
    LL tot=0;
    for(int i=1;i<=m;i++)
    {
        LL t1=kk[i]-kk[i-1];
        if(2*t1<=x){tot+=t1;continue;}
        if(t1>x)return false;
        tot+=(x-t1)+2*(2*t1-x);
    }
    return tot<=t;
}

int find()
{
    LL l=1,r=1e9+1;
    while(r-l>1)
    {
        int mid=(l+r)>>1;
        if(check(mid))r=mid;else l=mid;
    }
    if(!check(l))l++;
    return l;
}

int main()
{
    scanf("%d%d%d%lld",&n,&m,&s,&t);
    for(i=1;i<=n;i++)scan2(c[i].cost,c[i].v);
    for(i=1;i<=m;i++)scanf("%d",&kk[i]);
    sort(kk+1,kk+m+1);
    kk[0]=0;kk[++m]=s;
    int d=find();
    int ans=1e9+7;
    //check(6);
    for(i=1;i<=n;i++)if(c[i].v>=d)ans=min(ans,c[i].cost);
    if(ans<1e9+7)printf("%d",ans);else printf("-1");
    return 0;
}