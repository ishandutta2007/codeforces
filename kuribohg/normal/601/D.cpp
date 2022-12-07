#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<set>
using namespace std;
const int MAXN=300010;
int n,c[MAXN];
char s[MAXN];
int head[MAXN],to[MAXN<<1],next[MAXN<<1],cnt=1;
inline void adde(int f,int t)
{
    cnt++,to[cnt]=t,next[cnt]=head[f],head[f]=cnt;
    cnt++,to[cnt]=f,next[cnt]=head[t],head[t]=cnt;
}
struct Trie
{
    int ch[26];
}T[MAXN];
int id[MAXN],tot;
void dfs(int x,int fa)
{
    if(!T[id[fa]].ch[s[x]-'a']) T[id[fa]].ch[s[x]-'a']=++tot;
    id[x]=T[id[fa]].ch[s[x]-'a'];
    for(int i=head[x];i;i=next[i])
        if(to[i]!=fa) dfs(to[i],x);
}
int p[MAXN],ans[MAXN];
set<int> S[MAXN];
void DFS(int x,int fa)
{
    for(int i=head[x];i;i=next[i])
        if(to[i]!=fa)
        {
            DFS(to[i],x);
            if(S[p[x]].size()<S[p[to[i]]].size()) swap(p[x],p[to[i]]);
            for(set<int>::iterator it=S[p[to[i]]].begin();it!=S[p[to[i]]].end();++it)
                S[p[x]].insert(*it);
            S[p[to[i]]].clear();
        }
    ans[x]=(int)S[p[x]].size();
}
int ans1,ans2;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&c[i]);
    scanf("%s",s+1);
    for(int i=1,x,y;i<n;i++) scanf("%d%d",&x,&y),adde(x,y);
    id[0]=1,tot=1;
    dfs(1,0);
    for(int i=1;i<=n;i++) p[i]=i,S[i].insert(id[i]);
    DFS(1,0);
    for(int i=1;i<=n;i++)
        if(ans[i]+c[i]>ans1) ans1=ans[i]+c[i],ans2=1;
        else if(ans[i]+c[i]==ans1) ans2++;
    printf("%d\n%d\n",ans1,ans2);
    return 0;
}