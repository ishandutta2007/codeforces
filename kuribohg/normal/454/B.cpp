#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
#include<queue>
#include<vector>
using namespace std;
int n,a[100010],t,p;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=2;i<=n;i++) if(a[i]<a[i-1]) t++,p=i;
    if(a[1]<a[n]) t++,p=1;
    if(t>=2) {puts("-1");return 0;}
    if(t==1) printf("%d\n",(n+1-p)%n);
    if(t==0) puts("0");
    return 0;
}