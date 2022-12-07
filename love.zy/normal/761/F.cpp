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
 
LL sum[1005][1005][27];
LL tot[1005][1005][27];
char s[1005][1005];
struct node
{
    int x1,y1,x2,y2;
    int c;
}a[300005];
int m,n,q;

void add(int x1,int y1,int x2,int y2,int nu)
{
    tot[x1][y1][nu]++;
    tot[x1][y2+1][nu]--;
    tot[x2+1][y1][nu]--;
    tot[x2+1][y2+1][nu]++;
}

void cal_pre_sum(LL t[1005][1005][27])
{
    for(int k=1;k<=26;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                t[i][j][k]+=t[i][j-1][k];
    for(int k=1;k<=26;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                t[i][j][k]+=t[i-1][j][k];

}

LL cal_area_sum(int x1,int y1,int x2,int y2,int nu)
{
    if(x1>x2 || y1>y2)return 0;
    x1--;y1--;
    return sum[x2][y2][nu]+sum[x1][y1][nu]-sum[x1][y2][nu]-sum[x2][y1][nu];
}

LL cal_area_tot(int x1,int y1,int x2,int y2,int nu)
{
    if(x1>x2 || y1>y2)return 0;
    x1--;y1--;
    return tot[x2][y2][nu]+tot[x1][y1][nu]-tot[x1][y2][nu]-tot[x2][y1][nu];
}

LL cal_others(int x1,int y1,int x2,int y2)
{
    LL u=0;
    u+=cal_area_sum(1,1,n,y1-1,0);
    u+=cal_area_sum(1,y2+1,n,m,0);
    u+=cal_area_sum(1,y1,x1-1,y2,0);
    u+=cal_area_sum(x2+1,y1,n,y2,0);
    return u;
}

int main()
{
    scanf("%d%d%d\n",&n,&m,&q);
    for(int i=1;i<=n;i++)gets(s[i]+1);
    for(int i=1;i<=q;i++)
    {
        char cc;
        scanf("%d %d %d %d %c",&a[i].x1,&a[i].y1,&a[i].x2,&a[i].y2,&cc);
        a[i].c=cc-96;
        add(a[i].x1,a[i].y1,a[i].x2,a[i].y2,a[i].c);
    }
    cal_pre_sum(tot);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            for(int k=1;k<=26;k++)
                sum[i][j][k]=((LL)abs(s[i][j]-96-k))*tot[i][j][k];
    cal_pre_sum(sum);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            for(int k=1;k<=26;k++)
            {
                sum[i][j][0]+=sum[i][j][k];
                tot[i][j][0]+=tot[i][j][k];
            }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            tot[i][j][s[i][j]-96]+=q-tot[i][j][0];
    cal_pre_sum(tot);
    LL daan=1e18;
    for(int i=1;i<=q;i++)
    {
        LL ans=0;
        ans+=cal_others(a[i].x1,a[i].y1,a[i].x2,a[i].y2);
        for(int j=1;j<=26;j++)ans+=((LL)abs(a[i].c-j))*cal_area_tot(a[i].x1,a[i].y1,a[i].x2,a[i].y2,j);
        daan=min(daan,ans);
    }
    printf("%lld",daan);
    return 0;
}