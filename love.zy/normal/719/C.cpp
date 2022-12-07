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
  
char s[200005];
int i,j,k,l,m,n,t;

int main()
{
    scanf("%d %d\n",&n,&t);
    gets(s+1);
    for(i=1;i<=n;i++)if(s[i]=='.'){m=i;break;}
    l=0;s[0]='0';
    for(i=m+1;i<=n;i++)if(s[i]>='5'){l=i;break;}
    while(t-- && l>0)
    {
        s[l]='0';
        n=l;
        j=l;
        while(j>=0)
        {
            j--;
            if(s[j]=='.')j--;
            s[j]++;
            if(s[j]<=57)
            {
                if(s[j]>='5' || j<=m)l=j;
                break;
            }else s[j]='0';
        }
        if(l<=m || s[l]<'5')l=0;
    }
    while((s[n]=='0' || s[n]=='.') && n>=m)n--;
    if(s[0]!='0')i=0;else i=1;
    for(;i<=n;i++)printf("%c",s[i]);
    return 0;
}