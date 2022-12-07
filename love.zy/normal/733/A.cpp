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
  
char s[105];

int i,n,m,ans;
char c;

int main()
{
    n=0;
    while(scanf("%c",&c)==1 && c>='A' && c<='Z')
    {
        s[++n]=c;
    }
    s[0]='A';
    s[++n]='A';
    i=m=0;ans=0;
    while(i<n)
    {
        i++;
        if(s[i]=='A' || s[i]=='E' || s[i]=='O' || s[i]=='U' || s[i]=='Y' || s[i]=='I')
        {
            if(i-m>ans)ans=i-m;
            m=i;
        }
    }
    printf("%d",ans);
    return 0;
}