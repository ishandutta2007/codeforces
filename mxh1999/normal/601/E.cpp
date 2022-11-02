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
#define maxn 35010
struct Things
{
	int w,v;
	int l,r;
}	a[maxn];
const int base=1e7+19;
const int mo=1e9+7;
int que[20][maxn],cnt1[20];
int ques[20][maxn],cnt2[20];
int f[20][maxn];
int cnt;
int n,m,k;
int mjy[maxn];

inline bool in(int l,int r,int ql,int qr)
{
	if (l>ql)	swap(l,ql),swap(r,qr);
	return (r>=ql); 
} 
void solve(int l,int r,int dep)
{
	if (cnt2[dep]==0)	return;
	for (int i=1;i<=cnt1[dep];i++)
	{
		int u=que[dep][i];
		if (a[u].l<=l && a[u].r>=r)
		{
			for (int j=k;j>=a[u].w;j--)
			if (f[dep][j]<f[dep][j-a[u].w]+a[u].v)	f[dep][j]=f[dep][j-a[u].w]+a[u].v;
		}
	}
	if (l==r)
	{
		int maxx=0;
		for (int j=1;j<=k;j++)	f[dep][j]=max(f[dep][j],maxx),maxx=f[dep][j];
		ll zxo=0;
		for (int j=k;j>=1;j--)	zxo=(zxo*base+f[dep][j])%mo;
		for (int i=1;i<=cnt2[dep];i++)
			mjy[ques[dep][i]]=zxo;
		return;
	}
	int mid=(l+r)>>1;
	cnt1[dep+1]=cnt2[dep+1]=0;
	for (int j=1;j<=k;j++)	f[dep+1][j]=f[dep][j];
	for (int i=1;i<=cnt1[dep];i++)
	{
		int u=que[dep][i];
		if (!(a[u].l<=l && a[u].r>=r) && in(a[u].l,a[u].r,l,mid)) 
			que[dep+1][++cnt1[dep+1]]=u;
	}
	for (int i=1;i<=cnt2[dep];i++)
	if (ques[dep][i]<=mid)
	{
		ques[dep+1][++cnt2[dep+1]]=ques[dep][i];
	}
	solve(l,mid,dep+1);
	cnt1[dep+1]=cnt2[dep+1]=0;
	for (int j=1;j<=k;j++)	f[dep+1][j]=f[dep][j];
	for (int i=1;i<=cnt1[dep];i++)
	{
		int u=que[dep][i];
		if (!(a[u].l<=l && a[u].r>=r) && in(a[u].l,a[u].r,mid+1,r))
			que[dep+1][++cnt1[dep+1]]=u;
	}
	for (int i=1;i<=cnt2[dep];i++)
	if (ques[dep][i]>mid)
	{
		ques[dep+1][++cnt2[dep+1]]=ques[dep][i];
	}
	solve(mid+1,r,dep+1);
}
int main()
{
	read(n),read(k);
	for (int i=1;i<=n;i++)	read(a[i].v),read(a[i].w);
	read(m);
	for (int i=1;i<=n;i++)	a[i].l=1,a[i].r=m;
	cnt=n;
	for (int i=1;i<=m;i++)
	{
		int op;
		read(op);
		if (op==1)
		{
			cnt++;
			read(a[cnt].v),read(a[cnt].w);
			a[cnt].l=i;
			a[cnt].r=m;
		}
		if (op==2)
		{
			int x;
			read(x);
			a[x].r=i;
		}
		if (op==3)
		{
			ques[0][++cnt2[0]]=i;
		}
	}
	for (int i=1;i<=m;i++)	mjy[i]=-1;
	for (int i=1;i<=cnt;i++)	que[0][++cnt1[0]]=i;
	solve(1,m,0);
	for (int i=1;i<=m;i++)
	if (mjy[i]!=-1)	printf("%d\n",mjy[i]);
	return 0;
}