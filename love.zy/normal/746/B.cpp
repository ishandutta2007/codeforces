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
  
char s[2005];
char ans[2005];
int n,i,l,r;

int main()
{
    scanf("%d\n",&n);
    gets(s+1);
    if(n%2==1)
    {
        ans[(n+1)/2]=s[1];
        l=(n+1)/2-1;r=(n+1)/2+1;
        i=2;
    }else
    {
        l=n/2;r=n/2+1;i=1;
    }
    while(i<=n)
    {
        ans[l--]=s[i++];
        ans[r++]=s[i++];
    }
    for(i=1;i<=n;i++)printf("%c",ans[i]);
    return 0;
}