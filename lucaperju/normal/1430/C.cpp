#include <bits/stdc++.h>
using namespace std;
long long v[200005];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    long long t,i,j,rz=0,s=0,k,n,m;
    cin>>t;
    while(t--)
    {
        cin>>n;
        cout<<2<<'\n';
        cout<<n<<' '<<n-1<<'\n';
        for(i=n;i>=3;--i)
        {
            cout<<i<<' '<<i-2<<'\n';
        }
    }
    return 0;
}