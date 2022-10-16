#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    long long n,i,j;
    int t;
    cin>>t;
    while(t--)
    {
        int cnt=0;
            cin>>n;
    for(i=1;i<=n+n;++i)
    {
        int a;
        cin>>a;
        cnt+=a%2;
    }
    if(cnt==n)
            cout<<"YES\n";
    else
            cout<<"NO\n";
    }
    return 0;
}