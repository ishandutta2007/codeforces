#include <bits/stdc++.h>

using namespace std;
int v[505];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    long long m,n,k,t,i,j,p,mxx=0,s,q,nr1=0,nr2=0,nr3=0;
    cin>>t;
    while(t--)
    {
        cin>>n;
        int ok=1;
        for(i=1;i<=n;++i)
        {
            cin>>v[i];
            if(i>=2 && v[i]<v[i-1])
                ok=0;
        }
        s=0;
        for(i=1;i<=n;++i)
        {
            int a;
            cin>>a;
            s+=a;
        }
        if(s==0 || s==n)
        {
            if(ok)
                cout<<"Yes\n";
            else
                cout<<"NO\n";
        }
        else
        {
            cout<<"Yes\n";
        }
    }
    return 0;
}