#include <bits/stdc++.h>
using namespace std;
long long fct[250004];
int main()
{
    ios_base::sync_with_stdio(false);
    long long t,n,i,mod;
    cin>>t;
    while(t--)
    {
        cin>>n;
        long long s=0,xc=0;
        for(i=1;i<=n;++i)
        {
            long long a;
            cin>>a;
            s+=a;
            xc=(xc xor a);
        }
        if(s==2*xc)
        {
            cout<<"0\n\n";
            continue;
        }
        cout<<"2\n";
        cout<<s+xc<<' '<<xc<<'\n';
    }
    return 0;
}