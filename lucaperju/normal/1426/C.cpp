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
        cin>>n;
        long long rz=n;
        for(i=1;i*i-5<=n;++i)
        {
            rz=min(rz,i+(n-1)/i-1);
        }
        cout<<rz<<'\n';
    }
    return 0;
}