#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;
int n,a[100010],b[100010],c[100010],s,t;
bool sorted=true;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=1;i<=n;i++) c[i]=a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++) b[i]=lower_bound(a+1,a+n+1,c[i])-a;
    for(int i=1;i<=n;i++) if(b[i]!=i) sorted=false;
    if(sorted) {puts("yes");puts("1 1");return 0;}
    for(int i=1;i<=n;i++)
        if(b[i]!=b[i-1]+1) {s=i;break;}
    for(int i=s+1;i<=n;i++)
        if(b[i]!=b[i-1]-1) {t=i-1;break;}
    if(t==0) t=n;
    reverse(b+s,b+t+1);
    for(int i=1;i<=n;i++)
        if(b[i]!=i) {puts("no");return 0;}
    puts("yes");
    printf("%d %d\n",s,t);
    return 0;
}