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

int i,j,k,l,r,m,n,ans,tot;
int a[200005],b[200005];

int main()
{
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        if(a[i]<0)j++;
    }
    if(j>m){printf("-1");return 0;}
    m-=j;
    l=r=0;
    for(i=1;i<=n;i++)
        if(a[i]>=0)l++;else break;
    for(i=n;i>=max(l,1);i--)
        if(a[i]>=0)r++;else break;
    if(l+r>=n){printf("0");return 0;}
    for(i=l+1,j=k=0;i<=n-r;i++)
    {
        if(a[i]>=0 && j<=0){j=i;continue;}
        if(a[i]<0 && j>0)
        {
            b[++k]=i-j;
            j=0;
        }
    }
    for(j=0,i=1;i<=n;i++)
    {
        if(j==0 && a[i]<0){ans++;j=1;}
        if(j==1 && a[i]>=0){ans++;j=0;}
    }
    sort(b+1,b+k+1);
    for(i=1;i<=k;i++)
    {
        if(m<b[i])break;
        m-=b[i];ans-=2;
    }
    if(m>=r && r>0){m-=r;ans--;}
    printf("%d",ans);
    return 0;
}