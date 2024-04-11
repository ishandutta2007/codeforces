#include <bits/stdc++.h>
using namespace std;
int v[10003];
int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int n,i,j,k,t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(i=1;i<=n;++i)
            cin>>v[i];
        int s=0;
        for(i=1;i<=n;++i)
        {
            s+=v[i];
        }
        if(s<=n/2)
        {
            cout<<n/2<<'\n';
            for(i=1;i<=n/2;++i)
                cout<<0<<' ';
        }
        else
        {
            if((n/2)%2==1)
                n+=2;
            cout<<n/2<<'\n';
            for(i=1;i<=n/2;++i)
                cout<<1<<' ';
        }
        cout<<'\n';
    }
    return 0;
}