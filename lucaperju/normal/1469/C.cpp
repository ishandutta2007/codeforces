#include <bits/stdc++.h>
using namespace std;
long long v[200005];
int main()
{
    ios_base::sync_with_stdio(false);
    long long t,n,i,j,k,mod,m;
    long long x1,y1,x2,y2;
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        for(i=1;i<=n;++i)
            cin>>v[i];
        long long st,dr;
        st=v[1]+1;
        dr=v[1]+k;
        for(i=2;i<=n;++i)
        {
            st=max(v[i]+1,st-k+1);
            dr=min(dr+k-1,v[i]+k+k-1);
            if(st+k-1>dr)
            {
                st=-1;
                break;
            }
        }
        if(st==v[n]+1)
            cout<<"Yes\n";
        else
            cout<<"No\n";
    }
    return 0;
}