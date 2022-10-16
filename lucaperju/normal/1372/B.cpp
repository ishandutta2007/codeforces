#include <bits/stdc++.h>
using namespace std;
int v[200005];
long long st[200005],dr[200005];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    long long m,i,j,t,k;
    cin>>t;
    while(t--)
    {
        long long n;
        cin>>n;
        for(i=2;i*i<=n;++i)
        {
            if(n%i==0)
                break;
        }
        if(n%i)
        {
            cout<<1<<' '<<n-1<<'\n';
        }
        else
        cout<<n/i<<' '<<n-n/i<<'\n';
    }
    return 0;
}