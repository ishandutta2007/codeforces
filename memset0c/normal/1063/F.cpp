#include<bits/stdc++.h>
#define maxn 1000010
#define maxm 4000010
#define ls (cur<<1)
#define rs (cur<<1|1)
#define mid ((l+r)>>1)
using namespace std;
template<typename T> inline void read(T &x)
{
    x=0;char c=getchar();bool flag=false;
    while(!isdigit(c)){if(c=='-')flag=true;c=getchar();}
    while(isdigit(c)){x=(x<<1)+(x<<3)+(c^48);c=getchar();}
    if(flag)x=-x;
}
int n,ans,tot=1,las=1,root=1,cnt,pos;
int fa[maxn],len[maxn],ch[maxn][26],bel[maxn],dp[maxn];
int in[maxn],out[maxn],f[maxn][22],mx[maxm];
char s[maxn];
struct edge
{
    int to,nxt;
}e[maxn];
int head[maxn],edge_cnt;
void add(int from,int to)
{
    e[++edge_cnt]={to,head[from]},head[from]=edge_cnt;
}
void modify(int l,int r,int pos,int v,int cur)
{
    if(l==r)
    {
        mx[cur]=v;
        return;
    }
    if(pos<=mid) modify(l,mid,pos,v,ls);
    else modify(mid+1,r,pos,v,rs);
    mx[cur]=max(mx[ls],mx[rs]);
}
int query(int L,int R,int l,int r,int cur)
{
    if(!L||!R) return 0;
    if(L<=l&&R>=r) return mx[cur];
    int v=0;
    if(L<=mid) v=max(v,query(L,R,l,mid,ls));
    if(R>mid) v=max(v,query(L,R,mid+1,r,rs));
    return v;
}
void insert(int c,int id)
{
    int p=las,np=las=++tot;
    len[np]=len[p]+1,bel[id]=np;
    while(p&&!ch[p][c]) ch[p][c]=np,p=fa[p];
    if(!p) fa[np]=root;
    else
    {
        int q=ch[p][c];
        if(len[q]==len[p]+1) fa[np]=q;
        else
        {
            int nq=++tot;
            memcpy(ch[nq],ch[q],sizeof(ch[q]));
            len[nq]=len[p]+1,fa[nq]=fa[q],fa[np]=fa[q]=nq;
            while(ch[p][c]==q) ch[p][c]=nq,p=fa[p];
        }
    }
}
void dfs(int x)
{
    in[x]=++cnt,f[x][0]=fa[x];
    for(int i=1;i<=20;++i) f[x][i]=f[f[x][i-1]][i-1];
    for(int i=head[x];i;i=e[i].nxt) dfs(e[i].to);
    out[x]=cnt;
}
int get(int x,int lenth)
{
    x=bel[x];
    for(int i=20;i>=0;--i)
        if(f[x][i]&&len[f[x][i]]>=lenth)
            x=f[x][i];
    return x;
}
bool check(int p)
{
    int x=get(p,dp[p]-1),y=get(p-1,dp[p]-1);
    return max(query(in[x],out[x],1,tot,root),query(in[y],out[y],1,tot,root))>=dp[p]-1;
}
int main()
{
    read(n),scanf("%s",s+1),reverse(s+1,s+n+1);
    for(int i=1;i<=n;++i) insert(s[i]-'a',i);
    for(int i=2;i<=tot;++i) add(fa[i],i);
    dfs(root);
    for(int i=1;i<=n;++i)
    {
        dp[i]=dp[i-1]+1;
        while(!check(i))
            dp[i]--,pos++,modify(1,tot,in[bel[pos]],dp[pos],root);
        ans=max(ans,dp[i]);
    }
    printf("%d",ans);
    return 0;
}