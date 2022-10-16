#include <bits/stdc++.h>

using namespace std;
int a[1003],b[1003];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    long long m,n,i,t,j,k,mx,p,mxx=0;
    cin>>t;
    while(t--)
    {
        long long s=0;
        cin>>n;
        long long sc=0;
        for(i=1;i<=n/2+1;++i)
        {
            s+=(i-1)*1LL*((i*2LL-1LL)*(i*2LL-1LL)-sc);
            sc=(i*2LL-1LL)*(i*2LL-1LL);
        }
        cout<<s<<'\n';
    }
    return 0;
}