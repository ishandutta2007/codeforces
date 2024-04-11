#include <bits/stdc++.h>
using namespace std;
int x[203];
int main()
{
    ios_base::sync_with_stdio(false); /// jmek problema
    long long t,n,i,j,mod;
    cin>>t;
    while(t--)
    {
        int m;
        cin>>n>>m;
        for(i=2;i<=n+m;++i)
            x[i]=0;
        for(i=1;i<=n;++i)
            for(j=1;j<=m;++j)
            {
                int a;
                cin>>a;
                x[i+j]=(x[i+j] xor a);
            }
        int ok=1;
        for(i=1;i<=n+m;++i)
            if(x[i])
                ok=0;
        if(ok)
            cout<<"Jeel\n";
        else
            cout<<"Ashish\n";
    }
    return 0;
}