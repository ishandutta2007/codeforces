#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mp make_pair
#define pb push_back
#define fi first
#define se second
void read(int &digit)
{
	digit=0;
	char c;
	for (c=getchar();(c<'0' || c>'9') && c!='-';c=getchar());
	bool type=false;
	if (c=='-')
		type=true,c=getchar();
	for (;c>='0' && c<='9';digit=digit*10+c-'0',c=getchar());
	if (type==true)
		digit=-digit;
}

#define maxn 500010
struct Splay
{
	int son[2];
	int fa;
	pair<int,int> num;
	int pos;
	bool rev,tag;
	bool col;
}	node[maxn];
struct Edge
{
	int u,v;
	pair<int,int> z;
}	e[maxn];
priority_queue<pair<int,int> >	Q;
int q[maxn],top;
int n,m;
const int INF=1<<30;
inline bool root(int x){return node[node[x].fa].son[0]!=x && node[node[x].fa].son[1]!=x;}
void update(int x)
{
	int left=node[x].son[0],right=node[x].son[1];
	node[x].pos=x;
	if (node[node[left].pos].num>node[node[x].pos].num)	node[x].pos=node[left].pos;
	if (node[node[right].pos].num>node[node[x].pos].num)	node[x].pos=node[right].pos;
}
void down(int x)
{
	int l=node[x].son[0],r=node[x].son[1];
	if (node[x].rev)
	{
		node[x].rev^=1;
		node[l].rev^=1;
		node[r].rev^=1;
		swap(node[x].son[0],node[x].son[1]);
	}
	if (node[x].tag)
	{
		node[x].col^=1;
		node[x].tag^=1;
		node[l].tag^=1;
		node[r].tag^=1;
	}
}
void rotate(int x)
{
	int y=node[x].fa,z=node[y].fa;
	int left,right;
	if (node[y].son[0]==x)	left=0;else left=1;
	right=left^1;
	if (!root(y))
	{
		if (node[z].son[0]==y)	node[z].son[0]=x;else node[z].son[1]=x;
	}
	node[x].fa=z;
	node[y].fa=x;
	if (node[x].son[right]!=0)	node[node[x].son[right]].fa=y;
	node[y].son[left]=node[x].son[right];
	node[x].son[right]=y;
	update(y);
	update(x);
}
void splay(int x)
{
	top=0;q[++top]=x;
	for (int i=x;!root(i);i=node[i].fa)	q[++top]=node[i].fa;
	for (int i=top;i;i--)	down(q[i]);
	while (!root(x))
	{
		int y=node[x].fa,z=node[y].fa;
		if (!root(y))
		{
			if (node[y].son[0]==x ^ node[z].son[0]==y)	rotate(x);
			else rotate(y);
		}
		rotate(x);
	}
	update(x);
}
void access(int x)
{
	int t=0;
	while (x)
	{
		splay(x);
		node[x].son[1]=t;
		t=x;
		x=node[x].fa;
	}
}
void makeroot(int x)
{
	access(x);
	splay(x);
	node[x].rev^=1;
}
void link(int x,int y)
{
	//cerr<<"link"<<x<<' '<<y<<endl;
	makeroot(x);
	node[x].fa=y;
}
void cut(int x,int y)
{
	//cerr<<"cut"<<x<<" " <<y<<endl;
	makeroot(x);
	access(y);
	splay(y);
	node[node[y].son[0]].fa=0;
	node[y].son[0]=0;
	update(y);
}
bool getcol(int x)
{
	splay(x);
	return node[x].col;
}
void paint(int x,int y)
{
	makeroot(x);
	access(y);
	splay(y);
	node[y].tag^=1;
}
int query(int x,int y)
{
	makeroot(x);
	access(y);
	splay(y);
	return node[y].pos;
}
void deal(int k)
{
	int u=e[k].u,v=e[k].v;
	pair<int,int> w=e[k].z;
	int t=query(u,v);
	if (w<node[t].num)
	{
		Q.push(w);
		node[k+n].col=0;
		int col=getcol(t);
		cut(e[t-n].u,t);
		cut(e[t-n].v,t);
		link(u,k+n);
		link(v,k+n);
		if (col)	paint(e[t-n].u,e[t-n].v);
		node[t].col=0;
	}
}
int main()
{
	//freopen("603E.in","r",stdin);
	read(n),read(m);
	if (n&1)
	{
		for (int i=1;i<=m;i++)	printf("-1\n");
		return 0;
	}
	for (int i=1;i<n;i++)
	{
		e[m+i].u=1;
		e[m+i].v=i+1;
		e[m+i].z=mp(INF,m+i);
		node[n+m+i].num=mp(INF,m+i);
		node[n+m+i].col=true;
		link(1,n+m+i);
		link(i+1,n+m+i);
		Q.push(mp(INF,m+i));
	}

	for (int i=1;i<=m;i++)
	{
		int x,y,z;
		read(x),read(y),read(z);
		e[i].u=x;
		e[i].v=y;
		e[i].z=mp(z,i);
		node[n+i].num=mp(z,i);
		node[n+i].pos=n+i;
		deal(i);
		pair<int,int>	zxo=Q.top();
		while (!getcol(zxo.se+n))	Q.pop(),zxo=Q.top();
		printf("%d\n",e[zxo.se].z.fi==INF?-1:e[zxo.se].z.fi);
	}
	return 0;
}