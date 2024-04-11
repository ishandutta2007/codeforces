#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    long long m,i,j,t,k;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        for(i=1;i<=n;++i)
        {
            if(i%2)
                cout<<i<<' ';
            else
                cout<<i-1<<' ';
        }
        cout<<'\n';
    }
    return 0;
}