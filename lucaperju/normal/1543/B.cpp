#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    long long m=0,i,j,n,l,r,t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        long long s=0;
        for(i=1;i<=n;++i)
        {
            int a;
            cin>>a;
            s+=a;
        }
        s=s%n;
        cout<<s*1LL*(n-s)<<'\n';
    }
    return 0;
}