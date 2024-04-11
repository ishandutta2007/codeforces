#include <bits/stdc++.h>
using namespace std;
int v[200005],n;
int poz (int i)
{
    return (i-1+n+n)%n+1;
}
int main()
{
    ios_base::sync_with_stdio(0);
    long long i,j,s=0,k,l,t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        int pz;
        int ok=1;
        for(i=1;i<=n;++i)
        {
            cin>>v[i];
            if(v[i]==1)
                pz=i;
        }
        int cpz=pz;
        int ok1=1,ok2=1;
        for(i=1;i<=n;++i)
        {
            if(v[pz]!=i)
                ok1=0;
            pz=poz(pz+1);
        }
        pz=cpz;
        for(i=1;i<=n;++i)
        {
            if(v[pz]!=i)
                ok2=0;
            pz=poz(pz-1);
        }
        if(ok1 || ok2)
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}