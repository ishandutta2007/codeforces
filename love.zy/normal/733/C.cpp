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
  
int a[505],b[505];
int cz[505][2];
int i,j,k,l,m,n;
int last,now,sum;

bool cl(int x,int y)
{
    if(x==y)return true;
    int js=(x-i);
    int ma=0,p=0;
    for(int i=x;i<=y;i++)if(a[i]>ma)ma=a[i];
    for(int i=x;i<=y;i++)
    {
        if(a[i]<ma)continue;
        if(i>x && a[i]>a[i-1]){p=i;break;}
        if(i<y && a[i]>a[i+1]){p=i;break;}
    }  
    if(p==0)return false;
    int le=p-1,ri=p+1;
    if(le<x && ri>y)return true;
    if(ri<=y && a[p]>a[ri])
    {
        for(int i=p+1;i<=y;i++)
        {
            cz[++sum][0]=p-js;
            cz[sum][1]=1;
        }
        for(int i=p-1;i>=x;i--)
        {
            cz[++sum][0]=p-js;
            cz[sum][1]=0;
            p--;
        }
    }else
    {
        int lll=p;
        for(int i=p-1;i>=x;i--)
        {
            cz[++sum][0]=p-js;
            cz[sum][1]=0;
            p--;
        }
        for(int i=lll+1;i<=y;i++)
        {
            cz[++sum][0]=p-js;
            cz[sum][1]=1;
        }
    }
    return true;
}

int main()
{
    scan(n);
    for(i=1;i<=n;i++)scan(a[i]);
    scan(m);
    for(i=1;i<=m;i++)scan(b[i]);
    last=1;sum=0;
    for(i=1;i<=m;i++)
    {
        int tot=0;
        j=last;
        if(j>n){printf("NO");return 0;}
        while(j<=n && tot<b[i])
        {
            tot+=a[j];
            if(tot==b[i]){now=j+1;break;}
            j++;
        }
        if(tot>b[i]){printf("NO");return 0;}
        bool f=cl(last,j);
        if(!f){printf("NO");return 0;}
        last=now;
    }
    if(now<=n){printf("NO");return 0;}
    printf("YES\n");
    for(i=1;i<=sum;i++)
    {
        printf("%d ",cz[i][0]);
        if(cz[i][1]==0)printf("L\n");
        if(cz[i][1]==1)printf("R\n");
    }
    return 0;
}