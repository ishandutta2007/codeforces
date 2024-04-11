#include <bits/stdc++.h>
 
using namespace std;
 
 
const long long mod = 998244353;
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
 
/// tf is the point of this problem
long long row[1000006][2];
long long col[1000006][2];
long long checker[2];
long long nrchecker=2;
long long nrcol2;
long long nrcol0;
long long nrrow2;
long long nrrow0;
map<int,int>mp[1000006];
void upd (int x, int y, int t)
{
    if(t==-1)
    {
        long long vlc=mp[x][y]-1;
        if(vlc==-1)
        {
            /// so dumb
            return;
        }
        /// row:
        long long pz=x;
        long long parity=(y+vlc)%2;
        row[pz][1-parity]--;
        if(row[pz][1-parity]==0)
        {
            if(row[pz][parity]!=0)
                --nrrow0;
            else
                ++nrrow2;
        }
        /// col: btw. I'm having so much fun writing this :)
        pz=y;
        parity=(x+vlc)%2;
        col[pz][1-parity]--;
        if(col[pz][1-parity]==0)
        {
            if(col[pz][parity]!=0)
                --nrcol0;
            else
                ++nrcol2;
        }
        /// checker:
        parity=(x+y+vlc)%2;
        checker[1-parity]--;
        if(checker[1-parity]==0)
            ++nrchecker;
        /// so cool
        mp[x][y]=0;
    }
    else
    {
        if(mp[x][y])
            upd(x,y,-1);
        long long vlc=t;
        mp[x][y]=1+vlc;
        /// row:
        long long pz=x;
        long long parity=(y+vlc)%2;
        row[pz][1-parity]++;
        if(row[pz][1-parity]==1)
        {
            if(row[pz][parity]!=0)
                ++nrrow0;
            else
                --nrrow2;
        }
        /// col: yay so much fun
        pz=y;
        parity=(x+vlc)%2;
        col[pz][1-parity]++;
        if(col[pz][1-parity]==1)
        {
            if(col[pz][parity]!=0)
                ++nrcol0;
            else
                --nrcol2;
        }
        /// checker:
        parity=(x+y+vlc)%2;
        checker[1-parity]++;
        if(checker[1-parity]==1)
            --nrchecker;
        /// so cool
    }
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t,i,r,m,s,j,q,n;
    init();
    cin>>n>>m>>q;
    nrcol2=m;
    nrrow2=n;
    for(i=1;i<=q;++i)
    {
        long long x,y,t;
        cin>>x>>y>>t;
        upd(x,y,t);
        long long ans=0;
        if(nrcol0==0)
            ans=(ans+lgput(2,nrcol2))%mod;
        if(nrrow0==0)
            ans=(ans+lgput(2,nrrow2))%mod;
        ans=(ans-nrchecker+mod)%mod;
        cout<<ans<<'\n';
    }
    return 0;
}