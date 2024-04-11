#include<bits/stdc++.h>
using namespace std;
struct LCT
{
	int ch[555555][2],f[555555],tag[555555],key[555555],sum[555555],st[555555],ls[555555],rs[555555];
	LCT()
	{
		for (int i=1;i<=550000;i++) 
		{
			sum[i]=ch[i][0]=ch[i][1]=f[i]=tag[i]=key[i]=0;
		}
	}
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
		sum[x]=key[x];
		sum[x]+=sum[ch[x][0]];
		sum[x]+=sum[ch[x][1]];
	}
	void push(int x)
	{
		tag[x]^=1;
		swap(ch[x][0],ch[x][1]);
	}
	void pushdown(int x)
	{
		if (tag[x])
		{
			push(ch[x][0]);
			push(ch[x][1]);
			tag[x]=0;
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
			ch[x][1]=y;
			pushup(x);
		}
	}
	void makeroot(int x)
	{
		access(x);
		splay(x);
		push(x);
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
	void split(int x,int y)
	{
		makeroot(x);
		access(y);
		splay(x);
	}
	void link(int x,int y)
	{
		makeroot(x);
		if (findroot(y)!=x) f[x]=y;
	}
	void cut(int x,int y)
	{
		makeroot(x);
		if (findroot(y)!=x || f[y]!=x || ch[y][0]) return;
		ch[x][1]=0;f[y]=0;
		pushup(x);
	}
}lct;
int n,pa[333333],x,y,deg[333333];
vector<int> g[333333];
queue<int> q;
void dfs(int i,int fa)
{
	pa[i]=fa;
	for (int j=0;j<g[i].size();j++)
	{
		int to=g[i][j];
		if (to==fa) continue;
		dfs(to,i);
	}
}
int find(int x)
{
	int pos=x;
	while(pos)
	{
		lct.pushdown(pos);
		if (!lct.ch[pos][0] || !lct.sum[lct.ch[pos][0]]) 
		{
			if (lct.key[pos]) return pos;
			pos=lct.ch[pos][1];
		}
		else pos=lct.ch[pos][0];
	}
	return pos;
}
int main()
{
	scanf("%d",&n);
	for (int i=1;i<n;i++)
	{
		scanf("%d%d",&x,&y);
		g[x].push_back(y);
		g[y].push_back(x);
	}
	for (int i=1;i<n;i++)
	{
		scanf("%d%d",&x,&y);
		lct.key[n+i]=1;lct.ls[n+i]=x;lct.rs[n+i]=y;
		lct.link(x,n+i);lct.link(y,n+i);
	}
	printf("%d\n",n-1);
	dfs(1,0);
	for (int i=2;i<=n;i++) deg[pa[i]]++;
	for (int i=1;i<=n;i++)
	{
		if (!deg[i]) q.push(i);
	}
	for (int i=1;i<n;i++)
	{
		x=q.front();q.pop();
		lct.split(x,pa[x]);
		y=find(x);
		printf("%d %d %d %d\n",x,pa[x],lct.ls[y],lct.rs[y]);
		lct.cut(y,lct.ls[y]);lct.cut(y,lct.rs[y]);
		lct.ls[y]=x;lct.rs[y]=pa[x];
		lct.link(y,lct.ls[y]);lct.link(y,lct.rs[y]);
		lct.splay(y);lct.key[y]=0;lct.pushup(y); 
		if (!--deg[pa[x]]) q.push(pa[x]);
	}
	return 0;
}