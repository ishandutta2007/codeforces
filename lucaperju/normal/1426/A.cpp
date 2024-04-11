#include <bits/stdc++.h>
using namespace std;
int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    long long t,i,j,k,n,q,m;
    cin>>t;
    while(t--)
    {
        long long x;
        cin>>n>>x;
        if(n<=2)
            cout<<1<<'\n';
        else
            cout<<(n-3)/x+2<<'\n';
    }
    return 0;
}