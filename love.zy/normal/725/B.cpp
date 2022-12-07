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

char s[50];

LL n,ans,i;

int main()
{
    gets(s);
    n=0;
    for(i=0;i<strlen(s);i++)
        if(s[i]<='9')n=n*10+s[i]-48;
    i=(n-1)/4;
    ans=i*16;
    n=n-4*i;
    if(n%2==0)ans+=7;
    n=strlen(s);
    n=s[n-1]-96;
    if(n>=4)ans+=7-n;else ans+=3+n;
    printf("%lld\n",ans);
    return 0;
}