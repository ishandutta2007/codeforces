#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[105];
int main()
{
    scanf("%d%d",&n,&m);
    scanf("%d",&a[1]);
    int mx=a[1];
    for(int i=2;i<=n;i++) scanf("%d",&a[i]),mx=max(mx,a[i]);
    int mxk=mx+m,s=0;
    for(int i=1;i<=n;i++) s+=mx-a[i];
    m-=s;
    if(m<=0) printf("%d %d",mx,mxk);
    else printf("%d %d",mx+(m-1)/n+1,mxk);
    return 0;
}