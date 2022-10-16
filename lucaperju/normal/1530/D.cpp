#include <bits/stdc++.h>

using namespace std;

/*
const long long mod = 1000000007;
long long fct[200005],invfct[200005],inv[200005];
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
    inv[1]=fct[0]=fct[1]=invfct[0]=invfct[1]=1;
    for(long long i=2;i<=200000;++i)
        inv[i]=(mod-mod/i)*1LL*inv[mod%i]%mod,fct[i]=i*1LL*fct[i-1]%mod,invfct[i]=inv[i]*1LL*invfct[i-1]%mod;
}
*/

vector<int>intra[200005];
int rz[200005],vi[200005];

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    long long n,m,i,j,t,s=0;
    cin>>t;
    while(t--)
    {
        int cnt=0;
        cin>>n;
        for(i=1;i<=n;++i)
            intra[i].clear();
        for(i=1;i<=n;++i)
        {
            cin>>vi[i];
            intra[vi[i]].push_back(i);
        }
        for(i=1;i<=n;++i)
        {
            if(intra[i].size()>1)
            {
                for(int j=1;j<intra[i].size();++j)
                    vi[intra[i][j]]=-vi[intra[i][j]];
                while(intra[i].size()>1)
                    intra[i].pop_back();
            }
        }
        int cntin=0,cntout=0,cntboth=0;
        for(i=1;i<=n;++i)
        {
            if(vi[i]>0)
                ++cnt;
            if(vi[i]<0)
                ++cntout;
            if(intra[i].size()==0)
                ++cntin;
            if(vi[i]<0 && intra[i].size()==0)
                ++cntboth;
        }
        if(cntin==1 && cntboth==1 && cntout==1)
        {
            for(i=1;i<=n;++i)
                if(vi[i]<0)
                    break;
            vi[intra[-vi[i]][0]]=-vi[intra[-vi[i]][0]];
            intra[-vi[i]][0]=i;
            vi[i]=-vi[i];
        }
        cntin=cntout=cntboth=0;
        vector<int>vc;
        for(i=1;i<=n;++i)
        {
            if(vi[i]<0)
                ++cntout;
            if(intra[i].size()==0)
            {
                ++cntin;
                vc.push_back(i);
            }
            if(vi[i]<0 && intra[i].size()==0)
                ++cntboth;
        }
        if(cntin==1 && cntboth==1 && cntout==1)
            assert(0);
        for(i=1;i<=n;++i)
        {
            if(vi[i]<0 && intra[i].size()==0)
            {
                int vlc=vc.back();
                if(vlc==i)
                {
                    assert(vc.size()>=2);
                    vlc=vc[vc.size()-2];
                }
                vi[i]=vlc;
                intra[vlc].push_back(i);
                int a=vc.back();
                vc.pop_back();
                int b;
                if(vc.size()==0)
                    continue;
                b=vc.back();
                vc.pop_back();
                vc.push_back(a^b^vlc);
            }
        }
        for(i=1;i<=n;++i)
        {
            if(vi[i]<0)
            {
                int vlc=vc.back();
                if(vlc==i)
                {
                    assert(vc.size()>=2);
                    vlc=vc[vc.size()-2];
                }
                vi[i]=vlc;
                intra[vlc].push_back(i);
                int a=vc.back();
                vc.pop_back();
                int b;
                if(vc.size()==0)
                    continue;
                b=vc.back();
                vc.pop_back();
                vc.push_back(a^b^vlc);
            }
        }
        cout<<cnt<<'\n';
        for(i=1;i<=n;++i)
            cout<<vi[i]<<' ';
        cout<<'\n';
    }
    return 0;
}