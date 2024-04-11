//Author:mxh1999
//
#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;

#define maxn 100005

typedef long long ll;
int X,Y,k,n,m=1;
double ans;

struct Point{int x,n;} num[maxn];
bool cmp(const Point &x,const Point &y){return x.x<y.x;}

inline double dis(int i)
{
    return sqrt((ll)(X-num[i].x)*(X-num[i].x)+(ll)Y*Y);
}
inline double calchzh(int l,int r)
{
    return min(dis(r),dis(l))+num[r].x-num[l].x;
}
inline double calchzw(int t,int l,int r)
{
    return min(dis(r)+num[r].x-num[l].x+num[t].x-num[l].x,dis(l)+num[r].x-num[l].x+num[r].x-num[t].x);
}

int main()
{
    scanf("%d%d",&n,&k);
    for (int i=1;i<=n;i++)
    {
        scanf("%d",&num[i].x);
        num[i].n=i;
    }
    sort(num+1,num+n+1,cmp);
    scanf("%d%d",&X,&Y);
    if (k==n+1) {printf("%.10lf\n",calchzh(1,n));return 0;}
    for (m=1;m<=n;m++)
    if (num[m].n==k) break;
    k=m;
    double ans=min(dis(k)+calchzh(1,n),calchzw(k,1,n));
    for (int i=k;i<n;i++)   ans=min(ans,calchzh(i+1,n)+calchzw(k,1,i));
    for (int i=2;i<=k;i++)  ans=min(ans,calchzh(1,i-1)+calchzw(k,i,n));
    printf("%.10lf\n",ans);
    return 0;
}