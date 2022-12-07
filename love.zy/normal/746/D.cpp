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
  
int n,k,p,q;
int a[100005],b[100005];
int i,j,l,m;
char ca,cb;

int main()
{
    scanf("%d%d%d%d",&n,&m,&p,&q);
    if(p>q){ca='G';cb='B';}else {k=p;p=q;q=k;ca='B';cb='G';}
    l=j=0;i=1;
    while(l<p)
    {
        j++;
        if(j==m+1){a[i++]=0;q--;j=0;}else {a[i++]=1;l++;}
    }
    if(q<0){printf("NO");return 0;}
    l=i-1;i=1;
    while(q>0 && i<=l)
    {
        if(a[i]==1 && a[i+1]==1)
        {
            b[i]=1;i++;q--;
        }else i++;
    }
    if(q>0)while(q--)b[i++]=1;
    int tt=i-1,t=i-1;i=0;
    while(b[t]==1){t--;i++;}
    t=tt;
    if(i>m){printf("NO");return 0;}
    for(i=1;i<=max(t,l);i++)
    {
        if(i<=l)
        {
            if(a[i]==1)printf("%c",ca);
            else printf("%c",cb);
        }
        if(b[i]==1)printf("%c",cb);
    }
    return 0;
}