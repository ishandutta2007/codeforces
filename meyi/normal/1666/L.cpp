#include<iostream>
#include<cstdio>
#include<queue>
#include<algorithm>
using namespace std;
struct edge
{
    int nxt,to;
}e[200001<<1];
struct element
{
    int now,f,tag;
};
int n,m,s,tot,h[200001],pre[200001],vis[200001];
inline void add(int x,int y)
{
    e[++tot].nxt=h[x];
    h[x]=tot;
    e[tot].to=y;
}
inline void bfs()
{
    queue<element> q;
    for(int i=h[s];i;i=e[i].nxt)
        q.push({e[i].to,s,e[i].to});
    vis[s]=-1;
    while(!q.empty())
    {
        element k=q.front();
        q.pop();
        if(k.now==s)
            continue;
        if(vis[k.now])
        {
            if(k.tag!=vis[k.now])
            {
                cout<<"Possible\n";
                vector<int> ans;
                for(int i=k.now;i;i=pre[i])
                    ans.emplace_back(i);
                reverse(ans.begin(),ans.end());
                cout<<ans.size()<<'\n';
                for(auto i:ans)
                    cout<<i<<" ";
                cout<<'\n';
                ans.clear();
                ans.emplace_back(k.now);
                for(int i=k.f;i;i=pre[i])
                    ans.emplace_back(i);
                reverse(ans.begin(),ans.end());
                cout<<ans.size()<<'\n';
                for(auto i:ans)
                    cout<<i<<" ";
                cout<<'\n';
                exit(0);
            }
            continue;
        }
        vis[k.now]=k.tag;
        pre[k.now]=k.f;
        for(int i=h[k.now];i;i=e[i].nxt)
            q.push({e[i].to,k.now,k.tag});
    }
}
int main()
{
    cin>>n>>m>>s;
    for(int i=1;i<=m;++i)
    {
        int x,y;
        cin>>x>>y;
        add(x,y);
    }
    bfs();
    cout<<"Impossible\n";
    return 0;
}