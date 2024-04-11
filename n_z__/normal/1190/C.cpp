#include<bits/stdc++.h>
using namespace std;
int a[5];
int main()
{
    int n,k;
    a[1]=a[3]=10000000;
    cin>>n>>k;
    for(int x=1;x<=n;x++)
    {
        char c;
        cin>>c;
        if(c=='0')a[1]=min(a[1],x),a[2]=x;
        else a[3]=min(a[3],x),a[4]=x;
    }
    if(a[1]==1000000)a[1]=0;
    if(a[3]==1000000)a[3]=0;
    if(a[2]-a[1]<k||a[4]-a[3]<k)
    return puts("tokitsukaze"),0;
    sort(a+1,a+5);
    if(a[4]-a[2]>k||a[3]-a[1]>k)puts("once again");
    else puts("quailty");
}