#include <bits/stdc++.h>
using namespace std;
int v[200005],n,p;
bool check1 (long long x)
{
    int st=1;
    int i;
    int dr=0;
    for(i=1;i<=n;++i)
        if(v[i]<=x)
            dr=i;
    while(st<=n)
    {
        if(st>dr)
            return false;
        ++st;
        ++x;
        while(dr<n && v[dr+1]<=x)
            ++dr;
    }
    return true;
}
bool check2 (long long x)
{
    int st=1;
    int i;
    int dr=0;
    for(i=1;i<=n;++i)
        if(v[i]<=x)
            dr=i;
    while(st<=n)
    {
        if(dr-st+1>=p)
            return true;
        ++st;
        ++x;
        while(dr<n && v[dr+1]<=x)
            ++dr;
    }
    return false;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    long long i,j,t,m,k=0,a,b;
    long long pas=1LL<<40;
    cin>>n>>p;
    for(i=1;i<=n;++i)
        cin>>v[i];
    sort(v+1,v+n+1);
    while(pas)
    {
        if(!check1(k+pas))
            k+=pas;
        pas>>=1LL;
    }
    long long k1=k;
    pas=1LL<<40;
    while(pas)
    {
        if(!check2(k1+pas))
            k1+=pas;
        pas>>=1LL;
    }
    cout<<k1-k<<'\n';
    for(i=k+1;i<=k1;++i)
        cout<<i<<' ';
    return 0;
}