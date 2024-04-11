
/*****************************************
Author: lizi
Email: lzy960601@outlook.com
****************************************/
  
#include<bits/stdc++.h>
  
using namespace std;
  
const double eps=1e-10;
const double pi=3.1415926535897932384626433832795;
const double eln=2.718281828459045235360287471352;
  
#define LL long long
#define IN freopen("in.txt", "r", stdin)
#define OUT freopen("out.txt", "w", stdout)
#define scan(x) scanf("%d", &x)
#define mpr make_pair
#define pb push_back
#define sqr(x) (x) * (x)
#define pr(x) printf("Case %d: ",x)
#define prn(x) printf("Case %d:\n",x)
#define prr(x) printf("Case #%d: ",x)
#define prrn(x) printf("Case #%d:\n",x)
#define lowbit(x) (x&(-x))

const int maxn=1005;
struct TWO_SAT
{
    int pre[2*maxn],sccno[2*maxn],low[2*maxn];
    int sta[2*maxn],stac;
    int dfs_clock,scc_cnt,n;
    stack<int> s;
    vector<int> g[2*maxn],gg[2*maxn];//gg for topsort
    bool mark[2*maxn];//solve for all
    int col[2*maxn],du[2*maxn];//solve for topsort
    queue<int> q;//solve for topsort

    void init(int x)
    {
        n=x;stac=0;
        for(int i=0;i<=2*n;i++)g[i].clear(),mark[i]=false,sta[i]=0;
    }
    
    void add1(int x,int xx,int y,int yy)//x,y && 0 for i , 1 for opposite
    {
        xx--;yy--;
        g[2*x+xx].pb(2*y+yy);
    }
    
    void add2(int x,int y)
    {
        g[x].pb(y);
    }

    void SCC(int u)
    {
        pre[u]=low[u]=++dfs_clock;
        s.push(u);
        for(auto v : g[u])
        {
            if(!pre[v])
            {
                SCC(v);
                low[u]=min(low[u],low[v]);
            }else if(!sccno[v])low[u]=min(low[u],pre[v]);
        }
        if(low[u]==pre[u])
        {
            scc_cnt++;
            for(;;)
            {
                int x=s.top();s.pop();
                sccno[x]=scc_cnt;
                if(x==u)break;
            }
        }
    }

    void tarjan()
    {
        dfs_clock=scc_cnt=0;
        for(int i=1;i<=2*n;i++)sccno[i]=pre[i]=low[i]=0;
        while(!s.empty())s.pop();
        for(int i=1;i<=2*n;i++)if(!pre[i])SCC(i);
    }

    bool judge()
    {
        tarjan();
        for(int i=1;i<=n;i++)
            if(sccno[i<<1]==sccno[(i<<1)-1])return false;
        return true;
    }

    bool dfs(int x)
    {
        int k=(x%2==0)?x-1:x+1;
        if(mark[k])return false;
        if(mark[x])return true;
        mark[x]=true;
        sta[stac++]=x;
        for(auto p : g[x])if(!dfs(p))return false;
        return true;
    }

    bool solve1()//DFS,can replace judge,can solve dictionary-min
    {
        for(int i=1;i<=n;i++)
        {
            int k=2*i-1;
            stac=0;
            if(!dfs(k))
            {
                while(stac>0)mark[sta[--stac]]=false;
                if(!dfs(k+1))return false;
            }
        }
        return true;
    }

    void solve2()//topsort , must after judge!!! 
    {
        int conf[scc_cnt+5];
        for(int i=1;i<=scc_cnt;i++)col[i]=du[i]=0,conf[i]=0;
        for(int i=1;i<=scc_cnt;i++)gg[i].clear();
        for(int i=1;i<=2*n;i++)
        {
            int k=sccno[i];
            int j=sccno[(i%2==0)?i-1:i+1];
            conf[j]=k;
            for(auto p : g[i])
            {
                int t=sccno[p];
                if(t==k)continue;
                gg[t].pb(k);
                du[k]++;
            }
        }
        while(!q.empty())q.pop();
        for(int i=1;i<=scc_cnt;i++)
            if(du[i]==0)q.push(i);
        int tot=0;
        while(tot<scc_cnt)
        {
            int x=q.front();q.pop();tot++;
            if(!col[x])
            {
                col[x]=1;
                col[conf[x]]=2;
            }
            for(auto p : gg[x])
            {
                du[p]--;
                if(du[p]==0)q.push(p);
            }
        }
        for(int i=1;i<=n;i++)
            if(col[sccno[2*i-1]]==1)mark[2*i-1]=true;else mark[2*i]=true;
    }
}ts;

int m,l;
string rec[1005][2];
string s1,s2,n1,n2;
map<string,int> mp;
vector<int> pp[2005];

int main()
{
    cin>>m;l=0;
    for(int i=1;i<=m;i++)
    {
        cin>>s1>>s2;
        n1="";n1+=s1[0];n1+=s1[1];
        n2=n1;n1+=s1[2];n2+=s2[0];
        if(mp[n1]==0)mp[n1]=++l;
        if(mp[n2]==0)mp[n2]=++l;
        pp[mp[n1]].pb(2*i-1);
        pp[mp[n2]].pb(2*i);
        rec[i][0]=n1;rec[i][1]=n2;
        /*cout<<s1<<' '<<s2<<endl;
        cout<<n1<<' '<<n2<<endl;*/
    }
    ts.init(m);
    for(int i=1;i<=l;i++)
    {
        int l=0,r=0;
        for(auto p : pp[i])
            if(p&1)l++;else r++;
        for(auto p : pp[i])
        {
            if(l>1 && p&1)ts.add2(p,(p%2==0)?p-1:p+1);
            if(r>1 && p%2==0)ts.add2(p,(p%2==0)?p-1:p+1);
        }
        for(auto p : pp[i])
            for(auto q : pp[i])
                if(p!=q)ts.add2(p,(q%2==0)?q-1:q+1);
    }
    if(!ts.judge()){printf("NO");return 0;}
    ts.solve2();
    printf("YES\n");
    for(int i=1;i<=m;i++)
        if(ts.mark[2*i-1])cout<<rec[i][0]<<endl;else cout<<rec[i][1]<<endl;
    return 0;
}