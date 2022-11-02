#include<bits/stdc++.h>
using namespace std;
//static char buf[1000000],*p1=buf,*p2=buf;
//#define getchar() p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++
#define pi pair<int,int>
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define ls (rt<<1)
#define rs (rt<<1|1)
#define mid (l+r>>1)
#define lowbit (x&-x)
#define int long long
const int maxn=2e5+5,M=34005,mod=998244353;
inline int read()
{
	char ch=getchar();bool f=0;int x=0;
	for(;!isdigit(ch);ch=getchar())if(ch=='-')f=1;
	for(;isdigit(ch);ch=getchar())x=(x<<1)+(x<<3)+(ch^48);
	if(f==1)x=-x;return x;
}
inline void print(int x)
{
    static int a[55];int top=0;
    if(x<0) putchar('-'),x=-x;
    do{a[top++]=x%10,x/=10;}while(x);
    while(top) putchar(a[--top]+48);
}
int n,m,T,id,x,y;
int a,b,s[maxn],sum[maxn],st[maxn],pri[maxn],v[maxn],ans=0;
struct node{int v,x,y;};
vector<node>e[maxn];
int Pow(int x,int y){int res=1;while(y){if(y&1)res=res*x%mod;x=x*x%mod;y=y/2;}return res;}
void add(int x,int num){//cout<<x<<endl;
while(x>1)s[pri[x]]+=num,x/=pri[x];}
void get(int x){while(x>1)sum[pri[x]]=max(sum[pri[x]],-s[pri[x]]),x/=pri[x];}
void dfs(int g,int fa)
{
	//cout<<g<<" "<<fa<<endl;
	for(auto i:e[g])
	{
		int v=i.v,x=i.x,y=i.y;
		if(v==fa)continue;
		//cout<<v<<" "<<fa<<endl;
		//return ;
		add(x,1);add(y,-1);//return ;
		get(y);//return ;
		dfs(v,g);add(x,-1);add(y,1);
	}
}
void dfs2(int g,int fa)
{
	ans+=v[g];ans=ans%mod;
	for(auto j:e[g])
		if(j.v^fa)
		{
			int i=j.v,x=j.x,y=j.y;
			v[i]=v[g]*x%mod*Pow(y,mod-2)%mod;
			dfs2(i,g);
		}
}
void solve()
{
	n=read();ans=0;
	for(int i=1;i<=n;i++)e[i].clear(),s[i]=sum[i]=v[i]=0;
	//memset(v)
	for(int i=1;i<n;i++)
	{
		x=read(),y=read(),a=read(),b=read();
		e[x].pb((node){y,b,a}),e[y].pb((node){x,a,b});
	}
	dfs(1,0);v[1]=1;//return ;
	for(int i=1;i<=n;i++)if(sum[i])v[1]=v[1]*Pow(i,sum[i])%mod;
	//cout<<v[1]<<endl;
	dfs2(1,0);
	cout<<ans<<endl;
}
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//cout<<Pow(2,5);return 0;
	for(int i=2;i<=2e5;i++)if(!pri[i])
		for(int j=i;j<=2e5;j+=i)pri[j]=i;
	T=read();
	while(T--)
	{
		solve();
	}
 	return 0;
}