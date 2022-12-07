#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
const int MAXN=100010;
const long double PI=acos(-1);
int n,ans1,ans2;
long double ans;
struct Point
{
    int x,y,id;
    long double theta;
    friend bool operator<(const Point &p,const Point &q)
    {
        return p.theta<q.theta;
    }
}P[MAXN];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d%d",&P[i].x,&P[i].y),P[i].id=i;
    for(int i=1;i<=n;i++) P[i].theta=atan2(P[i].y,P[i].x);
    sort(P+1,P+n+1);
    P[n+1]=P[1];
    ans=100000000;
    for(int i=1;i<=n;i++)
    {
        long double x=P[i+1].theta-P[i].theta;
        if(i==n) x+=2*PI;
        if(x<=ans) ans=x,ans1=P[i].id,ans2=P[i+1].id;
    }
    printf("%d %d\n",ans1,ans2);
    return 0;
}