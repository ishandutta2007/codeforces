#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
const int N=200002;
int n,m,i,j,k,a,b,c,sz[N],dfn[N],dep[N],fa[N],top[N],e[N],x[N],h[N],t[N],v[N],T,vis[N],tmp,st[N],Tp,ans,q,F[N];
vector<int>p[N];
void dfs1(int i){
    sz[i]=1;
    for(int j=0;j<p[i].size();j++)
        if(p[i][j]!=fa[i]){
            fa[p[i][j]]=i;
            dep[p[i][j]]=dep[i]+1;
            dfs1(p[i][j]);
            sz[i]+=sz[p[i][j]];
            if(sz[p[i][j]]>sz[e[i]])
                e[i]=p[i][j];
        }
}
void dfs2(int i){
    dfn[i]=++T;
    if(e[i]){
        top[e[i]]=top[i];
        dfs2(e[i]);
    }
    for(int j=0;j<p[i].size();j++)
        if(p[i][j]!=fa[i]&&p[i][j]!=e[i]){
            top[p[i][j]]=p[i][j];
            dfs2(p[i][j]);
        }
}
void init(){
    scanf("%d",&n);
    for(i=1;i<n;i++){
        scanf("%d%d",&a,&b);
        p[a].push_back(b);
        p[b].push_back(a);
    }
    dfs1(1);
    top[1]=1;
    dfs2(1);    
}
bool cmp(int x,int y){
    return dfn[x]<dfn[y];
}
int LCA(int a,int b){
    while(top[a]!=top[b]){
        if(dep[top[a]]>dep[top[b]])
            a=fa[top[a]];
        else
            b=fa[top[b]];
    }
    return dep[a]<dep[b]?a:b;
}
void add(int a,int b){
    t[++k]=h[a];h[a]=k;v[k]=b;
}
void dfs(int i){
	//printf("%d   ",i);
    int f=0;
    for(int j=h[i];j;j=t[j]){
        dfs(v[j]);
        if(vis[i]!=T&&vis[v[j]]==T)
            f++;
        if(vis[i]==T&&vis[v[j]]==T)
            ans++;
        
    }
    h[i]=0;
    ans+=f>1;
    if(f==1)
    vis[i]=T;
}
void work(){
    scanf("%d",&q);
    for(T=1;T<=q;T++){
        scanf("%d",&m);
        for(i=1;i<=m;i++)
            scanf("%d",x+i),vis[x[i]]=T;
        tmp=0;
        for(i=1;i<=m;i++)
            if(vis[fa[x[i]]]==T)
                tmp=1;
        if(tmp){
            printf("-1\n");
            continue;
        }
        sort(x+1,x+m+1,cmp);
        k=0;Tp=0;
        if(x[1]!=1)st[Tp=1]=1;
        for(i=1;i<=m;i++){
            a=x[i];
            if(!Tp)
                st[Tp=1]=a;
            else{
                c=LCA(a,st[Tp]);
                while(Tp>1&&dep[st[Tp-1]]>=dep[c]){
                    add(st[Tp-1],st[Tp]);
                    Tp--;
                }
                if(dep[c]<dep[st[Tp]])add(c,st[Tp--]);
                if(st[Tp]!=c)st[++Tp]=c;
                st[++Tp]=a;
            }
        }
        while(Tp>1)
            add(st[Tp-1],st[Tp]),Tp--;
        ans=0;
        dfs(1);
        printf("%d\n",ans);
    }
}
int main(){
    init();
    work(); 
}