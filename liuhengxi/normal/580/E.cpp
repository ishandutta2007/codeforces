#include<cstdio>
#include<chrono>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
#define lc (p<<1)
#define rc ((p<<1)|1)
using namespace std;
const int N=1e5+5,MOD1=1000000021,MOD2=1000000181,MOD=1000000181;
inline int myrand()
{
	static int s1=1000000000,s2=chrono::steady_clock::now()
	.time_since_epoch().count()%MOD2;
	if((s1<<=1)>=MOD1)s1-=MOD1;
	if((s2<<=1)>=MOD2)s2-=MOD2;
	return s1^s2;
}
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
int p2[N];
struct hash
{
	int val;int len;
	hash(){}
	hash(int a,int b=1){val=a,len=b;}
	hash operator+(hash b)const
	{return hash((val*(long long)p2[b.len]+b.val)%MOD,len+b.len);}
}val[N<<2];
int n,q,qq,tag[N<<2];
int w[10]={myrand(),myrand(),myrand(),myrand(),myrand(),myrand(),myrand(),myrand(),myrand(),myrand()};
int ww[10][N];
char s[N];
void build(int p,int l,int r)
{
	int mid=(l+r)>>1;tag[p]=-1;
	if(r-l==1)return val[p]=hash(w[s[l]-'0']),void();
	build(lc,l,mid);build(rc,mid,r);
	val[p]=val[lc]+val[rc];
}
void update(int p,int l,int r,int x,int y,int v)
{
	int mid=(l+r)>>1;
	if(y<=l||r<=x)return;
	if(x<=l&&r<=y)
	{
		tag[p]=v;
		val[p].val=ww[v][r-l];
		return;
	}
	if(~tag[p])
	{
		val[lc].val=ww[tag[lc]=tag[p]][mid-l];
		val[rc].val=ww[tag[rc]=tag[p]][r-mid];
		tag[p]=-1;
	}
	update(lc,l,mid,x,y,v);update(rc,mid,r,x,y,v);
	val[p]=val[lc]+val[rc];
}
hash query(int p,int l,int r,int x,int y)
{
	int mid=(l+r)>>1;
	if(y<=l||r<=x)return hash(0,0);
	if(x<=l&&r<=y)return val[p];
	if(~tag[p])
	{
		val[lc].val=ww[tag[lc]=tag[p]][mid-l];
		val[rc].val=ww[tag[rc]=tag[p]][r-mid];
		tag[p]=-1;
	}
	return query(lc,l,mid,x,y)+query(rc,mid,r,x,y);
}
void init(int x)
{
	hash a(w[x]),b(0,0);
	F(i,0,n+1)
	{
		ww[x][i]=b.val;
		b=b+a;
	}
}
int pow(int aa,int b)
{
	long long a=aa,c=1;
	while(b)
	{
		if(b&1)(c*=a)%=MOD;
		b>>=1;(a*=a)%=MOD;
	}
	return (int)c;
}
int main()
{
	read(n);read(q);read(qq);q+=qq;
	p2[0]=1;F(i,0,n)p2[i+1]=(p2[i]<<1)%MOD;
	F(i,0,10)init(i);
	scanf("%s",s);
	build(1,0,n);
	while(q--)
	{
		int op,l,r,x;read(op);
		if(op==1)
		{
			read(l);read(r);read(x);
			update(1,0,n,--l,r,x);
		}
		else
		{
			int mid=0,t;
			read(l);read(r);read(x);--l;
			mid=l+(r-l)/x*x;
			if(query(1,0,n,l,r-mid+l).val!=query(1,0,n,mid,r).val)
			{
				puts("NO");
				continue;
			}
			t=(p2[mid-l]-1ll)*pow(p2[x]-1,MOD-2)%MOD;
			if(l!=mid&&query(1,0,n,l,mid).val!=query(1,0,n,l,l+x).val*(long long)t%MOD)
			{
				puts("NO");
				continue;
			}
			puts("YES");
		}
	}
	return 0;
}