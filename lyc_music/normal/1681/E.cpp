// Lynkcat.
// Problem: E. Labyrinth Adventures
// Contest: Codeforces - Educational Codeforces Round 129 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1681/problem/E
// Memory Limit: 512 MB
// Time Limit: 6000 ms

#include<bits/stdc++.h>
#define poly vector<int>
#define IOS ios::sync_with_stdio(false)
#define ll long long
#define mp make_pair
#define mt make_tuple
#define pa pair < int,int >
#define fi first
#define se second
#define inf 1e18
#define mod 998244353
#define int ll
#define N 200005
using namespace std;
int n;
int vis[2005][2005];
int q;
int dx[N][2],dy[N][2],ldx[N][2],ldy[N][2];
int rdx[N][2],rdy[N][2];
struct node
{
	int dis[2][2];
	node()
	{
		memset(dis,0,sizeof(dis));
	}
};
node tr[N<<2];
int calc(int x,int y,int X,int Y,int lx)
{
	int res=0;
	if (x==X) res=abs(y-Y);
	else if (y==Y)  res=abs(x-X);
	else if (x==lx) res=lx-y+lx-X;else
	res=lx-x+lx-Y;
	return res;
}
node merge(node x,node y,int mid)
{
	node res;
	for (int i=0;i<2;i++)
		for (int j=0;j<2;j++)
			res.dis[i][j]=inf;
	for (int i=0;i<2;i++)
		for (int j=0;j<2;j++)
			for (int ii=0;ii<2;ii++)
				for (int jj=0;jj<2;jj++)
				{
					res.dis[i][jj]=min(res.dis[i][jj],x.dis[i][j]+y.dis[ii][jj]+1+
					calc(dx[mid][j],dy[mid][j],rdx[mid][ii],rdy[mid][ii],mid));
				}
	return res;
}
void build(int k,int l,int r)
{
	if (l==r)
	{
		tr[k].dis[0][1]=tr[k].dis[1][0]=inf;
		return;
	}
	int mid=l+(r-l)/2;
	build(k<<1,l,mid);
	build(k<<1|1,mid+1,r);
	tr[k]=merge(tr[k<<1],tr[k<<1|1],mid);
}
node query(int k,int l,int r,int L,int R)
{
	if (L<=l&&r<=R) return tr[k];
	int mid=l+(r-l)/2;
	if (R<=mid) return query(k<<1,l,mid,L,R);
	if (L>mid) return query(k<<1|1,mid+1,r,L,R);
	return merge(query(k<<1,l,mid,L,R),query(k<<1|1,mid+1,r,L,R),mid);
}
void BellaKira()
{
	cin>>n;
	for (int j=0;j<=1;j++)
		dx[1][j]=dy[1][j]=1;
	for (int i=2;i<=n;i++)
	{
		for (int j=0;j<=1;j++)
			cin>>dx[i][j]>>dy[i][j];
		dx[i][0]=i;
		dy[i][1]=i;
		// vis[dx[i][0]][dy[i][0]]=1;
		// vis[dx[i][1]][dy[i][1]]=1;
		ldx[i][0]=dx[i-1][0]+1;
		ldy[i][0]=dy[i-1][0];
		ldx[i][1]=dx[i-1][1];
		ldy[i][1]=dy[i-1][1]+1;
	}
	// for (int i=1;i<=n;i++)
	// {
		// for (int j=1;j<=n;j++)
			// cout<<vis[i][j]<<"";
		// cout<<endl;
	// }
	for (int i=1;i<n;i++)
	{
		rdx[i][0]=dx[i+1][0]-1;
		rdy[i][0]=dy[i+1][0];
		rdx[i][1]=dx[i+1][1];
		rdy[i][1]=dy[i+1][1]-1;
	}
	build(1,1,n);
	cin>>q;
	for (int i=1;i<=q;i++)
	{
		int x,y,X,Y;
		cin>>x>>y>>X>>Y;
		int lx=max(x,y);
		int ly=max(X,Y);
		if (lx>ly) swap(x,X),swap(y,Y),swap(lx,ly);
		if (lx==ly)
		{
			cout<<calc(x,y,X,Y,lx)<<endl;
			continue;
		}
		node now=query(1,1,n,lx+1,ly);
		// cout<<lx<<" "<<ly<<endl;
		int res=inf;
		for (int ii=0;ii<2;ii++)
			for (int jj=0;jj<2;jj++)
			{
				now.dis[ii][jj]+=calc(x,y,rdx[lx][ii],rdy[lx][ii],lx)+1
				+calc(X,Y,dx[ly][jj],dy[ly][jj],ly),res=min(res,now.dis[ii][jj]);
			}
		cout<<res<<endl;
	}
			
		
}
signed main()
{
	IOS;
	int T=1;
	while (T--)
	{
		BellaKira();
	}
}