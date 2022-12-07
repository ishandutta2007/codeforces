#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#define next next2
using namespace std;
const int MAXN=200010;
typedef long long LL;
int n,Q;
bool ok,isKey[MAXN];
int anc[MAXN][20],Log[MAXN],dfn[MAXN],dep[MAXN],L[MAXN],R[MAXN],dfs_clock;
int ans;
vector<int> v;
struct Tree
{
    int head[MAXN],to[MAXN],next[MAXN],cnt;
    void init(int n)
    {
        for(int i=1;i<=n;i++)
            head[i]=0;
        cnt=1;
    }
    inline void adde(int f,int t)
    {
        cnt++,to[cnt]=t,next[cnt]=head[f],head[f]=cnt;
        cnt++,to[cnt]=f,next[cnt]=head[t],head[t]=cnt;
    }
    void DFS(int x)
    {
        dfn[x]=++dfs_clock,L[x]=dfs_clock;
        for(int i=head[x];i;i=next[i])
            if(to[i]!=anc[x][0])
            {
                dep[to[i]]=dep[x]+1;
                anc[to[i]][0]=x;
                DFS(to[i]);
            }
        R[x]=dfs_clock;    
    }
    int dfs(int x,int fa)
    {
        int o=0;
        for(int i=head[x];i;i=next[i])
            if(to[i]!=fa) o+=dfs(to[i],x);
        if(isKey[x]) {ans+=o;return 1;}
        else if(o<=1) return o;
        else {ans++;return 0;}
    }
}T,T2;
int LCA(int p,int q)
{
    if(dep[p]<dep[q]) swap(p,q);
    int d=dep[p]-dep[q];
    for(int i=Log[d];i>=0;i--)
        if(d&(1<<i)) p=anc[p][i];
    for(int i=Log[n];i>=0;i--)
        if(anc[p][i]!=anc[q][i]) p=anc[p][i],q=anc[q][i];
    if(p!=q) return anc[p][0];
    else return p;
}
bool cmp_by_dfn(int i,int j)
{
    return dfn[i]<dfn[j];
}
int S[MAXN],top;
int main()
{
    scanf("%d",&n);
    T.init(n);
    for(int i=1,x,y;i<n;i++)
        scanf("%d%d",&x,&y),T.adde(x,y);
    T.DFS(1);
    Log[0]=-1;
    for(int i=1;i<=n;i++) Log[i]=Log[i>>1]+1;
    for(int i=1;i<=Log[n];i++)
        for(int j=1;j<=n;j++)
            anc[j][i]=anc[anc[j][i-1]][i-1];
    scanf("%d",&Q);
    while(Q--)
    {
        int k,x;
        ans=0;
        scanf("%d",&k);
        v.clear();
        for(int i=1;i<=k;i++)
            scanf("%d",&x),v.push_back(x),isKey[x]=true;
        sort(v.begin(),v.end(),cmp_by_dfn);
        for(int i=0;i<k-1;i++) v.push_back(LCA(v[i],v[i+1]));
        sort(v.begin(),v.end(),cmp_by_dfn);
        v.erase(unique(v.begin(),v.end()),v.end());
        int len=v.size();
        for(int i=0;i<len;i++) T2.head[v[i]]=0;
        T2.cnt=1;
        ok=true;
        for(int i=0;i<len;i++)
        {
            while(top>0&&(L[v[i]]>R[S[top]]||L[v[i]]<L[S[top]])) top--;
            if(top>0)
            {
                T2.adde(S[top],v[i]);
                if(isKey[S[top]]&&isKey[v[i]])
                {
                    int x=S[top],y=v[i];
                    if(dep[y]-dep[x]==1) ok=false;
                }
            }
            S[++top]=v[i];
        }
        if(ok) T2.dfs(v[0],-1);
        if(!ok) puts("-1");
        else printf("%d\n",ans);
        top=0;
        for(int i=0;i<len;i++)
            isKey[v[i]]=false;
    }
    return 0;
}