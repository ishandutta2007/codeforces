#include <bits/stdc++.h>
using namespace std;
int v[200005];
int main()
{
    ios_base::sync_with_stdio(false);
    long long t,n,i,j,mod,m;
    cin>>t;
    while(t--)
    {
        long long a,b;
        cin>>n>>m>>a>>b;
        for(i=1;i<=m;++i)
            cin>>v[i];
        sort(v+1,v+m+1);
        long long timpt,timpd;
        timpd=max(b-a,a-b)-1;
        m=min(m,timpd);
        timpt=timpd;
        if(a<b)
            timpt+=a-1;
        else
            timpt+=n-a;
        int cntc=0;
        for(i=m;i>=1;--i)
        {
            if(timpt-cntc>=v[i])
            {
                ++cntc;
            }
        }
        cout<<cntc<<'\n';
    }
    return 0;
}