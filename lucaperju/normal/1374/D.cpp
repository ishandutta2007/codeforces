#include <bits/stdc++.h>
using namespace std;
int v[200005];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    long long i,j,n,t,m,k,n1;
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        int j=0;
        for(i=1;i<=n;++i)
        {
            long long a;
            cin>>a;
            if(a%k!=0)
                v[++j]=a%k;
        }
        n=j;
        for(i=1;i<=n;++i)
            v[i]=k-v[i];
        sort(v+1,v+n+1);
        int cntc=0,mx=0,pz=0;
        for(i=1;i<=n;++i)
        {
            ++cntc;
            if(i==n || v[i]!=v[i+1])
            {
                if(cntc>mx)
                    mx=cntc,pz=v[i];
                else if(cntc==mx)
                    pz=v[i];
                cntc=0;
            }
        }
        if(n)
            cout<<(mx-1)*k+pz+1<<'\n';
        else
            cout<<0<<'\n';
    }
    return 0;
}