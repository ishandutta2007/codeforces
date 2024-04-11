#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+5;
struct edge{int v,nex;}e[maxn*2];
long long ans,s[maxn],n,x,k,u,v,cnt=0,head[maxn];
void add(int u,int v){e[++cnt].v=v,e[cnt].nex=head[u],head[u]=cnt;}
void dfs(int x,int fa) 
{
    for(int i=head[x];i;i=e[i].nex) 
	{
        int v=e[i].v;if(v==fa) continue;
        dfs(v,x),s[x]+=s[v],ans+=min(s[v],k-s[v]);//cout<<ans<<" "<<x<<" "<<fa<<endl;
    }
}
int main() 
{
    scanf("%lld%lld",&n,&k),k=k*2;
    for(int i=1;i<=k;i++)scanf("%lld",&x),s[x]=1;
    for(int i=1;i<n;i++)scanf("%lld%lld",&u,&v),add(u,v),add(v,u);
    dfs(1,1);printf("%lld",ans);
    return 0;
}