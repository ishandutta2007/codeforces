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

int a[2][15];
int b[30];
bool x[27];
int p,q;
int i,j,k,l,m,n;

int main()
{
    memset(x,0,sizeof(x));
    for(i=1;i<=27;i++)
    {
        char c=getchar();
        b[i]=c-64;
        if(x[c-64])n=c-64,q=i;
        x[c-64]=true;
    }
    for(i=1;i<=27;i++)
        if(n==b[i]){p=i;break;}
    if(q-p<=1){printf("Impossible");return 0;}
    m=q-p-1;
    m/=2;m++;l=p;
    a[0][13-m+1]=n;
    for(i=13-m+2;i<=13;i++)a[0][i]=b[++l];
    for(i=13;l<q-1;i--)a[1][i]=b[++l];
    i=0;j=13-m;k=-1;
    if(j<=0){k=1;i=1;j=1;}
    for(l=q+1;l<=27;l++)
    {
        a[i][j]=b[l];
        j+=k;
        if(j<=0){k=1;i=1;j=1;}
    }
    for(l=1;l<=p-1;l++)
    {
        a[i][j]=b[l];
        j+=k;
        if(j<=0){k=1;i=1;j=1;}
    }
    for(i=0;i<=1;i++)
    {
        for(j=1;j<=13;j++)printf("%c",a[i][j]+64);
        printf("\n");
    }
    return 0;
}