#include<cstdio>
#define MAXN 100000
int n,m,ans;
bool f[MAXN+10];
void Read(int &x){
    char c;
    while(c=getchar(),c!=EOF)
        if(c>='0'&&c<='9'){
            x=c-'0';
            while(c=getchar(),c>='0'&&c<='9')
                x=x*10+c-'0';
            ungetc(c,stdin);
            return;
        }
}
struct node{
    int v;
    node *next;
}*adj[MAXN+10],edge[MAXN*2+10],*ecnt=edge;
void addedge(int u,int v){
    node *p=++ecnt;
    p->v=v;
    p->next=adj[u];
    adj[u]=p;
}
void read(){
    int i,u,v;
    Read(n),Read(m);
    for(i=1;i<=n;i++){
        Read(u);
        if(u)
            f[i]=1;
    }
    for(i=1;i<n;i++){
        Read(u),Read(v);
        addedge(u,v);
        addedge(v,u);
    }
}
void dfs(int u,int fa,int cnt){
    if(f[u])
        cnt++;
    else
        cnt=0;
    if(cnt>m)
        return;
    bool f=0;
    for(node *p=adj[u];p;p=p->next)
        if(p->v!=fa)
            dfs(p->v,u,cnt),f=1;
    if(!f)
        ans++;
}
int main()
{
    read();
    dfs(1,0,0);
    printf("%d",ans);
}