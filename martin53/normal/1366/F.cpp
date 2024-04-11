#include<bits/stdc++.h>
#define int long long
using namespace std;

const int nmax=2e3+42,mod=1e9+7;

int n,m,q;

vector< pair<int,int> > adj[nmax];

long long maxi[2][nmax];

pair<long long,long long> meet(pair<long long,long long> le,pair<long long,long long> ri)
{
    return {le.second-ri.second,ri.first-le.first};
}
bool beat(pair<long long,long long> le,pair<long long,long long> tested,pair<long long,long long> ri)
{
    pair<long long,long long> p=meet(le,tested);
    pair<long long,long long> q=meet(tested,ri);

    return p.first*q.second<=p.second*q.first;
}

long long eval(pair<long long,long long> line,long long x)
{
    return line.first*x+line.second;
}

long long sum(long long from,long long to,pair<long long,long long> line)
{
    long long ret=0;
    ret=1LL*(from+to)*(to-from+1)/2;
    ret=ret%mod;
    ret=line.first%mod*ret%mod;

    ret=(ret+line.second%mod*(to-from+1))%mod;

    //i=from...to, sum line.first*i+line.second
    /*
    for(int i=from;i<=to;i++)
    {
        cout<<"fast: "<<i+m<<" -> "<<i*line.first+line.second<<endl;

        ret=(ret+1LL*i*line.first+line.second)%mod;
    }
    */
    return ret;
}
signed main()
{
    cin>>n>>m>>q;

    for(int i=1;i<=m;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;

        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }

    for(int i=2;i<=n;i++)maxi[0][i]=-1e18;

    long long outp=0;

    //use only 1 edge now
    vector< pair<long long,long long> > hull={},active={};

    int to=min(n+m,q);

    for(int t=1;t<=to;t++)
    {
        long long path=0;

        for(int i=1;i<=n;i++)
        {
            maxi[t&1][i]=-1e18;

            for(auto j:adj[i])
                maxi[t&1][i]=max(maxi[t&1][i],maxi[!(t&1)][j.first]+j.second);

            path=max(path,maxi[t&1][i]);

            long long mx_path=0;

            for(auto j:adj[i])
                if(mx_path<j.second)mx_path=j.second;

            if(maxi[t&1][i]>=0)hull.push_back({mx_path,maxi[t&1][i]+1LL*mx_path*(to-t)});

            //cout<<"hull: "<<mx_path<<" "<<maxi[m&1][i]<<endl;
        }

        outp=(outp+path)%mod;
    }

    /*
    for(auto w:active)
        cout<<"active: "<<w.first<<" "<<w.second<<endl;
    */

    sort(hull.begin(),hull.end());

    for(auto k:hull)
    {
        while(active.size()&&active.back().first<=k.first&&active.back().second<=k.second)active.pop_back();

        active.push_back(k);
    }

    q=q-to;

    long long moment=1;

    int pointer=0;

    while(moment<=q)
    {
        pair<long long,long long> cur={0,0};

        for(auto k:hull)
            if(eval(cur,moment)<eval(k,moment))cur=k;

            long long ok=moment,not_ok=q+1;

            while(not_ok-ok>1)
            {
                long long av=(ok+not_ok)/2;

                long long my=eval(cur,av);

                long long mx=0;

                for(auto k:hull)
                {
                    mx=max(mx,eval(k,av));

                    if(mx>my)break;
                }
                if(mx==my)ok=av;
                else not_ok=av;
            }

            long long high=ok;
            if(high>q)high=q;

            assert(moment<=high);

            outp=(outp+sum(moment,high,cur))%mod;
            moment=high+1;
    }
    cout<<outp<<endl;

    return 0;
}