#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;
/*
#include <cmath>
#include <queue>
#include <cstdio>
#include <iomanip>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#define N 100000
#define ll long long
using namespace std;
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int main()
{

}
 */
 /*
 #include <cmath>
 #include <queue>
 #include <cstdio>
 #include <iomanip>
 #include <cstdlib>
 #include <cstring>
 #include <iostream>
 #include <algorithm>
 #define N 100000
 #define ll long long
 using namespace std;
 inline int read()
 {
     int x=0,f=1;char ch=getchar();
     while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
     while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
     return x*f;
 }
 int main()
 {

 }
  */
  /*
  #include <cmath>
  #include <queue>
  #include <cstdio>
  #include <iomanip>
  #include <cstdlib>
  #include <cstring>
  #include <iostream>
  #include <algorithm>
  #define N 100000
  #define ll long long
  using namespace std;
  inline int read()
  {
      int x=0,f=1;char ch=getchar();
      while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
      while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
      return x*f;
  }
  int main()
  {

  }
   */
const int MAXN = 300010;//
const int MAXM = 600010;//*2
char xB[1<<15],*xS=xB,*xT=xB;
#define getchar() (xS==xT&&(xT=(xS=xB)+fread(xB,1,1<<15,stdin),xS==xT)?0:*xS++)
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}


struct Edge
{
    int to,next;
    bool cut;//
    bool cong;
}edge[MAXM];
int head[MAXN],tot;
int Low[MAXN],DFN[MAXN],Stack[MAXN],vv[MAXN];//vv1~block
int Index,top;
int block;//
bool bbb[MAXN];
int bridge;//

void dd(int u,int v,bool pp)
{
    edge[tot].to = v;edge[tot].next = head[u];edge[tot].cut=false;
    edge[tot].cong = pp;
    head[u] = tot++;
}

void Tarjan(int u,int pre,bool ff)
{
    int v;
    Low[u] = DFN[u] = ++Index;
    Stack[top++] = u;
    bbb[u] = true;
    for(int i = head[u];i != -1;i = edge[i].next)
    {
        v = edge[i].to;
        if(v == pre && (!ff))continue;
        if( !DFN[v] )
        {
            Tarjan(v,u,edge[i].cong);
            if( Low[u] > Low[v] )Low[u] = Low[v];
            if(Low[v] > DFN[u])
            {
                bridge++;
                edge[i].cut = true;
                edge[i^1].cut = true;
            }
        }
        else if( bbb[v] && Low[u] > DFN[v] )
            Low[u] = DFN[v];
    }
    if(Low[u] == DFN[u])
    {
        block++;
        do
        {
            v = Stack[--top];
            bbb[v] = false;
            vv[v] = block;
        }
        while( v!=u );
    }
}
vector<int>vec[MAXN];
int dep[MAXN];
void dfs(int u)
{
    for(int i = 0;i < vec[u].size();i++)
    {
        int v = vec[u][i];
        if(dep[v]!=-1)continue;
        dep[v]=dep[u]+1;
        dfs(v);
    }
}
void solve(int n)
{
    memset(DFN,0,sizeof(DFN));memset(bbb,false,sizeof(bbb));
    Index = top = block = 0;
    Tarjan(1,0,false);
    for(int i = 1;i <= block;i++)vec[i].clear();
    for(int i = 1;i <= n;i++)for(int j = head[i];j != -1;j = edge[j].next)
          if(edge[j].cut)
          {
              vec[vv[i]].push_back(vv[edge[j].to]);
          }
    memset(dep,-1,sizeof(dep));
    dep[1]=0;
    dfs(1);
    int k = 1;
    for(int i = 1;i <= block;i++)if(dep[i]>dep[k])
          k = i;
    memset(dep,-1,sizeof(dep));
    dep[k]=0;
    dfs(k);
    int ans = 0;
    for(int i = 1;i <= block;i++)
        ans = max(ans,dep[i]);
    printf("%d\n",ans);
}
struct NN
{
    int u,v;
}node[MAXM];
bool cmp(NN a,NN b)
{
    if(a.u != b.u)return a.u<b.u;
    else return a.v<b.v;
}
    int n,m;
void doit()
{
    for(int i = 0;i < m;i++)
    {
        int u=read(),v=read();
        if(u>v)swap(u,v);
        node[i].u = u,node[i].v = v;
    }
    sort(node,node+m,cmp);
    for(int i = 0;i < m;i++)

        if(i == 0 || (node[i].u!=node[i-1].u || node[i].v != node[i-1].v))
        {
            if(i < m-1 && (node[i].u==node[i+1].u && node[i].v == node[i+1].v))
            {
                dd(node[i].u,node[i].v,true);
                dd(node[i].v,node[i].u,true);
            }
            else
            {
                dd(node[i].u,node[i].v,false);
                dd(node[i].v,node[i].u,false);
            }
        }
}
int main()
{
    n=read(),m=read();
    memset(head,-1,sizeof(head));
doit();

        solve(n);
}