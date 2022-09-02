#include<stdio.h>
#include<vector>
using namespace std;

vector <int> v1[300030],v2[300030];

int L[100010],V[100010],R[100010];
int N,ans;
int a,b;

struct tree{
    int x,w,c;
}T[1<<20];

void build(int rt,int s,int d)
{
    if(s==d){T[rt].w=s;return;}
    int m=(s+d)>>1;
    build(rt<<1,s,m);
    build(rt<<1|1,m+1,d);
    T[rt].w=T[rt<<1].w;
}

void pushdown(int rt)
{
    T[rt<<1].x+=T[rt].c;
    T[rt<<1|1].x+=T[rt].c;
    T[rt<<1].c+=T[rt].c;
    T[rt<<1|1].c+=T[rt].c;
    T[rt].c=0;
}

void update(int rt,int s,int d,int l,int r,int v)
{
    if(l<=s&&d<=r){
        T[rt].x+=v;
        T[rt].c+=v;
        return;
    }
    if(T[rt].c!=0)pushdown(rt);
    int m=(s+d)>>1;
    if(l<=m)update(rt<<1,s,m,l,r,v);
    if(r>m)update(rt<<1|1,m+1,d,l,r,v);
    if(T[rt<<1].x<T[rt<<1|1].x){
        T[rt].x=T[rt<<1|1].x;
        T[rt].w=T[rt<<1|1].w;
    }
    else{
        T[rt].x=T[rt<<1].x;
        T[rt].w=T[rt<<1].w;
    }
}

int main(){
    scanf("%d",&N);
    int i;
    for(i=0;i<N;i++){
        scanf("%d%d%d",L+i,V+i,R+i);
        v1[L[i]].push_back(i);
        v2[V[i]].push_back(i);
    }
    build(1,1,3e5);
    for(i=1;i<=3e5;i++){
        for(size_t j=0;j<v1[i].size();j++)update(1,1,3e5,V[v1[i][j]],R[v1[i][j]],1);
        if(ans<T[1].x)ans=T[1].x,a=i,b=T[1].w;
        for(size_t j=0;j<v2[i].size();j++)update(1,1,3e5,i,R[v2[i][j]],-1);
    }
    printf("%d\n",ans);
    for(i=0;i<N;i++){
        if(L[i]<=a&&a<=V[i]&&V[i]<=b&&b<=R[i])printf("%d ",i+1);
    }
    return 0;
}