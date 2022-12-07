#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#include<set>
#define next next2
using namespace std;
int gcd(int a,int b)
{
    if(b==0) return a;
    return gcd(b,a%b);
}
const int MAXN=400010;
int n,a[MAXN],f[MAXN],dep[MAXN],ans[MAXN],c[MAXN];
int head[MAXN],to[MAXN],next[MAXN],cnt=1;
vector<int> d[MAXN];
inline void adde(int f,int t)
{
    cnt++,to[cnt]=t,next[cnt]=head[f],head[f]=cnt;
    cnt++,to[cnt]=f,next[cnt]=head[t],head[t]=cnt;
}
void DFS(int x,int fa)
{
    f[x]=gcd(f[fa],a[x]);
    for(int i=0;i<d[x].size();i++)
        if(c[d[x][i]]>=dep[x]-1) ans[x]=max(ans[x],d[x][i]);
    for(int i=0;i<d[x].size();i++) c[d[x][i]]++;
    for(int i=head[x];i;i=next[i])
        if(to[i]!=fa)
        {
            dep[to[i]]=dep[x]+1;
            ans[to[i]]=max(ans[to[i]],f[x]);
            DFS(to[i],x);
        }
    for(int i=0;i<d[x].size();i++) c[d[x][i]]--;
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=1,x,y;i<n;i++) scanf("%d%d",&x,&y),adde(x,y);
    for(int i=1;i<=n;i++)
    {
        for(int k=1;k*k<=a[i];k++)
            if(a[i]%k==0)
            {
                d[i].push_back(k);
                if(a[i]!=k*k) d[i].push_back(a[i]/k);
            }
    }
    DFS(1,-1);
    ans[1]=a[1];
    for(int i=1;i<=n;i++) printf("%d ",ans[i]);
    return 0;
}