#include <bits/stdc++.h>

using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    long long t,n,m,i,j,k,s;
    cin>>t;
    while(t--)
    {
        s=0;
        cin>>n>>k;
        long long mx=0;
        for(i=1;i<=n;++i)
        {
            long long a;
            cin>>a;
            if(i!=1)
            {
                long long dif=a*100LL-s*1LL*k;
                if(dif>0)
                {
                    mx=max(mx,(dif-1)/k+1);
                }
            }
            s+=a;
        }
        cout<<mx<<'\n';
    }
    return 0;
}