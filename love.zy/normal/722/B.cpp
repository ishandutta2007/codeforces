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

int i,j,k,l,m,n,e;
char s[105];
int a[105];

int main()
{
    scanf("%d",&n);
    for(i=1;i<=n;i++)scanf("%d",&a[i]);
    scanf("\n");
    for(i=1;i<=n;i++)
    {
        gets(s);
        m=strlen(s);
        k=0;l=0;e=-1;
        for(j=0;j<m;j++)
        {
            if(s[j]=='a' || s[j]=='e' || s[j]=='i' || s[j]=='o' || s[j]=='u' || s[j]=='y'){k++;continue;}
            /*if(s[j]==' ')
            {
                if(j-e>1)k+=l;
                l=0;e=j;
            }*/
        }
        //if(m-1-e>1)k+=l;
        if(k!=a[i]){printf("NO");return 0;}
    }
    printf("YES");
    return 0;
}