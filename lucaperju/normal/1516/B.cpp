#include <bits/stdc++.h>
using namespace std;
int v[2003];
int xp[2003];
int main()
{
    ios_base::sync_with_stdio(false);
    int q,t,m,i,j;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        for(i=1;i<=n;++i)
            cin>>v[i];
        for(i=1;i<=n;++i)
        {
            xp[i]=(v[i]^xp[i-1]);
        }
        int ok=0;
        if(xp[n]==0)
            ok=1;
        for(i=1;i<n;++i)
        {
            for(j=i+1;j<n;++j)
            {
                if(xp[i]==xp[n] && xp[j]==0)
                    ok=1;
            }
        }
        if(ok)
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
	return 0;
}