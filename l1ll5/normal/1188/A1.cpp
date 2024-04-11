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
struct zgz
{
    int next,to;
}edge[N<<1];
int head[N],cnt=1;
void add(int from,int to)
{
    edge[cnt].to=to;
    edge[cnt].next=head[from];
    head[from]=cnt++;
}
int n,m;
int deg[N],ans;
int main()
{
    n=read();
    for(int i=1;i<n;i++)
    {
        int x=read(),y=read();
        add(x,y),add(y,x);
        deg[x]++,deg[y]++;
    }
    for(int i=1;i<=n;i++)
    if(deg[i]==2)ans++;
    if(ans)
    {
        puts("NO");
    }
    else puts("YES");
}