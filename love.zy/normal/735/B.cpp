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
  
double a[100005];
double x,y;
int n1,n2;
int n,i;

int main()
{
    scanf("%d %d %d",&n,&n1,&n2);
    if(n1>n2)
    {
        int t=n1;n1=n2;n2=t;
    }
    for(i=1;i<=n;i++)scanf("%lf",&a[i]);
    sort(a+1,a+n+1);
    double sum1=0,sum2=0,ans=0;
    for(i=n;i>=n-n1+1;i--)sum1+=a[i];
    ans+=sum1/(double)(n1);
    n-=n1;
    for(i=n;i>=n-n2+1;i--)sum2+=a[i];
    ans+=sum2/(double)(n2);
    printf("%.8lf",ans);
    return 0;
}