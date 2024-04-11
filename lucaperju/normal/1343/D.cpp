#include <bits/stdc++.h>
using namespace std;
int mars[400005];
int v[200005];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    long long mxc=0,m,i,j=0,t,x,z,y,n,k;
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        for(i=1;i<=2*k;++i)
            mars[i]=0;
        for(i=1;i<=n;++i)
            cin>>v[i];
        for(i=1;i<=n/2;++i)
        {
            int a=v[i];
            int b=v[n-i+1];
            mars[2]+=2;
            int valmn=a+b-(max(a,b)-1);
            int valmx=a+b+(k-min(a,b));
            --mars[valmn];
            ++mars[valmx+1];
            --mars[a+b];
            ++mars[a+b+1];
        }
        int mx=mars[2];
        for(i=2;i<=2*k;++i)
        {
            mars[i]+=mars[i-1];
            mx=min(mx,mars[i]);
        }
        cout<<mx<<'\n';
    }
    return 0;
}