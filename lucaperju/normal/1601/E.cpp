#include <bits/stdc++.h>

using namespace std;

/*
const long long mod = 998244353;
//*
long long lgput (long long a, long long exp)
{
    long long rz=1;
    while(exp)
        if(exp&1)
            exp^=1,rz=rz*1LL*a%mod;
        else
            exp>>=1,a=a*1LL*a%mod;
    return rz;
}
long long fct[200005],invfct[200005],inv[200005];
long long put2[200005];
long long cmb (long long n, long long k)
{
    if(n<k || k<0 || n<0)
        return 0;
    return fct[n]*1LL*invfct[k]%mod*1LL*invfct[n-k]%mod;
}
void init ()
{
    inv[1]=fct[0]=fct[1]=invfct[0]=invfct[1]=put2[0]=1,put2[1]=2;
    for(long long i=2;i<=200000;++i)
        put2[i]=put2[i-1]*2LL%mod,inv[i]=(mod-mod/i)*1LL*inv[mod%i]%mod,fct[i]=i*1LL*fct[i-1]%mod,invfct[i]=inv[i]*1LL*invfct[i-1]%mod;
}
/*/
long long v[300005];
int lg[300005];
int rmq[20][300005];
struct ura
{
    int l,r,pz;
    long long s;
}qs[300005];
int getmin (int l, int r)
{
    int lgc=lg[r-l+1];
    return min(rmq[lgc][r],rmq[lgc][l+(1<<lgc)-1]);
}
int st[300005];
int nxtt[300005];
int nxt[20][300005];
long long sums[20][300005];
int vc[300005];
vector<int>pzqs[300005];
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int m,q,t,s=0,n,d,i,k;
    cin>>n>>q>>k;
    for(i=1;i<=n;++i)
    {
        cin>>v[i];
        rmq[0][i]=v[i];
    }
    lg[1]=0;
    for(i=2;i<=n;++i)
        lg[i]=1+lg[i>>1];
    for(int put=1;put<=19;++put)
        for(i=1;i<=n;++i)
            rmq[put][i]=min(rmq[put-1][i],rmq[put-1][max(1,i-(1<<(put-1)))]);
    int kk=0;
    for(i=n;i>=1;--i)
    {
        while(kk>0 && v[i]<v[st[kk]])
            --kk;
        if(kk==0)
            nxtt[i]=n+1;
        else
            nxtt[i]=st[kk];
        st[++kk]=i;
    }
    for(i=1;i<=q;++i)
    {
        int l,r;
        cin>>l>>r;
        qs[i].pz=i;
        int nxtc=nxtt[l];
        long long cat;
        if(r<nxtc)
        {
            cat=(r-l)/k;
            qs[i].s=v[l]*1LL*(cat+1LL);
            continue;
        }
        cat=(min(nxtc,r)-l-1)/k;
        qs[i].s=v[l]*1LL*(cat+1LL);
        l=l+cat*k;
        ++l;
        ++r;
        if(l%k<r%k)
            r-=r%k-l%k;
        else if (r%k<l%k)
            r-=(k+r%k-l%k);
        pzqs[l%k].push_back(i);
        l=(l-1)/k+1;
        r=(r-1)/k+1;
        qs[i].l=l;
        qs[i].r=r;
        /// doamne ajuta sa fie ok transformarea asta
    }
    for(int modc=0;modc<k;++modc)
    {
        /// aici teoretic ar trebui sa fac O(n/k) *log
        if(pzqs[modc].size()==0)
            continue;
        int nc=0;
        for(i=(modc+k-1)%k+1;i<=n;i+=k)
            if(i+k-1<=n)
                vc[++nc]=getmin(i,i+k-1);
        kk=0;
        for(i=nc;i>=1;--i)
        {
            while(kk>0 && vc[i]<vc[st[kk]])
                --kk;
            if(kk==0)
                nxt[0][i]=nc+1;
            else
                nxt[0][i]=st[kk];
            st[++kk]=i;
        }
        nxt[0][nc+1]=nc+1;
        for(i=1;i<=nc;++i)
            sums[0][i]=vc[i]*1LL*(nxt[0][i]-i);
        for(int put=1;put<=lg[nc]+1;++put)
            for(i=1;i<=nc+1;++i)
            {
                nxt[put][i]=nxt[put-1][nxt[put-1][i]];
                sums[put][i]=sums[put-1][i]+sums[put-1][nxt[put-1][i]];
            }
        for(i=0;i<pzqs[modc].size();++i)
        {
            int l=qs[pzqs[modc][i]].l;
            int r=qs[pzqs[modc][i]].r;
            --r;
            if(r<l)
                continue;
            if(l==r)
            {
                qs[pzqs[modc][i]].s+=vc[l];
                continue;
            }
            long long s=0;
            for(int put=lg[nc]+1;put>=0;--put)
            {
                if(nxt[put][l]<=r)
                {
                    s=s+sums[put][l];
                    l=nxt[put][l];
                }
            }
            s=s+vc[l]*1LL*(r-l+1);
            qs[pzqs[modc][i]].s+=s;
        }
    }
    for(i=1;i<=q;++i)
        cout<<qs[i].s<<'\n';
    return 0;
}