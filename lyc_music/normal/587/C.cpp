//~~
#include<bits/stdc++.h>
#define IOS ios::sync_with_stdio(false)
#define ll long long
#define mp make_pair
#define pa pair < int,int >
#define fi first
#define se second
#define inf 1e18
#define mod 998244353
//#define int ll
#define N 100005
using namespace std;
inline char gc(){static char buf[1000000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
priority_queue<int>st1[N][25],val[N];
int n,m,q;
int st[N][25];
int dep[N];
vector<int>G[N];
void ad(int x,int y)
{
	G[x].push_back(y);
}
void ins(int x,int y)
{
	val[x].push(y);
	while (val[x].size()>10) val[x].pop();
}
priority_queue<int> merge(priority_queue<int>x,priority_queue<int>y)
{
	// cout<<"meg "<<x.size()<<" "<<y.size()<<endl;
	while (!y.empty()) x.push(y.top()),y.pop();
	while (x.size()>10) x.pop();
	// cout<<"meg "<<x.size()<<endl;
	return x;
}
void dfs(int k,int fa)
{
	dep[k]=dep[fa]+1;
	st1[k][0]=val[k];
	st[k][0]=fa;
	for (int i=1;i<=20;i++)
		st1[k][i]=merge(st1[k][i-1],st1[st[k][i-1]][i-1]),st[k][i]=st[st[k][i-1]][i-1];
	for (auto u:G[k])
	{
		if (u==fa) continue;
		dfs(u,k);
	}
}
priority_queue<int>lca(int x,int y)
{
	if (dep[x]<dep[y]) swap(x,y);
	int X=x,Y=y;
	int totx=0,toty=0;
	priority_queue<int>res;
	for (int i=20;i>=0;i--)
		if (dep[st[x][i]]>=dep[y]) res=merge(res,st1[x][i]),x=st[x][i];
	if (x==y) 
	{
		res=merge(res,st1[x][0]);
		return res;
	}
	for (int i=20;i>=0;i--)
		if (st[x][i]!=st[y][i])  res=merge(res,st1[x][i]),res=merge(res,st1[y][i]),x=st[x][i],y=st[y][i];
	res=merge(res,st1[x][1]);
	res=merge(res,st1[y][0]);
	return res;
}
void BellaKira()
{
	n=read(),m=read(),q=read();
	for (int i=1;i<n;i++)
	{
		int x=read(),y=read();
		ad(x,y);
		ad(y,x);
	}
	for (int i=1;i<=m;i++)
	{
		int x=read();
		ins(x,i);
	}
	dfs(1,0);
	// if (m==100&&n==10) cout<<"?"<<val[3].top()<<endl;
	while (q--)
	{
		int x=read(),y=read(),w=read();
		priority_queue<int>Q=lca(x,y);
		writesp(min((int)Q.size(),w));
		vector<int>nowq;
		w=min((int)Q.size(),w);
		while (Q.size())
		{
			nowq.push_back(Q.top());
			Q.pop();
		}
		reverse(nowq.begin(),nowq.end());
		for (int i=0;i<w;i++) writesp(nowq[i]);
		puts("");
	}
}
signed main()
{
	int T=1;
	while (T--)
	{
		BellaKira();
	}
}
/*

*/