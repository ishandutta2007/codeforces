#include <bits/stdc++.h>
using namespace std;
bitset<200003>v[60];///mlc
bitset<200003>vc;
int fv[60];
int main()
{
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    ios_base::sync_with_stdio(false);
    int i,j,n,t,m,p;
    cin>>n>>m>>p;
    for(i=0;i<n;++i)
    {
        for(j=0;j<m;++j)
        {
            char c;
            cin>>c;
            c-='0';
            v[j][i]=c;
            fv[j]+=c;
        }
    }
    long long mfv=0;
    for(i=0;i<m;++i)
    {
        if(fv[i]>=(n+1)/2)
            mfv=mfv|(1LL<<i);
    }
    long long msk;
    int mx=0;
    long long ans=0;
    for(int k=1;k<=10;++k)
    {
        int pz=(rng())%n;
        msk=0;
        for(i=0;i<m;++i)
            if(v[i][pz])
                msk=msk|(1LL<<i);
        msk=(msk&mfv);
        for(long long submask = msk; submask; submask = ((submask-1)&msk))
        {
            int cnt=0;
            for(i=0;i<m;++i)
            {
                if(submask&(1LL<<i))
                    ++cnt;
            }
            if(cnt<=mx)
                continue;
            vc.reset();
            vc.flip();
            for(i=0;i<m;++i)
            {
                if(submask&(1LL<<i))
                {
                    vc=(vc&v[i]);
                }
            }
            if(vc.count()>=(n+1)/2)
            {
                if(cnt>mx)
                {
                    mx=cnt;
                    ans=submask;
                }
            }
        }
    }
    for(i=0;i<m;++i)
        if(ans&(1LL<<i))
            cout<<1;
        else cout<<0;
    return 0;
}