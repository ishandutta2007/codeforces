#include <bits/stdc++.h>
using namespace std;
int v[10003];
long long st[10003],dr[10003];
int main()
{
    ios_base::sync_with_stdio(false);
    int i,j,n,t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        cout<<n/2*6<<'\n';
        for(i=1;i<=n;++i)
        {
            cin>>j;
        }
        for(i=1;i<=n;i+=2)
        {
            cout<<"2 "<<i<<' '<<i+1<<'\n';
            cout<<"1 "<<i<<' '<<i+1<<'\n';
            cout<<"2 "<<i<<' '<<i+1<<'\n';
            cout<<"2 "<<i<<' '<<i+1<<'\n';
            cout<<"1 "<<i<<' '<<i+1<<'\n';
            cout<<"2 "<<i<<' '<<i+1<<'\n';
        }
    }
    return 0;
}