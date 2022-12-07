#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
double x,y;
int n;
double a[1010],b[1010],v[1010],ans=1e20;
int main()
{
    scanf("%lf%lf",&x,&y);
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%lf%lf%lf",&a[i],&b[i],&v[i]);
        ans=min(ans,sqrt((a[i]-x)*(a[i]-x)+(b[i]-y)*(b[i]-y))/v[i]);
    }
    printf("%.010lf\n",ans);
    return 0;
}