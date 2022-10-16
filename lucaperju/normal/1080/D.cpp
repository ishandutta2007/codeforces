#include <bits/stdc++.h>

using namespace std;
int main()
{
    long long a,b,i,t,put,s;
    cin>>t;
    while(t--)
    {
        cin>>a>>b;
        if(a==2 && b==3)
        {
            cout<<"NO\n";
            continue;
        }
        long long cb=b;
        put=1;
        long long n=a;
        for(i=1;i<=n;++i)
        {
            if(cb>put)
                cb-=put;
            else
                break;
            put=put*4LL;
        }
        if(i==n+1)
        {
            cout<<"NO\n";
            continue;
        }
        cout<<"YES ";
        s=0;
        put=2;
        long long sc;
        for(i=n;i>=1;--i)
        {
            sc=s;
            s=(long long)s+put;
            --s;
            if(s>b)
                break;
            put=put*2LL;
        }
        cout<<i<<'\n';
    }
}