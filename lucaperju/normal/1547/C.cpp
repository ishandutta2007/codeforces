#include <bits/stdc++.h>
using namespace std;
int a[103],b[103];
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    long long q,m,i,j,l,r,t,n;
    cin>>t;
    while(t--)
    {
        int k;
        cin>>k>>n>>m;
        for(i=1;i<=n;++i)
            cin>>a[i];
        for(i=1;i<=m;++i)
            cin>>b[i];
        vector<int>rz;
        int ok=0;
        i=j=1;
        while(i<=n || j<=m)
        {
            if(i<=n && a[i]<=k)
            {
                if(a[i]==0)
                    ++k;
                rz.push_back(a[i]);
                ++i;
            }
            else if(j<=m && b[j]<=k)
            {
                if(b[j]==0)
                    ++k;
                rz.push_back(b[j]);
                ++j;
            }
            else
                break;
        }
        if((int)rz.size()<(n+m))
            cout<<"-1\n";
        else
        {
            for(int i=0;i<rz.size();++i)
                cout<<rz[i]<<' ';
            cout<<'\n';
        }
    }
    return 0;
}