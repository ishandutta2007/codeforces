#include <bits/stdc++.h>

using namespace std;
long long v[505];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    long long m,n,k,t,i,j,mx,p,mxx=0,s,q,nr1=0,nr2=0,nr3=0;
    cin>>n;
    for(i=1;i<=n;++i)
        cin>>v[i];
    long long rz=0;
    for(i=1;i<=n;++i)
        for(j=i;j<=n;++j)
            for(k=j;k<=n;++k)
            {
                rz=max(rz,v[i]|v[j]|v[k]);
            }
    cout<<rz;
    return 0;
}