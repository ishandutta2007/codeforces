#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#define next next2
using namespace std;
const int MAXN=1000010;
int n,fa[MAXN],letter[MAXN],label[MAXN],dep[MAXN];
int head[MAXN],to[MAXN],next[MAXN],cnt=1;
int S[MAXN],L[MAXN],R[MAXN],size[MAXN],dfs_clock;
inline void adde(int f,int t)
{
    cnt++,to[cnt]=t,next[cnt]=head[f],head[f]=cnt;
    cnt++,to[cnt]=f,next[cnt]=head[t],head[t]=cnt;
}
void dfs_label(int x)
{
    size[x]=1;
    L[x]=++dfs_clock,S[L[x]]=x;
    for(int i=head[x];i;i=next[i])
        if(to[i]!=fa[x])
        {
            dep[to[i]]=dep[x]+1;
            label[to[i]]=label[x]^(1<<letter[to[i]]);
            dfs_label(to[i]);
            size[x]+=size[to[i]];
        }
    R[x]=dfs_clock;
}
int ans[MAXN],len[1<<22];
void DFS(int x,bool k)
{
    int heavy=0;
    for(int i=head[x];i;i=next[i])
        if(to[i]!=fa[x]&&size[to[i]]>size[heavy]) heavy=to[i];
    for(int i=head[x];i;i=next[i])
        if(to[i]!=fa[x]&&to[i]!=heavy) DFS(to[i],0);
    if(heavy) DFS(heavy,1);
    for(int i=head[x];i;i=next[i])
        if(to[i]!=fa[x]&&to[i]!=heavy)
        {
            for(int o=L[to[i]];o<=R[to[i]];o++)
            {
                for(int p=0;p<22;p++)
                    ans[x]=max(ans[x],len[label[S[o]]^(1<<p)]+dep[S[o]]-dep[x]*2);
                ans[x]=max(ans[x],len[label[S[o]]]+dep[S[o]]-dep[x]*2);
            }
            for(int o=L[to[i]];o<=R[to[i]];o++)
                len[label[S[o]]]=max(len[label[S[o]]],dep[S[o]]);
        }
    for(int p=0;p<22;p++) ans[x]=max(ans[x],len[label[x]^(1<<p)]-dep[x]);
    ans[x]=max(ans[x],len[label[x]]-dep[x]);
    len[label[x]]=max(len[label[x]],dep[x]);
    if(!k)
    {
        for(int o=L[x];o<=R[x];o++)
            len[label[S[o]]]=-100000000;
    }
}
void dfs_ans(int x)
{
    for(int i=head[x];i;i=next[i])
        if(to[i]!=fa[x])
        {
            dfs_ans(to[i]);
            ans[x]=max(ans[x],ans[to[i]]);
        }
}
int main()
{
    for(int i=0;i<(1<<22);i++) len[i]=-100000000;
    scanf("%d",&n);
    for(int i=2;i<=n;i++)
    {
        char str[10];
        scanf("%d%s",&fa[i],str);
        letter[i]=str[0]-'a';
        adde(i,fa[i]);
    }
    dfs_label(1);
    DFS(1,1);
    dfs_ans(1);
    for(int i=1;i<=n;i++)
        printf("%d ",ans[i]);
    return 0;
}