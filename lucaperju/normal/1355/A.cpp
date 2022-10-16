#include <bits/stdc++.h>

using namespace std;
long long mindigit(long long nr)
{
    long long mn=10;
    while(nr>0)
    {
        mn=min(mn,nr%10);
        nr/=10;
    }
    return mn;
}
long long maxdigit(long long nr)
{
    long long mx=0;
    while(nr>0)
    {
        mx=max(mx,nr%10);
        nr/=10;
    }
    return mx;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    unsigned long long i,t,j,k,mx,p,mxx=0,s;
    unsigned long long q=1,n;
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        for(i=2;i<=k;++i)
        {
            if(mindigit(n)*maxdigit(n)==0)
                break;
            n=n+mindigit(n)*maxdigit(n);
        }
        cout<<n<<'\n';
    }
    return 0;
}