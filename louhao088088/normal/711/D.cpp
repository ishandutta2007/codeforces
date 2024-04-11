#include<bits/stdc++.h>
using namespace std;
#define int long long
inline int read()
{
	char ch=getchar();int x=0;bool f=0;
	for(;!isdigit(ch);ch=getchar())if(ch=='-')f=1;
	for(;isdigit(ch);ch=getchar())x=(x<<1)+(x<<3)+(ch^48);
	if(f==1)x=-x;return x;
}
const int maxn=2e5+5;
int n,m,a[maxn],mod=1e9+7,head[maxn],x,vis[maxn],ans[maxn],tot=0,s[maxn],p=0,cnt=1,in[maxn];
struct edge{int v,nex;}e[maxn*2];
void add(int u,int v){e[++cnt].v=v,e[cnt].nex=head[u];head[u]=cnt;in[v]++;}
void topsort()
{
    queue<int>q;
	for(int i=1;i<=n;i++) 
      if(in[i]==1)q.push(i);
    while(!q.empty()) 
	{
        int u=q.front();q.pop();
        for (int i=head[u];i;i=e[i].nex)
		{
            int y=e[i].v;
            if(in[y]>1)
			{
                in[y]--;
                if(in[y]==1)q.push(y);
            }
        }
    }
}
void dfs(int x,int num)
{
	//cout<<x<<" "<<num<<endl;
	if(vis[x])return;vis[x]=num;
	for(int i=head[x];i;i=e[i].nex)dfs(e[i].v,num);
}
signed main()
{
	n=read();
	for(int i=1;i<=n;i++)x=read(),add(i,x),add(x,i);
	for(int i=1;i<=n;i++)
	if(!vis[i])tot++,dfs(i,tot);//cout<<tot<<endl;
	topsort();s[0]=1;p=0;
	for(int i=1;i<=n;i++)if(in[i]>=2)ans[vis[i]]++,p++;
	for(int i=1;i<=n;i++)s[i]=s[i-1]*2%mod;int ans1=1;
	for(int i=1;i<=tot;i++)ans1=ans1*(s[ans[i]]-2)%mod;//cout<<ans1<<endl;
	ans1=ans1*s[n-p]%mod;cout<<ans1<<endl;
	return 0;
}