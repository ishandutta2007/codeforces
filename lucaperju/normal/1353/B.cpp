#include <bits/stdc++.h>

using namespace std;
int a[1003],b[1003];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    long long m,n,i,t,j,k,mx,p,mxx=0;
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        for(i=1;i<=n;++i)
        {
            cin>>a[i];
        }
        for(i=1;i<=n;++i)
            cin>>b[i];
        sort(b+1,b+n+1);
        j=n;
        for(i=n;i>=n-k+1;--i)
            a[++j]=b[i];
        sort(a+1,a+n+k+1);
        int s=0;
        for(i=n+k;i>k;--i)
            s+=a[i];
        cout<<s<<'\n';
    }
    return 0;
}