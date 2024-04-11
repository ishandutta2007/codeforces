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
 
int a[100005];
int c[100005];
int e[100005][2];
int i,j,k,l,m,n;

int main()
{
    scanf("%d",&n);
    for(i=1;i<=n-1;i++)scanf("%d%d",&e[i][0],&e[i][1]);
    for(i=1;i<=n;i++)scanf("%d",&c[i]);
    for(i=1;i<=n-1;i++)
    {
        int x=e[i][0],y=e[i][1];
        if(c[x]!=c[y]){a[x]++;a[y]++;}
    }
    m=k=j=0;
    for(i=1;i<=n;i++)
    {
        if(a[i]>1){m++;k=i;continue;}
        if(a[i]==1)j++;
    }
    if(m>1 || (m==1 && a[k]!=j)){printf("NO");return 0;}
    if(m==0 && j>2){printf("NO");return 0;}
    printf("YES\n");
    if(k>0 && a[k]==j){printf("%d",k);return 0;}
    for(i=1;i<=n;i++)if(a[i]>0)break;
    if(i>n)i=1;
    printf("%d",i);
    return 0;
}