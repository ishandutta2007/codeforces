#include <bits/stdc++.h>

using namespace std;
int main()
{
    long long i,j,n,m,b,k,s,q;
    cin>>q;
    while(q--)
    {
        int a;
        cin>>a;
        int ca=a;
        long long ok=0,cnt=0;
        while(ca)
        {
            if(ca%2==0)
                ok=1;
            ca/=2;
            ++cnt;
        }
        if(ok==0)
        {
            for(i=1;i*i<=a;++i)
                if(a%i==0)
                {
                        ok=max(ok,i);
                    if(i!=1)
                        ok=max(ok,a/i);
                }
            cout<<ok<<'\n';
        }
        else
        {
            cout<<(1<<(cnt))-1<<'\n';
        }
    }
}