#include<cstdio>
#include<algorithm>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=1e6+5;
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
struct query
{
	int l,r,id;
	bool operator<(query b)const{return l<b.l;}
}qy[N];
int n,m,ans[N],q,qa[3*N],qb[3*N],qf,qr,c[N];
bool *e[N],*u[N];
char *s[N];
void dfs(int x,int y)
{
	if(x>=n||y>=m||e[x][y]||s[x][y]=='X')return;
	e[x][y]=true;
	qa[qr]=x+1,qb[qr]=y;++qr;
	qa[qr]=x,qb[qr]=y+1;++qr;
	dfs(x+1,y);dfs(x,y+1);
}
void add(int x,int y){for(++x;x<=m;x+=x&-x)c[x]+=y;}
int sum(int x){int ans=0;for(;x;x-=x&-x)ans+=c[x];return ans;}
int main()
{
	int L=0;
	read(n);read(m);
	F(i,0,n)
	{
		s[i]=new char[m+1];
		scanf("%s",s[i]);
	}
	F(i,0,n)e[i]=new bool[m];
	F(i,0,n)u[i]=new bool[m];
	read(q);
	F(i,0,q)read(qy[i].l),read(qy[i].r),--qy[i].l,qy[i].id=i;
	sort(qy,qy+q);
	F(i,0,n)F(j,0,m)
	{
		if(s[i][j]=='X'){e[i][j]=false;continue;}
		if(i==0||j==0)e[i][j]=true;
		else e[i][j]=e[i-1][j]||e[i][j-1];
	}
	F(i,1,n)F(j,1,m)
	{
		u[i][j]=(!e[i-1][j])&&(!e[i][j-1]);
		if(u[i][j])add(j,u[i][j]);
	}
	F(i,0,q)
	{
		while(L<qy[i].l)
		{
			++L;
			qf=qr=0;
			F(i,0,n)dfs(i,L);
			while(qf<qr)
			{
				int i=qa[qf],j=qb[qf],delta;++qf;
				if(i>=n||j>=m)continue;
				delta=-u[i][j];
				delta+=u[i][j]=i!=L&&(!e[i-1][j])&&(!e[i][j-1]);
				if(delta)add(j,delta);
			}
			F(i,1,n)if(u[i][L])u[i][L]=false,add(L,-1);
		}
		ans[qy[i].id]=sum(qy[i].l)==sum(qy[i].r);
	}
	F(i,0,q)puts(ans[i]?"Yes":"No");
	return 0;
}