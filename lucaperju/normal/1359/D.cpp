#include <bits/stdc++.h>
using namespace std;
int v[100005];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int i,j,n,t,m;
    cin>>n;
    int rz=0,mxc=0,sc=0,val=0;
    for(i=1;i<=n;++i)
        cin>>v[i];
    for(val=-30;val<=30;++val)
    {
        sc=mxc=0;
        for(i=1;i<=n;++i)
        {
            sc+=v[i];
            mxc=max(mxc,v[i]);
            if(sc<0 || v[i]>val)
            {
                sc=0;
                mxc=0;
            }
            rz=max(rz,sc-mxc);
        }
    }
    cout<<rz;
    return 0;
}