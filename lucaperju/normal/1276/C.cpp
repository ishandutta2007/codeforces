#include <bits/stdc++.h>
using namespace std;
struct ura
{
    int val,cnt;
}v[400005];
int vi[400005];
bool cmp (ura a, ura b)
{
    return a.cnt<b.cnt;
}
vector<int>rz[4000];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    long long m,i,j,n,t;
    cin>>n;
    int ni=n;
    for(i=1;i<=n;++i)
        cin>>vi[i];
    sort(vi+1,vi+n+1);
    int cnt=0;
    j=0;
    for(i=1;i<=n;++i)
    {
        ++cnt;
        if(i==n || vi[i]!=vi[i+1])
        {
            v[++j]={vi[i],cnt};
            cnt=0;
        }
    }
    n=j;
    sort(v+1,v+n+1,cmp);
    int mx=n;
    int l=1;
    int sc=0;
  /*  for(i=1;i<=n;++i)
    {
        int lc=v[i].cnt;
        if(sc/lc+n-i+1>=lc)
        {
            int Lc=sc/lc+n-i+1;
            if(lc*Lc>mx)
            {
                mx=lc*Lc;
                l=lc;
            }
        }
        sc+=v[i].cnt;
    }*/
    i=1;
    for(int lc=1;lc<=ni;++lc)
    {
        while(i<=n && v[i].cnt<lc)
            sc+=v[i++].cnt;
        if(sc/lc+n-i+1>=lc)
        {
            int Lc=sc/lc+n-i+1;
            if(lc*Lc>mx)
            {
                mx=lc*Lc;
                l=lc;
            }
        }
    }
    cout<<mx<<'\n'<<l<<' '<<mx/l<<'\n';
    for(i=1;i<=l;++i)
        rz[i].resize(mx/l+2);
    i=j=1;
    int L=mx/l;
    for(int pz=n;pz>=1;--pz)
    {
        for(int k=1;k<=min(l,v[pz].cnt);++k)
        {
            rz[i][j]=v[pz].val;
            ++i;
            ++j;
            if(j==L+1)
                j=1;
            if(i==l+1)
            {
                i=1;
                j-=l;
                ++j;
                if(j<=0)
                    j+=L;
            }
        }
    }
    for(i=1;i<=l;++i)
    {
        for(j=1;j<=L;++j)
            cout<<rz[i][j]<<' ';
        cout<<'\n';
    }
    return 0;
}