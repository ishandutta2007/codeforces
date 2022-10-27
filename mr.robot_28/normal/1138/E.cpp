#include<cstdio>
#include<cctype>
#include<algorithm>
#define N 5000005
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)>(b)?(b):(a))
#define getid(a,b) ((a-1)*d+b+1)
 
using namespace std;
 
inline int read(){
    int x=0,f=1;
    char ch = getchar();
    for(;!isdigit(ch);ch=getchar())
        if(ch='-'){
            f=-1;
            printf("ch=%c\n",ch);
        }
    for(;isdigit(ch);ch=getchar()){
        x = x*10+ch-'0';
        return x*f;
    }
}
 
/*
4 5 3
3 1
1 2
2 4
4 1
2 3
011
110
111
001
*/
struct Graph{
    int head[N],nxt[N],to[N],En;
    inline void add_edge(int u,int v){//link 
        ++En;
        to[En] = v;
        nxt[En] = head[u];
        head[u] = En;
    }
}G1,G2;
int dfn[N],low[N],sk[N],bel[N],vis[N],siz[N],dp[N],TimeIndex,SCC,top;
char s[100001][51];
 
int tarjan(int u){
    dfn[u] = low[u] = ++TimeIndex;
    sk[++top] = u;
    vis[u] = 1;
 
    for(int i=G1.head[u];i;i=G1.nxt[i]){
        int v = G1.to[i];
        if(!dfn[v]){ //has not visited
            tarjan(v);// visit it 
            low[u] = MIN(low[u],low[v]);//
        }else if(vis[v])//has visited and in the stack
            low[u] = MIN(low[u],dfn[v]);
    }
 
    if(low[u]==dfn[u]){
        SCC++;
        do{
            vis[sk[top]] = 0;
            bel[sk[top]] = SCC; // color it
            top--;
        }while(sk[top+1]!=u);
    }
}
 
int dfs(int u){
    if(dp[u])
        return dp[u];
    int ans=0;
    for(int i=G2.head[u];i;i=G2.nxt[i]){
        int tmp = dfs(G2.to[i]);
        ans=MAX(ans,tmp);
    }
    dp[u] = siz[u]+ans;
    return dp[u];
}
 
int main(){
    int n,m,d;
    scanf("%d %d %d",&n,&m,&d);
    //printf("n=%d,m=%d,d=%d,tot=%d\n",n,m,d,tot);
    for(int i=1;i<=m;i++){
        int u,v;
        scanf("%d %d",&u,&v);
        for(int j=0;j<d;j++){
            G1.add_edge(getid(u,j),getid(v,(j+1)%d));
        }
    }
    
    for(int i=1;i<=n;i++)
        scanf("%s",s[i]);
 
    tarjan(1);//must begin from 1 
 
    for(int i=1;i<=n;i++){
        for(int j=0;j<d;j++){
            int x = getid(i,j);
            if(s[i][j]=='1' && vis[bel[x]]!=i){
                vis[bel[x]] = i;
                siz[bel[x]]++;
            }
 
            for(int k=G1.head[x];k;k=G1.nxt[k]){
                if(bel[x]!=bel[G1.to[k]])
                    G2.add_edge(bel[x],bel[G1.to[k]]);
            }
        }
    }
    
    printf("%d",dfs(bel[1]));
    return 0;
}