#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long LL;
const int MAXN=100010;
struct Point
{
    LL x,y;
    Point(){}
    Point(LL _x,LL _y):x(_x),y(_y){}
    friend bool operator<(const Point &p,const Point &q)
    {
        return p.x==q.x?p.y>q.y:p.x<q.x;
    }
}P[MAXN];
typedef Point Vector;
Vector operator+(const Vector &p,const Vector &q){return Vector(p.x+q.x,p.y+q.y);}
Vector operator-(const Vector &p,const Vector &q){return Vector(p.x-q.x,p.y-q.y);}
LL Dot(const Vector &p,const Vector &q){return p.x*q.x+p.y*q.y;}
LL Cross(const Vector &p,const Vector &q){return p.x*q.y-p.y*q.x;}
int n,S[MAXN],top,anc[MAXN][20],Log[MAXN];
int head[MAXN],to[MAXN<<1],next[MAXN<<1],cnt=1,dep[MAXN];
inline void adde(int f,int t)
{
    cnt++,to[cnt]=t,next[cnt]=head[f],head[f]=cnt;
    cnt++,to[cnt]=f,next[cnt]=head[t],head[t]=cnt;
}
void DFS(int x,int fa)
{
    for(int i=head[x];i;i=next[i])
        if(to[i]!=fa) dep[to[i]]=dep[x]+1,DFS(to[i],x);
}
int LCA(int p,int q)
{
    if(dep[p]<dep[q]) swap(p,q);
    int d=dep[p]-dep[q];
    for(int i=Log[d];i>=0;i--)
        if(d&(1<<i)) p=anc[p][i];
    for(int i=Log[n];i>=0;i--)
        if(anc[p][i]!=anc[q][i]) p=anc[p][i],q=anc[q][i];
    if(p!=q) return anc[p][0];
    else return p;
}
int Q,x,y;
int main()
{
    ios::sync_with_stdio(false);
    cin>>n;
    Log[0]=-1;
    for(int i=1;i<=n;i++) Log[i]=Log[i>>1]+1;
    for(int i=1;i<=n;i++) cin>>P[i].x>>P[i].y;
    S[top=1]=n;
    for(int i=n-1;i>=1;i--)
    {
        while(top>1&&Cross(P[i]-P[S[top]],P[S[top]]-P[S[top-1]])>0) top--;
        anc[i][0]=S[top],adde(i,S[top]);
        S[++top]=i;
    }
    for(int i=1;i<=Log[n];i++)
        for(int j=1;j<=n;j++)
            anc[j][i]=anc[anc[j][i-1]][i-1];
    DFS(n,-1);
    cin>>Q;
    while(Q--)
    {
        cin>>x>>y;
        int lca=LCA(x,y);
        cout<<lca<<" ";
    }
    cout<<endl;
    return 0;
}