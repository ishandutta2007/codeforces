#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
#include<queue>
#include<vector>
using namespace std;
int n;
double f[1000010],p[1000010],a[1000010];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%lf",&a[i]);
    for(int i=1;i<=n;i++) p[i]=a[i]*(p[i-1]+1.0),f[i]=a[i]*(f[i-1]+2.0*p[i-1]+1.0)+(1.0-a[i])*f[i-1];
    printf("%.010lf\n",f[n]);
    return 0;
}