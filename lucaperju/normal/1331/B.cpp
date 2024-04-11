#include <bits/stdc++.h>

using namespace std;
const int mod=1000000007;
int main ()
{
    ios::sync_with_stdio (false);
    cin.tie (0); cout.tie (0);
    int i,j,n;
    cin>>n;
    for(i=2;i<=n;++i)
    {
        if(n%i==0)
        {
            cout<<i<<n/i;
            return 0;
        }
    }
}