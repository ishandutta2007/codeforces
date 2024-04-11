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
  
map<int,int> mp;
int i,j,k,l,m,n;
int a[200005];
int x,y,ans;//x-,y-
int ne,b;
int u[2];

void out(int t)
{
    printf("%d\n",t);
    for(i=1;i<=n;i++)
    {
        if(i>1)printf(" ");
        printf("%d",a[i]);
    };
}

bool judge()
{
    for(int i=1;i<=n;i++)if(mp[a[i]]>1)return false;
    return ne<=0;
}

int main()
{
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        (a[i]%2==0)?x++:y++;
        mp[a[i]]++;
    }
    ne=abs(x-n/2);
    i=0;b=x>y?1:0;
    u[0]=2;u[1]=1;
    if(judge()){out(0);return 0;}
    while(u[b]<=m && ne>0 && i<n)
    {
        i++;
        if(a[i]%2==b || mp[a[i]]<=1)continue;
        while(mp[u[b]]>=1 && u[b]<=m)u[b]+=2;
        if(u[b]>m)break;
        mp[a[i]]--;a[i]=u[b];ne--;ans++;mp[u[b]]++;
    }
    if(judge()){out(ans);return 0;}
    if(u[b]>m){printf("-1");return 0;}
    i=0;
    while(u[b]<=m && ne>0 && i<n)
    {
        i++;
        if(a[i]%2==b)continue;
        while(mp[u[b]]>=1 && u[b]<=m)u[b]+=2;
        if(u[b]>m)break;
        mp[a[i]]--;a[i]=u[b];ne--;ans++;mp[u[b]]++;
    }
    if(judge()){out(ans);return 0;}
    if(u[b]>m || ne>0){printf("-1");return 0;}
    
    for(i=1;i<=n;i++)
    {
        if(mp[a[i]]==1)continue;
        j=a[i]%2;
        while(mp[u[j]]>=1 && u[j]<=m)u[j]+=2;
        if(u[j]>m){printf("-1");return 0;}
        mp[a[i]]--;a[i]=u[j];mp[u[j]]++;ans++;
    }
    out(ans);
    return 0;
}