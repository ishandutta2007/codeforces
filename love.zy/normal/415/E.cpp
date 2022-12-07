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
  
const int maxn=1200005;

map<int,int> mp;
LL g[25][2];//01
int inv[25];
int a[maxn],temp[maxn];
LL i,j,n,m,q,ans;

void solve(LL x,LL y)
{
    if(x==y)return;
    LL mid=(x+y)>>1;
    solve(x,mid);solve(mid+1,y);
    LL l=x,r=mid+1;
    LL i=x,now=mp[y-x+1];
    while(l<=mid && r<=y)
    {
        if(a[l]>a[r])
        {
            temp[i++]=a[r++];
            g[now][0]+=mid-l+1;
            continue;
        }
        temp[i++]=a[l++];
    }
    l=x,r=mid+1,i=x;
    while(l<=mid && r<=y)
    {
        if(a[l]<a[r])
        {
            temp[i++]=a[l++];
            g[now][1]+=y-r+1;
            continue;
        }
        temp[i++]=a[r++];
    }
    while(l<=mid)temp[i++]=a[l++];
    while(r<=y)temp[i++]=a[r++];
    for(LL i=x;i<=y;i++)a[i]=temp[i];
}

int main()
{
    mp[1]=0;for(i=1;i<=20;i++)mp[1<<i]=i;
    scanf("%lld",&n);
    for(i=1;i<=(1<<n);i++)scanf("%d",&a[i]);
    solve(1,1<<n);
    memset(inv,0,sizeof(inv));
    for(i=0;i<=n;i++)ans+=g[i][0];
    scanf("%lld",&m);
    for(i=1;i<=m;i++)
    {
        scanf("%lld",&q);
        for(j=q;j>=0;j--)
        {
            ans=ans-g[j][inv[j]]+g[j][1-inv[j]];
            inv[j]=1-inv[j];
        }
        printf("%lld\n",ans);
    }
    return 0;
}