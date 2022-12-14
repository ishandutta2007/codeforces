#include<bits/stdc++.h>
using namespace std;
int n,m,tp,x,y,pa[55555],a[55555],sub[55555],q;
vector<int> g[55555];
long long ans;
char opt[11];
struct LCT
{
	int ch[333333][2],f[333333],st[333333];
	int a[333333],p[333333],sub[333333],tag1[333333];
	long long sum[333333],sb[333333];
	bool isrt(int x)
	{
		if (!f[x]) return 1;
		return (ch[f[x]][0]!=x && ch[f[x]][1]!=x);
	}
	int get(int x)
	{
		return (ch[f[x]][1]==x);
	}
	void pushup(int x)
	{
		sum[x]=sum[ch[x][0]]+sum[ch[x][1]]+1ll*a[x]*p[x];
		sub[x]=sub[ch[x][0]]+sub[ch[x][1]]+a[x];
	}
	void push1(int x,int y)
	{
		tag1[x]+=y;
		sb[x]+=(1ll*a[x]*y);
	}
	void pushdown(int x)
	{
		if (tag1[x])
		{
			push1(ch[x][0],tag1[x]);
			push1(ch[x][1],tag1[x]);
			tag1[x]=0;
		}
	}
	void rotate(int x)
	{
		int fa=f[x],gfa=f[fa];
		int wh=get(x);
		ch[fa][wh]=ch[x][wh^1];
		f[ch[x][wh^1]]=fa;
		ch[x][wh^1]=fa;
		if (!isrt(fa)) ch[gfa][ch[gfa][1]==fa]=x;
		f[fa]=x;
		f[x]=gfa;
		pushup(fa);
	}
	void splay(int x)
	{
		int y=x,z=0;
		st[++z]=y;
		while(!isrt(y))
		{
			y=f[y];
			st[++z]=y;
		}
		while(z) pushdown(st[z--]);
		for (int fa;(fa=f[x]) && !isrt(x);rotate(x))
		{
			if (!isrt(fa))
			{
				if (get(fa)==get(x)) rotate(fa);
				else rotate(x);
			}
		}
		pushup(x);
	}
	void access(int x)
	{
		for (int y=0;x;y=x,x=f[x])
		{
			splay(x);
			a[x]+=sub[ch[x][1]];a[x]-=sub[y];
			ch[x][1]=y;
			pushup(x);
		}
	}
	int findroot(int x)
	{
		access(x);
		splay(x);
		int pos=x;
		while(ch[pos][0])
		{
			pushdown(pos);
			pos=ch[pos][0];
		}
		splay(pos);
		return pos;
	}
	void fuckit(int x,int y)//pa[x]=y
	{
		access(x);access(pa[x]);
		int ss=sub[x];splay(pa[x]);
		a[pa[x]]-=ss;pushup(pa[x]);
		ans-=(2ll*sum[pa[x]]*ss);	
		push1(pa[x],-2*ss);
		access(y);f[x]=pa[x]=y;
		splay(y);
		ans+=(2ll*sum[y]*ss);
		push1(y,2*ss);
		a[y]+=ss;pushup(y);
	}
	void perform(int x,int y)
	{
		if (x==1) fuckit(y,x);
		else
		{
			access(x);access(pa[x]);f[x]=0;int ss=sub[x];
			splay(pa[x]);a[pa[x]]-=ss;pushup(pa[x]);
			if (findroot(y)==x) 
			{
				access(pa[x]);
				f[x]=pa[x];splay(pa[x]);
				a[pa[x]]+=ss;pushup(pa[x]);
				fuckit(y,x);
			}
			else
			{
				access(pa[x]);
				f[x]=pa[x];splay(pa[x]);
				a[pa[x]]+=ss;pushup(pa[x]);
				fuckit(x,y);
			}
		}
	}
	void upd(int x,int y)
	{
		splay(x);
		p[x]+=y;
		pushup(x);
		ans+=(1ll*y*sb[x]);
	}
}lct;
void dfs(int i)
{
	sub[i]=1;
	for (int j=0;j<g[i].size();j++)
	{
		int to=g[i][j];
		dfs(to);
		sub[i]+=sub[to];
	}
}
void Out()
{
	double x=(double)ans/(double)n/(double)n;
	printf("%.9lf\n",x);
}
int main()
{
	scanf("%d",&n);
	for (int i=2;i<=n;i++) scanf("%d",&pa[i]);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=2;i<=n;i++) 
	{
		g[pa[i]].push_back(i);
	}
	dfs(1);
	for (int i=1;i<=n;i++)
	{
		ans+=(1ll*sub[i]*sub[i]*a[i]);
		lct.sb[i]+=(1ll*sub[i]*sub[i]);
		for (int j=0;j<g[i].size();j++)
		{
			int to=g[i][j];
			ans-=(1ll*sub[to]*sub[to]*a[i]);
			lct.sb[i]-=(1ll*sub[to]*sub[to]);
		}
	}
	for (int i=1;i<=n;i++)
	{
		lct.a[i]=lct.sub[i]=sub[i];lct.p[i]=a[i];
		lct.sum[i]=1ll*lct.a[i]*lct.p[i];
	} 
	for (int i=2;i<=n;i++) lct.f[i]=pa[i];
	Out();
	scanf("%d",&q);
	for (int i=1;i<=q;i++)
	{
		scanf("%s",opt);
		if (opt[0]=='P')
		{
			scanf("%d%d",&x,&y);
			lct.perform(x,y);
		}
		else
		{
			scanf("%d%d",&x,&y);
			lct.upd(x,y-a[x]);
			a[x]=y;
		}
		Out();
	}
	return 0;
}