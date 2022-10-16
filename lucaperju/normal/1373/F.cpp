#include <bits/stdc++.h>
using namespace std;
int a[2000006],b[2000006];
long long sa[2000006],sb[2000006];
int main()
{
    ios_base::sync_with_stdio(false); /// ce jeg de F
    cin.tie(0);
    long long i,j,n,t,m,k,n1;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        for(i=1;i<=n;++i)
            cin>>a[i];
        for(i=1;i<=n;++i)
            cin>>b[i];
        for(i=n+1;i<=2*n;++i)
        {
            a[i]=a[i-n];
            b[i]=b[i-n];
        }
        a[0]=sa[0]=a[n];
        b[0]=sb[0]=b[n];
        long long mxc=0;
        long long ok=1;
        for(i=1;i<=2*n;++i)
        {
            sa[i]=sa[i-1]+a[i];
            sb[i]=sb[i-1]+b[i];
        }
        if(sb[n-1]<sa[n-1])
            ok=0;
        mxc=-sa[1]+sb[0];
        for(i=2;i<=2*n;++i)
        {
            if(sb[i]-sa[i]-mxc<0)
                ok=0;
            mxc=max(mxc,-sa[i]+sb[i-1]);
        }
        if(ok)
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}