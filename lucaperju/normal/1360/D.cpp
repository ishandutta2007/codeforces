#include <bits/stdc++.h>

using namespace std;
int v[200005];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    long long t,n,i,m,j,k,mx,p,mxx=0,s,q,nr1=0,nr2=0,nr3=0;
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        long long rz=n;
        for(i=1;i*i<=n;++i)
        {
            if(n%i==0)
            {
                if(i<=k)
                    rz=min(rz,n/i);
                if(n/i<=k)
                    rz=min(rz,i);
            }
        }
        cout<<rz<<'\n';
    }
    return 0;
}