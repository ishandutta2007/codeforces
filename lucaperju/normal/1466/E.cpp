#include <bits/stdc++.h>
using namespace std;
const long long mod=1000000007;
long long cnt[61][61];
vector<int>vc;
int main()
{
    ios_base::sync_with_stdio(false);
    long long t,n,i,j,k,m;
    long long a,x1,y1,x2,y2;
    cin>>t;
    while(t--)
    {
    for(i=0;i<=60;++i)
        for(j=0;j<=60;++j)
            cnt[i][j]=0;
    cin>>n;
    for(i=1;i<=n;++i)
    {
        cin>>a;
        vc.clear();
        j=0;
        while(a)
        {
            if(a&1LL)
                vc.push_back(j);
            a>>=1LL;
            ++j;
        }
        for(j=0;j<vc.size();++j)
            for(k=0;k<vc.size();++k)
                ++cnt[vc[j]][vc[k]];
    }
    long long pc=1;
    long long rz=0;
    for(i=0;i<=120;++i)
    {
        long long s=0;
        for(j=0;j<=i;++j)
        {
            if(j>60 || i-j>60)
                continue;
            long long vlc=cnt[j][j];
            s=(s+vlc*1LL*cnt[j][i-j]%mod*1LL*n%mod)%mod;
            s=(s+vlc*1LL*(cnt[j][j]-cnt[j][i-j])%mod*1LL*cnt[i-j][i-j]%mod)%mod;
        }
        rz=(rz+(pc*1LL*s)%mod)%mod;
        pc=pc*2LL%mod;
    }
    cout<<rz%mod<<'\n';
    }
    return 0;
}