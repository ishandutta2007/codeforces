#include <bits/stdc++.h>

using namespace std;
int a[100005],b[100005];
int am[2];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    long long i,j,mx=0,n,s=0,rz=0;
    int k,t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(i=1;i<=n;++i)
            cin>>a[i];
        for(i=1;i<=n;++i)
            cin>>b[i];
        int ok=1;
        am[0]=am[1]=0;
        for(i=1;i<=n;++i)
        {
            if(a[i]>b[i] && !am[0])
                ok=0;
            if(a[i]<b[i] && !am[1])
                ok=0;
            if(a[i]==-1)
                am[0]=1;
            if(a[i]==1)
                am[1]=1;
        }
        if(ok)
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}