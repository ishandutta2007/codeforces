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
  
const int maxn=50005;
char s[maxn];
bool a[30];
int i,j,k,l,m,n,tot;
bool f;

int main()
{
    gets(s);
    n=strlen(s);
    if(n<26){printf("-1");return 0;}
    f=false;
    for(i=0;i<n-25;i++)
    {
        tot=0;
        memset(a,0,sizeof(a));
        for(j=0;j<=25;j++)
        {
            if(s[i+j]=='?'){tot++;continue;}
            if(a[s[i+j]-64])break;
            a[s[i+j]-64]=true;
            tot++;
        }
        if(tot==26)
        {
            f=true;
            k=i;
            break;
        }
    }
    if(!f){printf("-1");return 0;}
    for(i=0;i<=25;i++)
        if(s[k+i]=='?')
        {
            for(j=1;j<=26;j++)
                if(!a[j])
                {
                    s[k+i]=j+64;
                    a[j]=true;
                    break;
                }
        }
    for(i=0;i<n;i++)if(s[i]=='?')s[i]='A';
    printf("%s",s);
    return 0;
}