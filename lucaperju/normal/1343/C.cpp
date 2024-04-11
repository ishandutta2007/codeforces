#include <bits/stdc++.h>
using namespace std;
long long v[200005];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    long long mxc=0,m,i,j=0,t,x,z,y,n,k;
    long long s=0,mx=0;
    cin>>t;
    while(t--)
    {
        s=0;
        mx=-1000000001;
        cin>>n;
        for(i=1;i<=n;++i)
            cin>>v[i];
        for(i=1;i<=n+1;++i)
        {
            if(i==n+1 || (v[i]<0 && v[i-1]>0) || (v[i]>0 && v[i-1]<0))
            {
                s+=mx;
                mx=-1000000001;
            }
            mx=max(mx,v[i]);
        }
        cout<<s<<'\n';
    }
    return 0;
}