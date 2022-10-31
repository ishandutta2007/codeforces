#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define MAXN 5000
int cnt[MAXN+10],f[MAXN+10][MAXN+10][2],n,d[MAXN+10];
struct node{
    int v;
    node *next;
}*adj[MAXN+10],edge[MAXN*2+10],*ecnt=edge;
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
void addedge(int u,int v){
    node *p=++ecnt;
    p->v=v;
    p->next=adj[u];
    adj[u]=p;
}
void dfs(int u,int fa){
    if(d[u]==1){
        cnt[u]=1;
        f[u][0][1]=f[u][1][0]=0;
        return;
    }
    int temp[MAXN+10][2],i,j,cu,cv;
    memset(temp,0xff,sizeof temp);
    f[u][0][0]=f[u][0][1]=0;
    for(node *p=adj[u];p;p=p->next){
        int v=p->v;
        if(v==fa)
            continue;
        dfs(v,u);
        for(i=0;i<=cnt[u];i++)
            for(j=0;j<=cnt[v];j++)
                for(cu=0;cu<2;cu++){
                    if(f[u][i][cu]==-1)
                        continue;
                    for(cv=0;cv<2;cv++){
                        if(f[v][j][cv]==-1)
                            continue;
                        if(temp[i+j][cu]==-1)
                            temp[i+j][cu]=f[u][i][cu]+f[v][j][cv]+(cv!=cu?1:0);
                        else
                            temp[i+j][cu]=min(temp[i+j][cu],f[u][i][cu]+f[v][j][cv]+(cv!=cu?1:0));
                    }

            }
        cnt[u]+=cnt[v];
        for(i=0;i<=cnt[u];i++){
            f[u][i][0]=temp[i][0];
            f[u][i][1]=temp[i][1];
            temp[i][1]=temp[i][0]=-1;
        }
    }
}
int main()
{
    memset(f,0xff,sizeof f);
    int i,u,v;
    Read(n);
    for(i=1;i<n;i++){
        Read(u),Read(v);
        addedge(u,v);
        addedge(v,u);
        d[u]++,d[v]++;
    }
    for(i=1;i<=n;i++)
        if(d[i]>1)
            break;
    dfs(i,-1);
    printf("%d\n",min(f[i][cnt[i]/2][0],f[i][cnt[i]/2][1]));
}