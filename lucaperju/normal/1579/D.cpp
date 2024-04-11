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
int v[200005];
priority_queue< pair<int,int> > q; /// tf is the point of this problem
vector<pair<int,int> >rz;
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    long long t,i,j;
    cin>>t;
    while(t--)
    {
        long long n;
        cin>>n;
        while(!q.empty())
            q.pop();
        for(i=1;i<=n;++i)
        {
            cin>>v[i];
            q.push(make_pair(v[i],i));
        }
        rz.clear();
        while(1)
        {
            pair<int,int>a,b;
            a=q.top();
            q.pop();
            b=q.top();
            q.pop();
            if(a.first==0 || b.first==0)
                break;
            --a.first;
            --b.first;
            rz.push_back(make_pair(a.second,b.second));
            q.push(a);
            q.push(b);
        }
        cout<<rz.size()<<'\n';
        for(i=0;i<rz.size();++i)
            cout<<rz[i].first<<' '<<rz[i].second<<'\n';
    }
    return 0;
}