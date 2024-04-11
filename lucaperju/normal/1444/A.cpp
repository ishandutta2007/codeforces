#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int s=0,n,m,i,t,j,k=0;
    cin>>t;
    long long a,b;
    while(t--)
    {
        cin>>a>>b;
        if(a%b)
        {
            cout<<a<<'\n';
            continue;
        }
        long long cb=b;
        long long mx=1;
        for(i=2;i*i<=cb;++i)
        {
            if(cb%i==0)
            {
                long long ca=a;
                while(ca%i==0)
                    ca/=i;
                while(cb%i==0)
                {
                    cb/=i;
                    ca*=i;
                }
                ca/=i;
                mx=max(mx,ca);
            }
        }
        if(cb>1)
        {
            while(a%cb==0)
                a/=cb;
            mx=max(mx,a);
        }
        cout<<mx<<'\n';
    }
    return 0;
}