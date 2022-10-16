#include <bits/stdc++.h>

using namespace std;
long long v[300005];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    long long n,i,j,k=0,s=0,cnt=0,m,t;
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        s=0;
        for(i=k;i<=k*10LL;i+=k)
            s+=i%10LL;
        long long val=n/(k*10LL);
        s=s*1LL*val;
        for(i=k*10LL*val;i<=n;i+=k)
            s+=i%10;
        cout<<s<<'\n';
    }
    return 0;
}