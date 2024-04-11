#include <bits/stdc++.h>

using namespace std;
int a[200005],b[200005];
int cnt[200005];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    long long m,n,k,t,i,j,p,mxx=0,s,q,nr1=0,nr2=0,nr3=0;
    cin>>n;
    for(i=1;i<=n;++i)
        cin>>a[i];
    for(i=1;i<=n;++i)
    {
        int x;
        cin>>x;
        b[x]=i;
    }
    for(i=1;i<=n;++i)
    {
        int pz1=i;
        int pz2=b[a[i]];
        if(pz2<pz1)
            pz2+=n;
        ++cnt[pz2-pz1];
    }
    int mx=0;
    for(i=0;i<=n;++i)
    {
        mx=max(mx,cnt[i]);
    }
    cout<<mx;
    return 0;
}