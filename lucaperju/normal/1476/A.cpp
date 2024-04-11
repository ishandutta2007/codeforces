#include <bits/stdc++.h>

using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    long long t,n,m,i,j,k;
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        long long r=n%k;
        if(r==0)
        {
            cout<<1<<'\n';
            continue;
        }
        r=k-r;
        long long rz=1;
        rz+=(r-1)/n+1;
        cout<<rz<<'\n';
    }
    return 0;
}