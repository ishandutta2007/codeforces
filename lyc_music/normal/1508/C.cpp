//QwQcOrZ yyds!!!
#include<bits/stdc++.h>
#define ll long long
#define foor(i,a,b) for (int i=(a);i<=(b);i++)
#define door(i,a,b) for (int i=(a);i>=(b);i--)
#define go(i,x) for (int i=head[x];i;i=e[i].nx)
#define IOS ios::sync_with_stdio(false)
#define mp make_pair
#define pb push_back
#define pa pair < int,int >
#define fi first
#define se second
#define re register
#define be begin()
#define en end()
#define sqr(x) ((x)*(x))
#define ret return puts("-1"),0;
#define put putchar('\n')
#define inf 1000000005
#define mod 998244353
#define int ll
#define N 200005
using namespace std;
inline char gc(){static char buf[1000000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int fa[N],col[N],vis[N],ans,s;
int sumtot;
int m,tot,bl;
int n;
set<int>S;
queue<int>q;
vector<int>G[N];
map<int,int>Mp[N];
struct node
{
	int u,v,w;
};
node E[N];
bool cmp(node x,node y)
{
	return x.w<y.w;
}
int gf(int x)
{
	if (x==fa[x]) return x;
	return fa[x]=gf(fa[x]);
}
void ad(int x,int y)
{
	fa[gf(x)]=gf(y);
	G[x].push_back(y);
}
int gcol(int x)
{
	if (col[x]==x) return x;
	return col[x]=gcol(col[x]);
}
bool dfs(int k,int fa)
{
//	cout<<k<<" "<<fa<<endl;
	if (vis[k]) return 1;
	vis[k]=1;
	bool res=0;
	for (auto u:G[k])
	{
		if (u==fa) continue;
		res|=dfs(u,k);
	}
	return res;
}
void work(int k)
{
	q.push(k);
	S.erase(k);
	vis[k]=1;
	while (!q.empty())
	{
		int u=q.front();
//		cout<<u<<endl;
		q.pop();
		auto it=S.begin();
		while (it!=S.end())
		{
			int v=(*it);
			it++;
			if (Mp[u][v]) continue;
			q.push(v);
			S.erase(v);
			vis[v]=1;
			fa[gf(u)]=gf(v);
		}
	}
}
signed main()
{
	n=read();m=read();
	for (int i=1;i<=n;i++) fa[i]=i;
	for (int i=1;i<=m;i++)
	{
		int u=read(),v=read(),w=read();
		s^=w;
		E[i]={u,v,w};
		Mp[u][v]=Mp[v][u]=1;
	}
	tot=n*(n-1)/2;
	tot-=m;
	for (int j=1;j<=n;j++) vis[j]=0;
	for (int i=1;i<=n;i++)
		S.insert(i);
	for (int i=1;i<=n;i++)
		if (!vis[i])
			work(i),sumtot++;
//			cout<<"!"<<i<<endl;
//	cout<<sumtot<<" "<<tot<<endl;
	if (n-sumtot!=tot) bl=1;
//	return 0;
	for (int i=1;i<=n;i++) col[i]=i;
	sort(E+1,E+m+1,cmp);
//	return 0;
	for (int i=1;i<=m;i++)
		if (gf(E[i].u)!=gf(E[i].v))
		{
			ans+=E[i].w;
			fa[fa[E[i].u]]=fa[E[i].v];
			col[gcol(E[i].u)]=gcol(E[i].v);
		}
	if (bl) writeln(ans);
	else
	{
		for (int i=1;i<=m;i++)
			if (gcol(E[i].u)!=gcol(E[i].v)) s=min(s,E[i].w);
		writeln(ans+s);
	}
}
/*
633 198000
566 15 145571249
488 19 986207091
116 230 576844532
253 420 532745372
556 460 500113498
413 99 84350884
151 514 229469513
74 612 381734256
467 334 64380164
104 274 624260528
353 39 1008001701
323 319 861442927
104 440 274373215
27 601 14694606
248 242 800015670
103 437 240622474
388 579 798259463
113 382 3326758
284 319 405903485
153 559 332786176
185 160 379433530
453 615 599757581
236 559 322359591
397 595 433952803
281 458 359087599
375 33 486988594
*/