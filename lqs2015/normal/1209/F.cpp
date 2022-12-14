#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
int n,m,x[111111],y[111111],dist[111111],cnt,xp[11],crt,lst,res[111111],cur,ans[555555];
vector<pair<int,int> > g[111111];
vector<pair<int,int> > ng[555555];
vector<int> v,van,c[11];
stack<pair<vector<int>,int> > s;
bool used[555555];
int lent(int x)
{
    int res=0;
    while(x)
    {
        res++;
        x/=10;
    }
    return res;
}
void dijk()
{
    for (int i=1;i<=n;i++) dist[i]=1e9;
    dist[1]=0;
    priority_queue<pair<int,int> > pq;
    pq.push(make_pair(0,1));
    while(!pq.empty())
    {
        int x=pq.top().second,y=-pq.top().first;
        pq.pop();
        if (dist[x]!=y) continue;
        for (int i=0;i<g[x].size();i++)
        {
            int to=g[x][i].first,val=g[x][i].second;
            if (dist[to]>dist[x]+val)
            {
                dist[to]=dist[x]+val;
                pq.push(make_pair(-dist[to],to));
            }
        }
    }
}
int main()
{
    scanf("%d%d",&n,&m);
    for (int i=1;i<=m;i++)
    {
        scanf("%d%d",&x[i],&y[i]);
        int cst=lent(i);
        g[x[i]].push_back(make_pair(y[i],cst));
        g[y[i]].push_back(make_pair(x[i],cst));
    }
    dijk();cnt=n;
    for (int i=1;i<=m;i++)
    {
        if (dist[x[i]]+lent(i)==dist[y[i]] || dist[y[i]]+lent(i)==dist[x[i]])
        {
            crt=0;
            int k=i;
            while(k)
            {
                xp[++crt]=k%10;
                k/=10;
            }
            if (dist[x[i]]>dist[y[i]]) swap(x[i],y[i]);
            lst=x[i];
            for (int j=crt;j>=1;j--)
            {
                if (j==1) ng[lst].push_back(make_pair(xp[j],y[i]));
                else 
                {
                    ng[lst].push_back(make_pair(xp[j],++cnt));
                    lst=cnt;
                }
            }
        }
    }
    v.push_back(1);
    s.push(make_pair(v,0));
    for (int i=1;i<=cnt;i++) ans[i]=1e9;
    used[1]=1;
    while(!s.empty())
    {
        v=s.top().first;cur=s.top().second;
        s.pop();
        for (int i=0;i<v.size();i++)
        {
            if (v[i]<=n) res[v[i]]=cur;
        }
  //      for (int i=0;i<v.size();i++) cout<<v[i]<<" ";
  //      cout<<endl;
   //     cout<<cur<<endl<<endl;
        van.clear();
        for (int i=0;i<v.size();i++)
        {
            for (int j=0;j<ng[v[i]].size();j++)
            {
                int to=ng[v[i]][j].second,val=ng[v[i]][j].first;
                if (used[to]) continue;
                van.push_back(to);ans[to]=min(ans[to],val);
            }
        }
        for (int i=0;i<=9;i++) c[i].clear();
        for (int i=0;i<van.size();i++)
        {
            if (used[van[i]]) continue;
            used[van[i]]=1;
            c[ans[van[i]]].push_back(van[i]);
        }
        for (int i=9;i>=0;i--)
        {
            if (!c[i].empty()) 
            {
                s.push(make_pair(c[i],(10ll*cur+i)%mod));
            }
        }
    }
    for (int i=2;i<=n;i++) printf("%d\n",res[i]);
    return 0;
}