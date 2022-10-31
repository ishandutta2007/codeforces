#include<cstdio>
#include<algorithm>
using namespace std;
#define MAXN 100000
#define MAXM 200000
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
}edge[MAXM*2+10],*adj[MAXN+10],*ecnt=edge;
int lenth[MAXN+10],n,m;
long long ans;
inline void addedge(int u,int v){
    node *p=++ecnt;
    p->v=v;
    p->next=adj[u];
    adj[u]=p;
}
int main()
{
    int i;
    Read(n),Read(m);
    int u,v,cnt;
    for(i=1;i<=m;i++){
        Read(u),Read(v);
        addedge(v,u);
        addedge(u,v);
    }
    for(i=1;i<=n;i++){
        lenth[i]++;
        cnt=0;
        for(node *p=adj[i];p;p=p->next){
            if(p->v>i)
                lenth[p->v]=max(lenth[i],lenth[p->v]);
            cnt++;
        }
        ans=max(1ll*lenth[i]*cnt,ans);
    }
    printf("%I64d\n",ans);
}