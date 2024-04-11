#include <bits/stdc++.h>
using namespace std;
int a[100010];
void Y(bool x)
{
    printf("%s",x?"YES":"NO");
}
main()
{
    int n,i,len;
    cin>>n;
    for(i=0;i<n;i++) cin>>a[i];
    sort(a,a+n);
    len=unique(a,a+n)-a;
    if(len<3) Y(1); else if (len==3) Y(a[2]+a[0]==2*a[1]); else Y(0);
}