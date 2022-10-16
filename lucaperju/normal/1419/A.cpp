#include <bits/stdc++.h>
using namespace std;
int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    long long t,i,j,k,n,q,rz=0,m;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int a=0,b=0,val;
        val=n%2;
        for(i=1;i<=n;++i)
        {
            char c;
            cin>>c;
            c-='0';
            if(i%2==val)
            {
                if(c%2==0)
                    ++a;
                else
                    ++b;
            }
        }
        if(val==1)
        {
            if(b>0)
                cout<<1<<'\n';
            else
                cout<<2<<'\n';
        }
        else
        {
            if(a>0)
                cout<<2<<'\n';
            else
                cout<<1<<'\n';
        }
    }
    return 0;
}