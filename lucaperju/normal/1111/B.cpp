#include <bits/stdc++.h>

using namespace std;
long long v[100005],sp[100005];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    long long i,j,s=0,pz,m,ok=0,n,k;
    double mx=0;
    cin>>n>>k>>m;
    for(i=1;i<=n;++i)
        cin>>v[i];
    sort(v+1,v+n+1);
    for(i=n;i>=1;--i)
        sp[i]=sp[i+1]+v[i];
    ++m;
    for(i=0;i<n;++i)
    {
        s=sp[i+1];
        --m;
        if(m<0)
            break;
        s+=min(m,(n-i)*1LL*k);
        double cur=(double)s/(n-i);
        if(cur>mx)
            mx=cur;
    }
    cout<<setprecision(10)<<fixed<<mx;
    return 0;
}