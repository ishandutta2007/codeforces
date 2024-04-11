
#include <bits/stdc++.h>

using namespace std;
int v[55],fv[55];
int main()
{
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--)
    {
        long long n,i;
        cin>>n;
        for(i=1;i<=n;++i)
        {
            cin>>v[i];
            while(v[i]>n)
                v[i]/=2LL;
        }
        while(1)
        {
            for(i=1;i<=n;++i)
                fv[i]=0;
            for(i=1;i<=n;++i)
                ++fv[v[i]];
            if(fv[1]>1)
                break;
            for(i=1;i<=n;++i)
                if(fv[i]>1)
                    break;
            if(i==n+1)
                break;
            int val=i;
            for(i=1;i<=n;++i)
            {
                if(v[i]==val)
                {
                    v[i]/=2;
                    break;
                }
            }
        }
        if(fv[1]>1)
            cout<<"NO\n";
        else
            cout<<"YES\n";
    }

    return 0;
}