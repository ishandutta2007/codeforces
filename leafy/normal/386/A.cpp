#include<bits/stdc++.h>  
using namespace std;
int n;
int a[10005];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    int mx1,mx2,p1,p2;
    if(a[1]>=a[2]) mx1=a[1],p1=1,mx2=a[2],p2=2;
    else mx2=a[1],p2=1,mx1=a[2],p1=2;
    for(int i=3;i<=n;i++)
        if(a[i]>mx1) mx1=a[i],p1=i;
    sort(a+1,a+n+1);
    printf("%d %d",p1,a[n-1]);
    return 0;
}