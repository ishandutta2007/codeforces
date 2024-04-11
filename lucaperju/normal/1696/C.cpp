#include <bits/stdc++.h>

using namespace std;
int a[500005];
int b[500005];
struct ura
{
    long long val,cnt;
}v1[500005],v2[500005];
int main()
{
    ios_base::sync_with_stdio(false);
    int k=0,t,i,j,n,m,x,y,ok=1;
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        for(i=1;i<=n;++i)
            cin>>a[i];
        cin>>m;
        for(i=1;i<=m;++i)
            cin>>b[i];
        int pz=0;
        for(i=1;i<=n;++i)
        {
            int cntc=1,vlc=a[i];
            while(vlc%k==0)
            {
                vlc/=k;
                cntc*=k;
            }
            if(vlc!=v1[pz].val)
                v1[++pz]={vlc,cntc};
            else
                v1[pz].cnt+=cntc;
        }
        int pz2=0;
        for(i=1;i<=m;++i)
        {
            int cntc=1,vlc=b[i];
            while(vlc%k==0)
            {
                vlc/=k;
                cntc*=k;
            }
            if(vlc!=v2[pz2].val)
                v2[++pz2]={vlc,cntc};
            else
                v2[pz2].cnt+=cntc;
        }
        if(pz!=pz2)
        {
            cout<<"NO\n";
            continue;
        }
        int ok=1;
        for(i=1;i<=pz;++i)
        {
            if(v1[i].cnt!=v2[i].cnt || v1[i].val!=v2[i].val)
                ok=0;
        }
        if(ok)
            cout<<"YES\n";
        else
            cout<<"No\n";
    }
    return 0;
}