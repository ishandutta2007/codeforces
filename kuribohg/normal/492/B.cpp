#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
#include<queue>
#include<vector>
using namespace std;
const int MAXN=1000010;
int n,l,a[MAXN];
double ans;
int main()
{
    scanf("%d%d",&n,&l);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    a[n+1]=0,a[n+=2]=l;
    sort(a+1,a+n+1);
    for(int i=1;i<n;i++) ans=max(ans,(double)a[i+1]-a[i]);
    ans/=2.0;
    ans=max(ans,(double)max(a[2],l-a[n-1]));
    printf("%.010lf\n",ans);
    return 0;
}