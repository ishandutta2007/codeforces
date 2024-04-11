#include <bits/stdc++.h>

using namespace std;

/*
const long long mod = 1000000007;

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
*/
map<pair<int,int>,long long>mp;
priority_queue<pair<long long,pair<int,int>>> pq;
vector<int>v[200005];
vector<int>cst[200005];
struct ura
{
    int a,b,c;
}idk[200005];
bool cmp (ura a, ura b)
{
    return a.c<b.c;
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    long long t,i,k,m,j=0,tt,p,n;
    t=1;
    //cin>>t;
    while(t--)
    {
        cin>>n>>m>>k;
        for(i=1;i<=m;++i)
            cin>>idk[i].a>>idk[i].b>>idk[i].c;
        sort(idk+1,idk+m+1,cmp);

        for(i=1;i<=min(m,k);++i)
        {
            long long a,b,c;
            //cin>>a>>b>>c;
            a=idk[i].a;
            b=idk[i].b;
            c=idk[i].c;
            v[a].push_back(b);
            v[b].push_back(a);
            cst[a].push_back(c);
            cst[b].push_back(c);
            pq.push(make_pair(-c,make_pair(a,b)));
            mp[make_pair(min(a,b),max(a,b))]=c;
        }
        long long cstc;
        while(k--)
        {
            pair<long long,pair<int,int>> a = pq.top();
            pq.pop();
            if(a.second.first==a.second.second)
            {
                ++k;
                continue;
            }
            if(a.second.first>a.second.second)
                swap(a.second.first,a.second.second);
            if(mp[a.second]==-1)
            {
                ++k;
                continue;
            }
            if(k==0)
            {
                cout<<-a.first;
                return 0;
            }
            int x=a.second.first,y=a.second.second;
            long long c=-a.first;
            mp[a.second]=-1;
            for(long long i=0;i<v[x].size();++i)
            {
                if(v[x][i]!=y && (mp[make_pair(min(v[x][i],y),max(v[x][i],y))]>(c+cst[x][i]) || mp[make_pair(min(v[x][i],y),max(v[x][i],y))]==0))
                {
                    pq.push(make_pair(-(c+cst[x][i]),make_pair(v[x][i],y)));
                    mp[make_pair(min(v[x][i],y),max(v[x][i],y))]=(c+cst[x][i]);
                }
            }
            for(long long i=0;i<v[y].size();++i)
            {
                if(x!=v[y][i] && (!mp[make_pair(min(v[y][i],x),max(v[y][i],x))] || mp[make_pair(min(v[y][i],x),max(v[y][i],x))]>(c+cst[y][i])))
                {
                    pq.push(make_pair(-(c+cst[y][i]),make_pair(x,v[y][i])));
                    mp[make_pair(min(v[y][i],x),max(v[y][i],x))]=(c+cst[y][i]);
                }
            }
        }
    }
    return 0;
}