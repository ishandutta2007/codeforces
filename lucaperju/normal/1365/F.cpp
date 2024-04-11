#include <bits/stdc++.h>

using namespace std;
int a[503],b[503];
struct ura
{
    int a,b;
}va[503],vb[503];
bool cmp (ura a, ura b)
{
    if(a.a<b.a)
        return true;
    if(a.a>b.a)
        return false;
    return a.b<b.b;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    long long m,n,k,t,i,j,p,mxx=0,s,q,nr1=0,nr2=0,nr3=0;
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(i=1;i<=n;++i)
            cin>>a[i];
        for(i=1;i<=n;++i)
            cin>>b[i];
        if(n%2)
        {
            if(a[n/2+1]!=b[n/2+1])
            {
                cout<<"no\n";
                continue;
            }
        }
        for(i=1;i<=n/2;++i)
            va[i]={min(a[i],a[n-i+1]),max(a[i],a[n-i+1])};
        for(i=1;i<=n/2;++i)
            vb[i]={min(b[i],b[n-i+1]),max(b[i],b[n-i+1])};
        sort(va+1,va+n/2+1,cmp);
        sort(vb+1,vb+n/2+1,cmp);
        for(i=1;i<=n/2;++i)
        {
            if(va[i].a!=vb[i].a || va[i].b!=vb[i].b)
                break;
        }
        if(i==n/2+1)
            cout<<"Yes\n";
        else
            cout<<"no\n";
    }
    return 0;
}