#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=10020;
long long p[N][1002],Ans=1ll<<60;
int n,m,g,r,s,e;
short qx[30000002],qy[30000002];
bool in[10002][1002];
int d[N],u,v,i,j,x,y,a,b;
void init(){
    scanf("%d%d",&n,&m);
    for(i=1;i<=m;i++)
        scanf("%d",d+i);
    sort(d+1,d+m+1);
    scanf("%d%d",&a,&b);
}
void work(){
    memset(p,0x3f,sizeof(p));
    d[0]=-(1<<30);
    d[m+1]=1<<30;
    p[1][0]=0;
    qx[0]=1;
    qy[0]=0;
    while(s<=e){
        u=qx[s];
        v=qy[s];
        in[u][v]=0;
        if(u==m)
            Ans=min(Ans,p[u][v]-(v==0?b:0));
        s++;
            x=u-1;
            y=(v+d[u]-d[u-1])%a;
        if(d[u]-d[u-1]<=a-v&&p[x][y]>p[u][v]+d[u]-d[u-1]+(v+d[u]-d[u-1]==a?b:0)){

            p[x][y]=p[u][v]+d[u]-d[u-1]+(v+d[u]-d[u-1]==a?b:0);
            if(!in[x][y]){
                in[x][y]=1;
                        e++;
            qx[e]=x;
            qy[e]=y;
            }
        }
                x=u+1;
            y=(v+d[u+1]-d[u])%a;
        if(d[u+1]-d[u]<=a-v&&p[x][y]>p[u][v]+d[u+1]-d[u]+(v+d[u+1]-d[u]==a?b:0)){

            p[x][y]=p[u][v]+d[u+1]-d[u]+(v+d[u+1]-d[u]==a?b:0);
            if(!in[x][y]){
                in[x][y]=1;
                        e++;
            qx[e]=x;
            qy[e]=y;
            }
        }        
    }
    printf("%lld",Ans<1ll<<55?Ans:-1);
}
int main(){
    init();
    work();
    return 0;
}