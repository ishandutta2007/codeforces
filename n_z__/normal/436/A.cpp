#include<bits/stdc++.h>
using namespace std;
struct candy{
    int t,h,m;
}a[2001],b[2001];
bool cmp(candy a,candy b)
{
    if(a.h!=b.h)return a.h<b.h;
    return a.m>b.m;
}
int main()
{
    int n,q;
    cin>>n>>q;
    for(int x=1;x<=n;x++)
    cin>>a[x].t>>a[x].h>>a[x].m;
    sort(a+1,a+1+n,cmp);
    for(int x=1;x<=n;x++)
    b[x]=a[x];
    int ans=0,nowm=q;
    int now=0;
    while(true)
    {
        int man=0;
        a[man].m=0;
        for(int x=1;a[x].h<=nowm&&x<=n;x++)
        if(a[x].m>a[man].m&&a[x].t==now)man=x;
        if(man==0)break;
        ans++;
        now=!now;
        nowm+=a[man].m;
        a[man].m=-1;
    }
    int ans2=0;
    nowm=q;
    now=1;
    while(true)
    {
        int man=0;
        b[man].m=0;
        for(int x=1;b[x].h<=nowm&&x<=n;x++)
        if(b[x].m>b[man].m&&b[x].t==now)man=x;
        if(man==0)break;
        ans2++;
        now=!now;
        nowm+=b[man].m;
        b[man].m=-1;
    }
    cout<<max(ans,ans2)<<endl;
}