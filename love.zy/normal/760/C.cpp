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

int g[maxn],a[maxn];
int n,i,j,tot,k;

int main()
{
    scanf("%d",&n);tot=0;
    for(i=1;i<=n;i++)scanf("%d",&g[i]);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&k);
        tot+=k;
    }
    k=0;
    for(i=1;i<=n;i++)
    {
        if(a[i]>0)continue;
        a[i]=++k;
        j=g[i];while(a[j]==0){a[j]=k;j=g[j];}
    }
    if(k==1)k--;
    if(tot%2==0)k++;
    printf("%d",k);
    return 0;
}