#include <bits/stdc++.h>
using namespace std;
long long v[200005];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    long long n,m,i,j,t,x,y,k;
    cin>>n>>m>>x>>k>>y;
    for(i=1;i<=n;++i)
        cin>>v[i];
    i=1;
    long long rz=0;
    long long ap=0;
    for(j=1;j<=m;++j)
    {
        long long a;
        cin>>a;
        long long cnt=0;
        long long mxc=0;
        while(i<=n && v[i]!=a)
        {
            mxc=max(mxc,v[i]);
            ++i;
            ++cnt;
        }
        if(i==n+1)
        {
            cout<<-1;
            return 0;
        }
        if(mxc<max(a,ap))
        {
            rz+=y*(cnt%k);
            cnt-=cnt%k;
            rz+=min(cnt*1LL*y,x*1LL*cnt/k);
        }
        else
        {
            if(cnt==cnt%k)
            {
                cout<<-1;
                return 0;
            }
            rz+=y*(cnt%k);
            cnt-=cnt%k;
            rz+=x;
            cnt-=k;
            rz+=min(cnt*y,x*cnt/k);
        }
        ++i;
        ap=a;
    }
    long long mxc=0;
    long long a=0;
    long long cnt=0;
    while(i<=n && v[i]!=a)
    {
        mxc=max(mxc,v[i]);
        ++i;
        ++cnt;
    }
    if(mxc<max(a,ap))
        {
            rz+=y*(cnt%k);
            cnt-=cnt%k;
            rz+=min(cnt*1LL*y,x*1LL*cnt/k);
        }
        else
        {
            if(cnt==cnt%k)
            {
                cout<<-1;
                return 0;
            }
            rz+=y*(cnt%k);
            cnt-=cnt%k;
            rz+=x;
            cnt-=k;
            rz+=min(cnt*y,x*cnt/k);
        }
    cout<<rz;
    return 0;
}