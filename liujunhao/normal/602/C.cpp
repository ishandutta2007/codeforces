#include<cstdio>
#include<algorithm>
#include<queue>
#include<cstring>
#define MAXN 400
using namespace std;
queue<int>q;
int n,m,dist[MAXN+10];
bool mat[MAXN+10][MAXN+10],vis[MAXN+10];
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
void spfa(bool f){
    memset(dist,0x7f,sizeof dist);
    q.push(1);
    dist[1]=0;
    vis[1]=0;
    int u,v;
    while(!q.empty()){
        u=q.front();
        q.pop();
        for(v=1;v<=n;v++)
            if(mat[u][v]==f)
                if(dist[v]>dist[u]+1){
                    dist[v]=dist[u]+1;
                    if(!vis[v]){
                        q.push(v);
                        vis[v]=1;
                    }
                }
    }
}
int main()
{
    int i;
    bool f;
    Read(n),Read(m);
    int u,v;
    for(i=1;i<=m;i++){
        Read(u),Read(v);
        mat[u][v]=mat[v][u]=1;
    }
    if(mat[1][n])
        f=0;
    else f=1;
    spfa(f);
    if(dist[n]==0x7f7f7f7f)
        puts("-1");
    else
        printf("%d\n",max(dist[n],1));
}