#include<cstdio>
#include<algorithm>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
#define lc (p<<1)
#define rc ((p<<1)|1)
using namespace std;
const int N=5e5+5,MOD=998244353;
template<typename T>void readmain(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
template<typename T>T& read(T &x){readmain(x);return x;}
template<typename T,typename ...Tr>void read(T &x,Tr&... r){readmain(x);read(r...);}
struct mat
{
	int a,b,c,d;
	mat operator*(mat v)
	{
		mat ans;
		ans.a=((long long)a*v.a+(long long)b*v.c)%MOD;
		ans.b=((long long)a*v.b+(long long)b*v.d)%MOD;
		ans.c=((long long)c*v.a+(long long)d*v.c)%MOD;
		ans.d=((long long)c*v.b+(long long)d*v.d)%MOD;
		return ans;
	}
	mat(){}
	mat(int u,int v){a=0,b=u?max(min(u*10+v+1,19-u*10-v),0):0,c=1,d=max(min(v+1,19-v),0);}
};
int n,m;
char cc[N],*c=cc+1;
mat seg[N<<2];
void build(int p,int l,int r)
{
	int mid=(l+r)>>1;
	if(r-l==1)return seg[p]=mat(c[l-1],c[l]),void();
	build(lc,l,mid);build(rc,mid,r);
	seg[p]=seg[lc]*seg[rc];
}
void update(int p,int l,int r,int x)
{
	int mid=(l+r)>>1;
	if(r-l==1)return seg[p]=mat(c[l-1],c[l]),void();
	if(x<mid)update(lc,l,mid,x);
	else update(rc,mid,r,x);
	seg[p]=seg[lc]*seg[rc];
}
int main()
{
	read(n,m);
	scanf("%s",c);
	F(i,0,n)c[i]-='0';
	build(1,0,n);
	while(m--)
	{
		int x,d;--read(x);read(d);
		c[x]=d;
		update(1,0,n,x);
		if(x+1<n)update(1,0,n,x+1);
		printf("%d\n",seg[1].d);
	}
	return 0;
}