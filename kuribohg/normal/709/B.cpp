#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=1000010;
int n,x,a[MAXN],ans=1000000000;
int main()
{
    scanf("%d%d",&n,&x);
    if(n==1) {puts("0");return 0;}
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    ++n,a[n]=x;
    sort(a+1,a+n+1);
    int pos=0;
    for(int i=1;i<=n;i++) if(a[i]==x) pos=i;
    for(int i=1;i<pos;i++)
    {
        int x=pos-i,l=i,r=pos+n-2-x;
        if(x>=n-2) ans=min(ans,a[pos]-a[l]);
        else if(r<=n) ans=min(ans,a[pos]-a[l]+a[r]-a[l]);
    }
    for(int i=pos+1;i<=n;i++)
    {
        int x=i-pos,r=i,l=pos-(n-2-x);
        if(x>=n-2) ans=min(ans,a[r]-a[pos]);
        else if(l>=1) ans=min(ans,a[r]-a[pos]+a[r]-a[l]);
    }
    printf("%d\n",ans);
    return 0;
}