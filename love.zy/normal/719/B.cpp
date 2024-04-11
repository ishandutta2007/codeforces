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
  
char a[100005],b[100005];
int i,n,m1,m2,p,q;

int main()
{
    scanf("%d\n",&n);
    gets(a+1);m1=m2=0;
    p=q=0;
    for(i=1;i<=n;i++)if(i%2==0)b[i]='b';else b[i]='r';
    for(i=1;i<=n;i++)
        if(a[i]!=b[i])
        {
            if(a[i]=='b')p++;else q++;
        }
    m1=max(p,q);
    p=q=0;
    for(i=1;i<=n;i++)if(i%2==1)b[i]='b';else b[i]='r';
    for(i=1;i<=n;i++)
        if(a[i]!=b[i])
        {
            if(a[i]=='b')p++;else q++;
        }
    m2=max(p,q);
    printf("%d",min(m1,m2));
    return 0;
}