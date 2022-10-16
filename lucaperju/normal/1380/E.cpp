#include <bits/stdc++.h>
using namespace std;
int t[200005];
int v[200005];
vector <int> pz[200005];
int sz[200005];
vector <int> vc[200005];
int tata (int i)
{
    if(t[i]==0 || t[i]==i)
        return i;
    return t[i]=tata(t[i]);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    long long n,m,i,j,x,y,k;
    cin>>n>>m;
    int cnt=0;
    for(i=1;i<=n;++i)
    {
        cin>>v[i];
        if(v[i]!=v[i-1])
            ++cnt;
        pz[v[i]].push_back(i);
    }
    cout<<cnt-1<<'\n';
    for(i=1;i<=m;++i)
    {
        sz[i]=1;
        vc[i].push_back(i);
        t[i]=i;
    }
    for(i=1;i<m;++i)
    {
        int a,b;
        cin>>a>>b;
        a=tata(a);
        b=tata(b);
        if(sz[a]<sz[b])
            swap(a,b);
        /// a <--- b
        for(j=0;j<vc[b].size();++j)
        {
            int vlc=vc[b][j];
            for(k=0;k<pz[vlc].size();++k)
            {
                int pzc=pz[vlc][k];
                if(tata(v[pzc-1])==a)
                    --cnt;
                if(tata(v[pzc+1])==a)
                    --cnt;
            }
            vc[a].push_back(vlc);
        }
        vc[b].clear();
        sz[a]+=sz[b];
        t[b]=a;
        cout<<cnt-1<<'\n';
    }
    return 0;
}