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

char s1[100005],s2[100005];
int a[100005],b[100005];
int i,j,k,l,n,m,r;

bool judge(int x)
{
    for(i=1;i<=m-x+1;i++)
        if(a[i-1]<b[i+x])return true;
    return false;
}

int main()
{
    gets(s1+1);
    gets(s2+1);
    n=strlen(s1+1);
    m=strlen(s2+1);
    for(i=k=1;i<=m;i++)
    {
        while(k<=n && s2[i]!=s1[k])k++;
        a[i]=k;k++;
    }
    k=n;
    for(i=m;i>=1;i--)
    {
        while(k>=0 && s2[i]!=s1[k])k--;
        b[i]=k;k--;
    }
    a[0]=0;b[m+1]=n+1;
    if(a[1]>n && b[m]<1){printf("-");return 0;}
    if(a[m]<=n)
    {
        printf("%s",s2+1);
        return 0;
    }
    int l=0,r=m;
    while(r-l>1)
    {
        int mid=(l+r)>>1;
        if(judge(mid))r=mid;else l=mid;
    }
    if(!judge(r))r--;
    for(i=1;i<=m-r+1;i++)
        if(a[i-1]<b[i+r]){j=i;break;}
    for(i=1;i<=j-1;i++)printf("%c",s2[i]);
    for(i=j+r;i<=m;i++)printf("%c",s2[i]);
    return 0;
}