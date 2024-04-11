#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    long long i,j,n,t,m,k;
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        if(k<n)
        {
            cout<<k*(k+1LL)/2LL<<'\n';
        }
        else if(k>=n)
        {
            cout<<n*1LL*(n-1LL)/2LL+1<<'\n';
        }
    }
    return 0;
}