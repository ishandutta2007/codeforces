
/*****************************************
Author: lizi
Email: lzy960601@outlook.com
*****************************************/
  
#include<bits/stdc++.h>
  
using namespace std;
  
const double eps=1e-10;
const double pi=3.1415926535897932384626433832795;
const double eln=2.718281828459045235360287471352;
  
#define LL long long
#define IN freopen("in.txt", "r", stdin)
#define OUT freopen("out.txt", "w", stdout)
#define scan(x) scanf("%d", &x)
#define mp make_pair
#define pb push_back
#define sqr(x) (x) * (x)
#define pr(x) printf("Case %d: ",x)
#define prn(x) printf("Case %d:\n",x)
#define prr(x) printf("Case #%d: ",x)
#define prrn(x) printf("Case #%d:\n",x)
#define lowbit(x) (x&(-x))
#define fi first
#define se second
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int maxn=100005;

struct TWO_SAT //2*i-1 && 2*i
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

    void add(int x,int xx,int y,int yy)//x,y && 0 for i , 1 for opposite
    {
        x++;y++;
        //printf("%d:%d %d:%d\n",x,xx,y,yy);
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


vi men,food;
int le[maxn][2],ri[maxn][2];
//0-left,1-right

bool check(int tim)
{
    ts.init((int)food.size());
    int l=0,r=0,now=1;
    while(l<food.size())
    {
        r=l;
        while(r<food.size() && food[r]<men[now])r++;
        r--;
        if(l>r)
        {
            le[now][0]=ri[now-1][0]=-1;
            now++;
            continue;
        }
        for(int i=l;i<r;i++)
            ts.add(i,1,i+1,1);
        for(int i=r;i>l;i--)
            ts.add(i,0,i-1,0);
        le[now][0]=l;le[now][1]=r;
        ri[now-1][0]=l;ri[now-1][1]=r;
        l=r+1;now++;
    }
    ri[now-1][0]=-1;
    for(int i=now;i+1<men.size();i++)
        le[i][0]=ri[i][0]=-1;
    if(le[1][0]>=0)
        for(int i=le[1][0];i<=le[1][1];i++)
            ts.add(i,0,i,1);
    now=men.size();now-=2;
    if(ri[now][0]>=0)
        for(int i=ri[now][0];i<=ri[now][1];i++)
            ts.add(i,1,i,0);
    for(int i=1;i+1<men.size();i++)
    {
        l=le[i][0],r=ri[i][0];
        if(l>=0)
            for(int j=le[i][0];j<=le[i][1];j++)
                if(abs(men[i]-food[j])>tim)
                    ts.add(j,1,j,0);
        if(r>=0)
            for(int j=ri[i][0];j<=ri[i][1];j++)
                if(abs(men[i]-food[j])>tim)
                    ts.add(j,0,j,1);
        if(l<0 || r<0)continue;
        while(l<=le[i][1])
        {
            int dis=abs(men[i]-food[l]);
            if(dis<=tim)
            {
                int lt=max((tim-dis)>>1,tim-2*dis);
                while(r<=ri[i][0] && abs(men[i]-food[r])<=lt)r++;
                if(r<=ri[i][0])ts.add(l,1,r,1),ts.add(r,0,l,0);
            }
            l++;
        }

        l=le[i][1],r=ri[i][1];
        while(r>=ri[i][0])
        {
            int dis=abs(men[i]-food[r]);
            if(dis<=tim)
            {
                int lt=max((tim-dis)>>1,tim-2*dis);
                while(l>=le[i][0] && abs(men[i]-food[l])<=lt)l--;
                if(l>=le[i][0])ts.add(r,0,l,0),ts.add(l,1,r,1);
            }
            r--;
        }
    }
    return ts.judge();
}

string s;
int len;

int main()
{
    cin>>len>>s;
    men.pb(-1);
    for(int i=0;i<len;i++)
    {
        if(s[i]=='P')men.pb(i);
        if(s[i]=='*')food.pb(i);
    }
    men.pb(len+1);
    int l=0,r=2*len;
    while(r-l>1)
    {
        int mid=(l+r)>>1;
        if(check(mid))r=mid;else l=mid;
    }
    if(!check(l))l++;
    //printf("%d\n",check(10));
    //ts.solve2();
    /*for(int i=1;i<=food.size();i++)
    {
        printf("%d : ",i);
        if(ts.mark[2*i-1])printf("left\n");else printf("right\n");
    }*/
    printf("%d\n",l);
    return 0;
}