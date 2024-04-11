#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<vector>
#include<math.h>
#include<stdlib.h>
using namespace std;

const int MX = (1<<19);
const int EX = MX;
int T1[2*MX+5],T0[2*MX+5];
int st[500050],en[1000010],next[1000010];
int c_edge;
int N;
int List[MX],c_L;
int prev[MX];
bool check[MX];

void addedge(int s,int d)
{
    c_edge++;
    next[c_edge]=st[s];
    st[s]=c_edge;
    en[c_edge]=d;
}

void dfs(int x)
{
    check[x]=1;
    prev[x]=c_L;
    int i;
    for(i=st[x];i;i=next[i]){
        if(!check[en[i]])dfs(en[i]);
    }
    List[x]=c_L++;
}

void update1(int x,int y,int t)
{
    int x1=MX+x,y1=MX+y;
    while(x1<=y1){
        T1[x1]=t;
        T1[y1]=t;
        x1=(x1+1)>>1;
        y1=(y1-1)>>1;
    }
}

void update0(int x,int t)
{
    int x1=x+MX;
    while(x1){
        T0[x1]=t;
        x1>>=1;
    }
}

int read0(int x,int y)
{
    int x1=x+EX,y1=y+EX;
    int ret=0;
    while(x1<=y1){
        ret=max(ret,T0[x1]);
        ret=max(ret,T0[y1]);
        x1=(x1+1)>>1;
        y1=(y1-1)>>1;
    }
    return ret;
}

int read1(int x)
{
    int x1=x+EX,ret=0;
    while(x1){
        ret=max(ret,T1[x1]);
        x1>>=1;
    }
    return ret;
}

int main()
{
   // freopen("input.txt","r",stdin);
    scanf("%d",&N);
    int i;
    for(i=1;i<N;i++){
        int x,y;scanf("%d%d",&x,&y);
        addedge(x,y);addedge(y,x);
    }
    dfs(1);
    //for(i=1;i<=N;i++)printf("%d %d\n",prev[i],List[i]);
    int q;scanf("%d",&q);
    for(i=1;i<=q;i++){
        int x,y;scanf("%d%d",&x,&y);
        if(x==1){
            update1(prev[y],List[y],i);
        }
        else if(x==2){
            update0(List[y],i);
        }
        else{
            printf("%d\n",read0(prev[y],List[y])<read1(List[y]));
        }
    }
    return 0;
}