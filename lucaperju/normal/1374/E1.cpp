#include <bits/stdc++.h>
using namespace std;
int a[200005],b[200005],both[200005];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    long long i,j,n,t,m,k;
    cin>>n>>k;
    int n1=0,n2=0,n3=0;
    for(i=1;i<=n;++i)
    {
        int x,y,z;
        cin>>x>>y>>z;
        if(y+z==2)
            both[++n3]=x;
        else if(y==1)
            a[++n1]=x;
        else if(z==1)
            b[++n2]=x;
    }
    sort(a+1,a+n1+1);
    sort(b+1,b+n2+1);
    sort(both+1,both+n3+1);
    for(i=1;i<=n1;++i)
        a[i]+=a[i-1];
    for(i=1;i<=n2;++i)
        b[i]+=b[i-1];
    long long mn=999999999999999LL;
    long long sc=0;
    if(n1>=k && n2>=k)
        mn=a[k]+b[k];
    for(i=1;i<=n3;++i)
    {
        sc+=both[i];
        if(n1>=k-i && n2>=k-i)
            mn=min(mn,sc+a[k-i]+b[k-i]);
    }
    if(mn==999999999999999LL)
        cout<<-1<<'\n';
    else
    cout<<mn<<'\n';
    return 0;
}