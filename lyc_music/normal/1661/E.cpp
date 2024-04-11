//LYC_music yyds!
#include<bits/stdc++.h>
#define IOS ios::sync_with_stdio(0)
#define lowbit(x) (x&(-x))
#define int long long
using namespace std;
inline char gc()
{
	static char buf[1000000],*p1=buf,*p2=buf;
	return p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++;
}
int read()
{
	int pos=1,num=0;
	char ch=getchar();
	while (!isdigit(ch))
	{
		if (ch=='-') pos=-1;
		ch=getchar();
	}
	while (isdigit(ch))
	{
		num=num*10+(int)(ch-'0');
		ch=getchar();
	}
	return pos*num;
}
void write(int x)
{
	if (x<0)
	{
		putchar('-');
		write(-x);
		return;
	}
	if (x>=10) write(x/10);
	putchar(x%10+'0');
}
void writesp(int x)
{
	write(x);
	putchar(' ');
}
void writeln(int x)
{
	write(x);
	putchar('\n');
}
const int N=4,M=5e5+10;
int tmpfa[N<<2],n,m,q,a[N][M],tmp[N<<2];
struct node
{
	int fa[N*2],ans;
	node()
	{
		for (int i=1;i<=n;i++)
			fa[i]=fa[i+n]=0;
	}
	void init()
	{
		ans=0;
		for (int i=1;i<=n;i++)
			fa[i]=fa[i+n]=i;
	}
	int find(int x)
	{
		if (fa[x]==x) return x;
		return fa[x]=find(fa[x]);
	}
	void merge(int x,int y)
	{
		int fx=find(x),fy=find(y);
		if (fx==fy) return;
		fa[fy]=fx;
	}
	void New(int l)
	{
		init();
		for (int i=1;i<n;i++)
		{
			int L=a[i][l],R=a[i+1][l];
			if (L==R) merge(i,i+1);
		}
		for (int i=1;i<=n;i++)
			find(i+n);
		for (int i=1;i<=n;i++)
			if (fa[i]==i&&a[i][l]==1) ans++;
	}
}tree[M<<2];
int findtmp(int x)
{
	if (tmpfa[x]==x) return x;
	return tmpfa[x]=findtmp(tmpfa[x]);
}
node merge(node x,node y,int mid)
{
	node res;
	res.ans=x.ans+y.ans;
	for (int i=1;i<=2*n;i++)
		tmpfa[i]=x.fa[i];
	for (int i=1;i<=2*n;i++)
		tmpfa[i+2*n]=y.fa[i]+2*n;
	for (int i=1;i<=n;i++)
	{
		int L=a[i][mid],R=a[i][mid+1];
		if (L==R)
		{
			int fx=findtmp(i+n),fy=findtmp(i+2*n);
			if (fx==fy) continue;
			if (a[i][mid]==1)
				res.ans--;
			tmpfa[fy]=fx;
		}
	}
	memset(tmp,0,sizeof(tmp));
	for (int i=1;i<=n;i++)
	{
		int fx=findtmp(i);
		if (!tmp[fx]) tmp[fx]=i;
		fx=findtmp(i+3*n);
		if (!tmp[fx]) tmp[fx]=i+n;
	}
	for (int i=1;i<=n;i++)
		res.fa[i]=tmp[findtmp(i)],res.fa[i+n]=tmp[findtmp(i+3*n)];
	return res;
}
void build(int k,int l,int r)
{
	if (l==r) return tree[k].New(l),void();
	int mid=(l+r)>>1;
	build(k<<1,l,mid);
	build(k<<1|1,mid+1,r);
	tree[k]=merge(tree[k<<1],tree[k<<1|1],mid);
}
node query(int k,int l,int r,int L,int R)
{
	if (L<=l&&r<=R) return tree[k];
	int mid=(l+r)>>1;
	if (L>mid) return query(k<<1|1,mid+1,r,L,R);
	if (R<=mid) return query(k<<1,l,mid,L,R);
	return merge(query(k<<1,l,mid,L,R),query(k<<1|1,mid+1,r,L,R),mid);
}
signed main()
{
//	freopen("harmony.in","r",stdin);
//	freopen("harmony.out","w",stdout);
	n=3; m=read();
	for (int i=1;i<=3;i++)
	{
		string st;
		cin>>st;
		for (int j=1;j<=m;j++)
			a[i][j]=st[j-1]-'0';
	}
	build(1,1,m); q=read();
	while (q--)
	{
		int l=read(),r=read();
		if (l>r)
		{
			writeln(0);
			continue;
		}
		writeln(query(1,1,m,l,r).ans);
	}
}