#include <bits/stdc++.h>

using namespace std;

/*
const long long mod = 998244353;
long long fct[200005],invfct[200005],inv[200005];
long long put2[200005];
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
*/
vector<int>rz;
int v[2025],n;
void rev (int pz)
{
    assert(pz%2==1);
    assert(pz<=n);
    rz.push_back(pz);
    for(int i=1;i<=pz/2;++i)
        swap(v[i],v[pz-i+1]);
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    long long t,i,a,b,j,k,m;
    cin>>t;
    while(t--)
    {
        cin>>n;
        rz.clear();
        for(i=1;i<=n;++i)
        {
            cin>>v[i];
        }
        for(i=1;i<=n;++i)
            if(v[i]%2!=i%2)
                break;
        if(i!=n+1)
        {
            cout<<"-1\n";
            continue;
        }
        int nc=n;
        for(int vlc=n;vlc>1;vlc-=2,nc-=2)
        {
            int a,b;
            for(i=1;i<=nc;++i)
            {
                if(v[i]==vlc)
                    a=i;
                if(v[i]==vlc-1)
                    b=i;
            }
            rev(a);
            for(i=1;i<=nc;++i)
            {
                if(v[i]==vlc)
                    a=i;
                if(v[i]==vlc-1)
                    b=i;
            }
            rev(b-1);
            for(i=1;i<=nc;++i)
            {
                if(v[i]==vlc)
                    a=i;
                if(v[i]==vlc-1)
                    b=i;
            }
            rev(b+1);
            rev(3);
            rev(nc);
        }
        cout<<rz.size()<<'\n';
        for(i=0;i<rz.size();++i)
            cout<<rz[i]<<' ';
        cout<<'\n';
    }
    return 0;
}