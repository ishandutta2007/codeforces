#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<vector>
#include<math.h>
#include<stdlib.h>
using namespace std;

const int MX = 100010;
int st[MX], en[2*MX], next[2*MX];
int V;
int k,d;
int p[MX];
int Q[MX];
bool check[MX];
bool inp[MX];
int dis[MX][2]; //0:for a, 1:for b;

void addedge(int s,int d,int c)
{
    next[c]=st[s];
    st[s]=c;
    en[c]=d;
}

int finder(int x)
{
    memset(check,0,sizeof(check));
    int fr=1,re=0;
    Q[0]=x;
    check[x]=1;
    int ret=x;
    while(fr!=re){
        int i;
        int tx=Q[re];
        for(i=st[tx];i;i=next[i]){
            if(check[en[i]])continue;
            check[en[i]]=1;
            Q[fr]=en[i];
            if(inp[en[i]])ret=en[i];
            fr++;
        }
        re++;
    }
    return ret;
}

void pre(int x,int t)
{
    memset(check,0,sizeof(check));
    int fr=1,re=0;
    Q[0]=x;
    check[x]=1;
    while(fr!=re){
        int tx=Q[re];
        int i;
        for(i=st[tx];i;i=next[i]){
            if(check[en[i]])continue;
            check[en[i]]=1;
            Q[fr]=en[i];
            dis[en[i]][t]=dis[tx][t]+1;
            fr++;
        }
        re++;
    }
}

int solve()
{
    int i,cnt=0;
    for(i=1;i<=V;i++){
        if(dis[i][0]<=d && dis[i][1]<=d)cnt++;
    }
    return cnt;
}

int main()
{
//  freopen("input.txt","r",stdin);
    scanf("%d%d%d",&V,&k,&d);
    int i;
    for(i=1;i<=k;i++){
        scanf("%d",p+i);
        inp[p[i]]=1;
    }
    for(i=1;i<V;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        addedge(x,y,2*i-1);
        addedge(y,x,2*i);
    }
    int a=finder(p[1]);
    int b=finder(a);
    pre(a,0);
    pre(b,1);
    printf("%d",solve());
    return 0;
}