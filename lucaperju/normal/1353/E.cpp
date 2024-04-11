#include <bits/stdc++.h>

using namespace std;
int v[1000006],sp[1000006];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    long long m,n,i,t,j,k,mx,p,mxx=0;
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        int cnt=0;
        for(i=1;i<=n;++i)
        {
            char c;
            cin>>c;
            v[i]=c-'0';
            cnt+=v[i];
            sp[i]=v[i];
            if(i<k)
                continue;
            sp[i]=v[i]+sp[i-k];
        }
        long long rz=max(0,cnt-1);
        for(i=n;i>max(0LL,n-k);--i)
        {
          /*  if(catst[i]!=(i-1)/k+1)
                rz=min(rz,cnt-sp[i]+(i-1)/k+1-sp[i]-catst[i]-catdr[i-(i-1)/k*k]);*/
            long long sc=0,mxc=0;
            for(j=i-(i-1)/k*k;j<=i;j+=k)
            {
                if(v[j]==0)
                    --sc;
                else
                    ++sc;
                if(sc<0)
                    sc=0;
                mxc=max(mxc,sc);
            }
            rz=min(rz,cnt-mxc);
        }
        cout<<rz<<'\n';
    }
    return 0;
}