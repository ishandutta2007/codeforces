#include <bits/stdc++.h>
using namespace std;
int v[103][103];
int ok[103][103];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t,n,i,m,j,mx=0,k;
    cin>>n;
    if(n%2==1)
    {
        for(i=1;i<=n;++i)
            cin>>j;
        cout<<"YES\n";
        cout<<n-1<<'\n';
        for(i=1;i<=n/2;++i)
            cout<<"1 "<<i*2<<' '<<i*2+1<<'\n';
        for(i=1;i<=n/2;++i)
            cout<<"1 "<<i*2<<' '<<i*2+1<<'\n';
    }
    else
    {
        long long s=0;
        for(i=1;i<=n;++i)
        {
            long long a;
            cin>>a;
            s^=a;
        }
        if(s)
        {
            cout<<"NO";
            return 0;
        }
        --n;
        cout<<"YES\n";
        cout<<n-1<<'\n';
        for(i=1;i<=n/2;++i)
            cout<<"1 "<<i*2<<' '<<i*2+1<<'\n';
        for(i=1;i<=n/2;++i)
            cout<<"1 "<<i*2<<' '<<i*2+1<<'\n';
    }
    return 0;
}