#include <bits/stdc++.h>
using namespace std;
long long cst[200005];
vector<int>v[200005];
long long dsta[200005],dstb[200005],dstc[200005];
int viz[200005];
int q[200005];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    long long mxc=0,n,m,i,j=0,t,x,z,y;
    cin>>t;
    while(t--)
    {
        long long mx=2000000000000000LL;
        cin>>n>>m>>x>>y>>z;
        for(i=1;i<=n;++i)
            v[i].clear();
        for(i=1;i<=m;++i)
            cin>>cst[i];
        sort(cst+1,cst+m+1);
        for(i=1;i<=m;++i)
            cst[i]+=cst[i-1];
        for(i=1;i<=m;++i)
        {
            int a,b;
            cin>>a>>b;
            v[a].push_back(b);
            v[b].push_back(a);
        }
        dsta[x]=dstb[y]=dstc[z]=0;
        int st=1,dr=0;
        q[++dr]=x;
        for(i=1;i<=n;++i)
            viz[i]=0;
        while(st<=dr)
        {
            int pz=q[st++];
            viz[pz]=1;
            for(i=0;i<v[pz].size();++i)
                if(!viz[v[pz][i]])
                {
                    viz[v[pz][i]]=1;
                    dsta[v[pz][i]]=1+dsta[pz];
                    q[++dr]=v[pz][i];
                }
        }
        for(i=1;i<=n;++i)
            viz[i]=0;
        st=1;
        dr=0;
        q[++dr]=y;
        while(st<=dr)
        {
            int pz=q[st++];
            viz[pz]=1;
            for(i=0;i<v[pz].size();++i)
                if(!viz[v[pz][i]])
                {
                    viz[v[pz][i]]=1;
                    dstb[v[pz][i]]=1+dstb[pz];
                    q[++dr]=v[pz][i];
                }
        }
        for(i=1;i<=n;++i)
            viz[i]=0;
        st=1;
        dr=0;
        q[++dr]=z;
        while(st<=dr)
        {
            int pz=q[st++];
            viz[pz]=1;
            for(i=0;i<v[pz].size();++i)
                if(!viz[v[pz][i]])
                {
                    viz[v[pz][i]]=1;
                    dstc[v[pz][i]]=1+dstc[pz];
                    q[++dr]=v[pz][i];
                }
        }
        cst[m+1]=mx;
        for(i=1;i<=n;++i)
            mx=min(mx,cst[dstb[i]]+cst[min(m+1,dstb[i]+dsta[i]+dstc[i])]);
        cout<<mx<<'\n';
    }
    return 0;
}