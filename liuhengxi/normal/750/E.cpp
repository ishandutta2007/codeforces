#include<cstdio>
#include<algorithm>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
#define lc (p<<1)
#define rc (p<<1|1)
using namespace std;
const int N=2e5+5,INF=0x3fffffff;
template<typename T>void readmain(T &x)
{
	bool neg=false;
	int c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
template<typename T>T& read(T &x){readmain(x);return x;}
template<typename T,typename ...Tr>void read(T &x,Tr&... r){readmain(x);read(r...);}
struct matrix
{
	static const int N=5;
	int a[N][N];
	matrix(){F(i,0,N)F(j,0,N)a[i][j]=INF;F(i,0,N)a[i][i]=0;}
	friend matrix operator+(matrix a,matrix b);
}d[11],seg[N<<2];
#define N matrix::N
matrix operator+(matrix a,matrix b)
{
	matrix c;
	F(i,0,N)F(j,0,N)c.a[i][j]=INF;
	F(i,0,N)F(k,0,N)F(j,0,N)c.a[i][j]=min(c.a[i][j],a.a[i][k]+b.a[k][j]);
	return c;
}
#undef N
int n,q;
char s[N];
void build(int p,int l,int r)
{
	int mid=(l+r)>>1;
	if(r-l==1)return seg[p]=d[s[l]-'0'],void();
	build(lc,l,mid);build(rc,mid,r);
	seg[p]=seg[lc]+seg[rc];
}
matrix query(int p,int l,int r,int x,int y)
{
	int mid=(l+r)>>1;
	if(y<=l||r<=x)return d[10];
	if(x<=l&&r<=y)return seg[p];
	return query(lc,l,mid,x,y)+query(rc,mid,r,x,y);
}
int main()
{
	d[2].a[0][1]=0,d[2].a[0][0]=1;
	d[0].a[1][2]=0,d[0].a[1][1]=1;
	d[1].a[2][3]=0,d[1].a[2][2]=1;
	d[6].a[3][3]=1,d[6].a[4][4]=1;
	d[7].a[3][4]=0;
	read(n,q);
	scanf("%s",s);
	build(1,0,n);
	while(q--)
	{
		int l,r,ans;--read(l),read(r);
		ans=query(1,0,n,l,r).a[0][4];
		if(ans==INF)ans=-1;
		printf("%d\n",ans);
	}
	return 0;
}