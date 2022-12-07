#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=10000010;
const int INF=1000000000;
int n,k;
int head[MAXN],to[MAXN],next[MAXN],cnt=1;
bool danger[200010];
char L[100010],R[100010];
inline int Hash(int type,int i)
{
    if(type) return n+i+1;
    else return i+1;
}
inline void adde(int f,int t)
{
    if(danger[f]||danger[t]) return;
    cnt++,to[cnt]=t,next[cnt]=head[f],head[f]=cnt;
}
int dis[MAXN];
int q[MAXN],l,r;
void BFS()
{
    q[l=r=1]=1,dis[1]=0;
    while(l<=r)
    {
        int x=q[l++];
        for(int i=head[x];i;i=next[i])
            if(dis[to[i]]==INF)
            {
                dis[to[i]]=dis[x]+1;
                int h=to[i];
                if(h>n) h-=n;
                if(dis[to[i]]<h) q[++r]=to[i];
            }
    }
}
int main()
{
    scanf("%d%d%s%s",&n,&k,L,R);
    L[n]='-',R[n]='-',n++;
    for(int i=0;i<n;i++)
    {
        if(L[i]=='X') danger[Hash(0,i)]=true;
        if(R[i]=='X') danger[Hash(1,i)]=true;
    }
    for(int i=0;i<n-1;i++) adde(Hash(0,i),Hash(0,i+1)),adde(Hash(1,i),Hash(1,i+1));
    for(int i=1;i<n;i++) adde(Hash(0,i),Hash(0,i-1)),adde(Hash(1,i),Hash(1,i-1));
    for(int i=0;i<n-k;i++) adde(Hash(0,i),Hash(1,i+k)),adde(Hash(1,i),Hash(0,i+k));
    for(int i=n-k;i<n;i++) adde(Hash(0,i),Hash(1,n-1)),adde(Hash(1,i),Hash(0,n-1));
    for(int i=1;i<=n+n;i++) dis[i]=INF;
    BFS();
    int res=min(dis[n],dis[n+n]);
    if(res!=INF) puts("YES");
    else puts("NO");
    return 0;
}