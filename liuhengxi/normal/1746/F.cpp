#include<cstdio>
#include<cstring>
#include<random>
#include<chrono>
#include<map>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
template<typename T>void readmain(T &x)
{
	bool neg=false;
	unsigned int c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
template<typename T>T& read(T &x){readmain(x);return x;}
template<typename T,typename ...Tr>void read(T &x,Tr&... r){readmain(x);read(r...);}
mt19937_64 rnd(chrono::steady_clock::now().time_since_epoch().count()^*(new char)
^79774871^""[2]);
typedef unsigned long long ull;
constexpr int N=3e5+5;
map<int,ull> mp;
ull gethash(int x)
{
	if(!mp.count(x))mp[x]=rnd();
	return mp[x];
}
namespace seg
{
	ull pool[4200000];
	ull *s[(1<<20)+5],*t[(1<<20)+5],*cur=pool;
#define lc (p<<1)
#define rc (p<<1|1)
	void build(int p,int l,int r,int siz)
	{
		s[p]=cur;
		cur+=siz;
		t[p]=cur;
		cur+=siz;
		if(r-l==1)return;
		int mid=(l+r)>>1;
		build(lc,l,mid,siz-1);
		build(rc,mid,r,siz-1);
	}
	void update(int p,int l,int r,int x,ull y,int siz)
	{
		if(r-l==1)return s[p][0]=y,void();
		int mid=(l+r)>>1;
		if(x<mid)update(lc,l,mid,x,y,siz-1);
		else update(rc,mid,r,x,y,siz-1);
		ull car=0,tc;
		for(int i=0;i<siz;++i)
		{
			tc=(car&(s[lc][i]|s[rc][i]))|(s[lc][i]&s[rc][i]);
			s[p][i]=s[lc][i]^s[rc][i]^car;
			car=tc;
		}
		s[p][siz]=car;
	}
	void query(int p,int l,int r,int x,int y,int siz)
	{
		if(x==l&&r==y)
		{
			memcpy(t[p],s[p],sizeof(ull)*(siz+1));
			return;
		}
		int mid=(l+r)>>1;
		if(y<=mid)
		{
			query(lc,l,mid,x,y,siz-1);
			F(i,0,siz)t[p][i]=t[lc][i];
			t[p][siz]=0;
			return;
		}
		if(mid<=x)
		{
			query(rc,mid,r,x,y,siz-1);
			F(i,0,siz)t[p][i]=t[rc][i];
			t[p][siz]=0;
			return;
		}
		query(lc,l,mid,x,mid,siz-1),query(rc,mid,r,mid,y,siz-1);
		ull car=0,tc;
		for(int i=0;i<siz;++i)
		{
			tc=(car&(t[lc][i]|t[rc][i]))|(t[lc][i]&t[rc][i]);
			t[p][i]=t[lc][i]^t[rc][i]^car;
			car=tc;
		}
		t[p][siz]=car;
	}
#undef lc
#undef rc
}
int n,q,a[N],ts,ans[64];
int main()
{
	read(n,q);
	while((1<<ts)<n)++ts;
	seg::build(1,0,n,++ts);
	F(i,0,n)read(a[i]),seg::update(1,0,n,i,gethash(a[i]),ts-1);
	while(q--)
	{
		int opt;
		read(opt);
		if(opt==1)
		{
			int i;read(i);read(a[--i]);
			seg::update(1,0,n,i,gethash(a[i]),ts-1);
		}
		if(opt==2)
		{
			int l,r,k;read(l,r,k);--l;
			seg::query(1,0,n,l,r,ts-1);
			F(i,0,64)ans[i]=0;
			for(int i=ts;~--i;)
			{
				(ans[0x00]<<=1)|=(int)(seg::t[1][i]>>0x00&1);
				(ans[0x01]<<=1)|=(int)(seg::t[1][i]>>0x01&1);
				(ans[0x02]<<=1)|=(int)(seg::t[1][i]>>0x02&1);
				(ans[0x03]<<=1)|=(int)(seg::t[1][i]>>0x03&1);
				(ans[0x04]<<=1)|=(int)(seg::t[1][i]>>0x04&1);
				(ans[0x05]<<=1)|=(int)(seg::t[1][i]>>0x05&1);
				(ans[0x06]<<=1)|=(int)(seg::t[1][i]>>0x06&1);
				(ans[0x07]<<=1)|=(int)(seg::t[1][i]>>0x07&1);
				(ans[0x08]<<=1)|=(int)(seg::t[1][i]>>0x08&1);
				(ans[0x09]<<=1)|=(int)(seg::t[1][i]>>0x09&1);
				(ans[0x0a]<<=1)|=(int)(seg::t[1][i]>>0x0a&1);
				(ans[0x0b]<<=1)|=(int)(seg::t[1][i]>>0x0b&1);
				(ans[0x0c]<<=1)|=(int)(seg::t[1][i]>>0x0c&1);
				(ans[0x0d]<<=1)|=(int)(seg::t[1][i]>>0x0d&1);
				(ans[0x0e]<<=1)|=(int)(seg::t[1][i]>>0x0e&1);
				(ans[0x0f]<<=1)|=(int)(seg::t[1][i]>>0x0f&1);
				(ans[0x10]<<=1)|=(int)(seg::t[1][i]>>0x10&1);
				(ans[0x11]<<=1)|=(int)(seg::t[1][i]>>0x11&1);
				(ans[0x12]<<=1)|=(int)(seg::t[1][i]>>0x12&1);
				(ans[0x13]<<=1)|=(int)(seg::t[1][i]>>0x13&1);
				(ans[0x14]<<=1)|=(int)(seg::t[1][i]>>0x14&1);
				(ans[0x15]<<=1)|=(int)(seg::t[1][i]>>0x15&1);
				(ans[0x16]<<=1)|=(int)(seg::t[1][i]>>0x16&1);
				(ans[0x17]<<=1)|=(int)(seg::t[1][i]>>0x17&1);
				(ans[0x18]<<=1)|=(int)(seg::t[1][i]>>0x18&1);
				(ans[0x19]<<=1)|=(int)(seg::t[1][i]>>0x19&1);
				(ans[0x1a]<<=1)|=(int)(seg::t[1][i]>>0x1a&1);
				(ans[0x1b]<<=1)|=(int)(seg::t[1][i]>>0x1b&1);
				(ans[0x1c]<<=1)|=(int)(seg::t[1][i]>>0x1c&1);
				(ans[0x1d]<<=1)|=(int)(seg::t[1][i]>>0x1d&1);
				(ans[0x1e]<<=1)|=(int)(seg::t[1][i]>>0x1e&1);
				(ans[0x1f]<<=1)|=(int)(seg::t[1][i]>>0x1f&1);
				(ans[0x20]<<=1)|=(int)(seg::t[1][i]>>0x20&1);
				(ans[0x21]<<=1)|=(int)(seg::t[1][i]>>0x21&1);
				(ans[0x22]<<=1)|=(int)(seg::t[1][i]>>0x22&1);
				(ans[0x23]<<=1)|=(int)(seg::t[1][i]>>0x23&1);
				(ans[0x24]<<=1)|=(int)(seg::t[1][i]>>0x24&1);
				(ans[0x25]<<=1)|=(int)(seg::t[1][i]>>0x25&1);
				(ans[0x26]<<=1)|=(int)(seg::t[1][i]>>0x26&1);
				(ans[0x27]<<=1)|=(int)(seg::t[1][i]>>0x27&1);
				(ans[0x28]<<=1)|=(int)(seg::t[1][i]>>0x28&1);
				(ans[0x29]<<=1)|=(int)(seg::t[1][i]>>0x29&1);
				(ans[0x2a]<<=1)|=(int)(seg::t[1][i]>>0x2a&1);
				(ans[0x2b]<<=1)|=(int)(seg::t[1][i]>>0x2b&1);
				(ans[0x2c]<<=1)|=(int)(seg::t[1][i]>>0x2c&1);
				(ans[0x2d]<<=1)|=(int)(seg::t[1][i]>>0x2d&1);
				(ans[0x2e]<<=1)|=(int)(seg::t[1][i]>>0x2e&1);
				(ans[0x2f]<<=1)|=(int)(seg::t[1][i]>>0x2f&1);
				(ans[0x30]<<=1)|=(int)(seg::t[1][i]>>0x30&1);
				(ans[0x31]<<=1)|=(int)(seg::t[1][i]>>0x31&1);
				(ans[0x32]<<=1)|=(int)(seg::t[1][i]>>0x32&1);
				(ans[0x33]<<=1)|=(int)(seg::t[1][i]>>0x33&1);
				(ans[0x34]<<=1)|=(int)(seg::t[1][i]>>0x34&1);
				(ans[0x35]<<=1)|=(int)(seg::t[1][i]>>0x35&1);
				(ans[0x36]<<=1)|=(int)(seg::t[1][i]>>0x36&1);
				(ans[0x37]<<=1)|=(int)(seg::t[1][i]>>0x37&1);
				(ans[0x38]<<=1)|=(int)(seg::t[1][i]>>0x38&1);
				(ans[0x39]<<=1)|=(int)(seg::t[1][i]>>0x39&1);
				(ans[0x3a]<<=1)|=(int)(seg::t[1][i]>>0x3a&1);
				(ans[0x3b]<<=1)|=(int)(seg::t[1][i]>>0x3b&1);
				(ans[0x3c]<<=1)|=(int)(seg::t[1][i]>>0x3c&1);
				(ans[0x3d]<<=1)|=(int)(seg::t[1][i]>>0x3d&1);
				(ans[0x3e]<<=1)|=(int)(seg::t[1][i]>>0x3e&1);
				(ans[0x3f]<<=1)|=(int)(seg::t[1][i]>>0x3f&1);
			}
			bool fa=true;
			F(i,0,64)fa=fa&&ans[i]%k==0;
			puts(fa?"YES":"NO");
		}
	}
	return 0;
}