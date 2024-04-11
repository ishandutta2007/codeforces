#include <bits/stdc++.h>

using namespace std;
int v[5003];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,m,ok=0,i,j,cnt=4,h,l,r,t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(i=1;i<=n;++i)
            cin>>v[i];
        ok=0;
        for(i=1;i<=n;++i)
        {
            for(j=i+2;j<=n;++j)
                if(v[i]==v[j])
                {
                    cout<<"YES\n";
                    ok=1;
                    break;
                }
            if(ok)
                break;
        }
        if(!ok)
            cout<<"NO\n";
    }
    return 0;
}