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
  
int a[1005];
vector<int> g[1005];
int gov[1005];
int f[1005],tot[1005],cal[1005];
int i,j,k,l,m,n;
int num,ans;

int find(int t)
{
    if(f[t]==t)return t;
    else return f[t]=find(f[t]);
}

int main()
{
    scanf("%d%d%d",&n,&m,&k);
    for(i=1;i<=n;i++)f[i]=i,tot[i]=1;
    for(i=1;i<=k;i++)scanf("%d",&gov[i]);
    for(i=1;i<=m;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        int xx=find(x),yy=find(y);
        if(xx==yy)continue;
        tot[xx]+=tot[yy];f[yy]=f[xx];
    }
    num=0;
    for(i=1;i<=k;i++)
    {
        cal[i]=tot[find(gov[i])];
        num+=cal[i];
    }
    sort(cal+1,cal+k+1);
    cal[k]+=n-num;
    for(i=1;i<=k;i++)
    {
        ans+=cal[i]*(cal[i]-1)/2;
    }
    printf("%d",ans-m);
    return 0;
}