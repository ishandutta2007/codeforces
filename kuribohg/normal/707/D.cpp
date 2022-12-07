#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<bitset>
#define next next2
using namespace std;
const int MAXN=200010;
int n,m,Q,ver[MAXN];
struct Node
{
    int op,x,y;
    Node(){}
    Node(int _op,int _x,int _y):op(_op),x(_x),y(_y){}
}A[MAXN];
int head[MAXN],to[MAXN],next[MAXN],cnt=1;
inline void adde(int f,int t)
{
    cnt++,to[cnt]=t,next[cnt]=head[f],head[f]=cnt;
}
int ans[1010],sum,res[MAXN];
bitset<1001> B[1001];
void DFS(int x,int fa)
{
    bool flag=false;
    if(A[x].op==1)
    {
        sum-=ans[A[x].x];
        if(!B[A[x].x][A[x].y]) ans[A[x].x]++,flag=true;
        sum+=ans[A[x].x];
        B[A[x].x][A[x].y]=1;
    }
    else if(A[x].op==2)
    {
        sum-=ans[A[x].x];
        if(B[A[x].x][A[x].y]) ans[A[x].x]--,flag=true;
        sum+=ans[A[x].x];
        B[A[x].x][A[x].y]=0;
    }
    else if(A[x].op==3)
    {
        sum-=ans[A[x].x];
        ans[A[x].x]=m-ans[A[x].x];
        sum+=ans[A[x].x];
        B[A[x].x].flip();
    }
    res[x]=sum;
    for(int i=head[x];i;i=next[i])
        if(to[i]!=fa) DFS(to[i],x);
    if(A[x].op==2)
    {
        sum-=ans[A[x].x];
        if(flag) ans[A[x].x]++;
        sum+=ans[A[x].x];
        if(flag) B[A[x].x][A[x].y]=1;
    }
    else if(A[x].op==1)
    {
        sum-=ans[A[x].x];
        if(flag) ans[A[x].x]--;
        sum+=ans[A[x].x];
        if(flag) B[A[x].x][A[x].y]=0;
    }
    else if(A[x].op==3)
    {
        sum-=ans[A[x].x];
        ans[A[x].x]=m-ans[A[x].x];
        sum+=ans[A[x].x];
        B[A[x].x].flip();
    }
}
int main()
{
    scanf("%d%d%d",&n,&m,&Q);
    for(int i=1;i<=Q;i++)
    {
        int op=0,x=0,y=0;
        scanf("%d%d",&op,&x);
        if(op==1||op==2) scanf("%d",&y);
        A[i]=Node(op,x,y);
    }
    for(int i=1;i<=Q;i++)
    {
        if(A[i].op==4) adde(A[i].x,i);
        else adde(i-1,i);
    }
    DFS(0,-1);
    for(int i=1;i<=Q;i++) printf("%d\n",res[i]);
    return 0;
}