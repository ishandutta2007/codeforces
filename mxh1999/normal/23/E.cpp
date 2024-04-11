//This is meng meng da mjy>_<
#include <map>
#include <queue>
#include <cmath>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define INF 1000000007
typedef long long ll;
using namespace std;

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
//====================Template by stilwell=======================
struct Bignum
{
	#define N 51
	#define base 100000000
	static char s[N*10];
	typedef long long value;
	value a[N];
	int len;
	void clear(){len=1;a[len]=0;}
	Bignum(){clear();}
	Bignum(value x){*this=x;}
	Bignum operator =(const Bignum &b)
	{
		len=b.len;
		for (int i=1;i<=len;i++)	a[i]=b.a[i];
		return *this;
	}
	Bignum operator +(const Bignum &b)
	{
		int L=len>b.len?len:b.len;
		Bignum tmp;
		for (int i=1;i<=L+1;i++)	tmp.a[i]=0;
		for (int i=1;i<=L;i++)
		{
			if (i>len) tmp.a[i]+=b.a[i];else
			if (i>b.len)	tmp.a[i]+=a[i];else	tmp.a[i]+=a[i]+b.a[i];
			if (tmp.a[i]>=base)	tmp.a[i]-=base,++tmp.a[i+1];
		}
		if (tmp.a[L+1])	tmp.len=L+1;	else tmp.len=L;
		return tmp;
	}
	Bignum operator -(Bignum b)
	{
		int L=len>b.len?len:b.len;
		Bignum tmp;
		for (int i=1;i<=L+1;i++)	tmp.a[i]=0;
		for (int i=1;i<=L;i++)
		{
			if (i>b.len)	b.a[i]=0;
			tmp.a[i]+=a[i]-b.a[i];
			if (tmp.a[i]<0)
			{
				tmp.a[i]+=base;--tmp.a[i+1];
			}
		}
		while (L>1 && !tmp.a[L])	L--;
		tmp.len=L;
		return tmp;
	}
	Bignum operator *(const Bignum &b)	const
	{
		int L=len+b.len;
		Bignum tmp;
		for (int i=1;i<=L;i++)	tmp.a[i]=0;
		for (int i=1;i<=len;i++)
			for (int j=1;j<=b.len;j++)
			{
				tmp.a[i+j-1]+=a[i]*b.a[j];
				if (tmp.a[i+j-1]>=base)
				{
					tmp.a[i+j]+=tmp.a[i+j-1]/base;
					tmp.a[i+j-1]%=base;
				}
			}
		tmp.len=len+b.len;
		while (tmp.len>1 && !tmp.a[tmp.len])	tmp.len--;
		return tmp;
	}
	pair<Bignum,Bignum> divide(const Bignum &a,const Bignum &b)
	{
		int L=a.len;
		Bignum c,d;
		for (int i=L;i;i--)
		{
			c.a[i]=0;d=d*base;d.a[1]=a.a[i];
			int l=0,r=base-1,mid;
			while (l<r)
			{
				mid=(l+r+1)>>1;
				if (b*mid<=d)	l=mid;else r=mid-1;
			}
			c.a[i]=l;d-=b*l;
		}
		while (L>1 && !c.a[L])	L--;
		c.len=L;
		return mp(c,d);
	}
	Bignum operator /(value x)
	{
		value d=0;
		Bignum tmp;
		for (int i=len;i;i--)
		{
			d=d*base+a[i];
			tmp.a[i]=d/x;
			d%=x;
		}
		tmp.len=len;
		while (tmp.len>1 && !tmp.a[tmp.len])	tmp.len--;
		return tmp;
	}
	value operator %(value x)
	{
		value d=0;
		for (int i=len;i;--i)	d=(d*base+a[i])%x;
		return d;
	}
	Bignum operator /(const Bignum &b){return divide(*this,b).first;}
	Bignum operator %(const Bignum &b){return divide(*this,b).second;}
	Bignum &operator +=(const Bignum &b){*this=*this+b;return *this;}
	Bignum &operator -=(const Bignum &b){*this=*this-b;return *this;}
	Bignum &operator *=(const Bignum &b){*this=*this*b;return *this;}
	Bignum operator /=(const Bignum &b){*this=*this/b;return *this;}
	Bignum operator %=(const Bignum &b){*this=*this%b;return *this;}
	Bignum &operator ++(){Bignum T;T=1;*this=*this+T;return *this;}
	Bignum &operator --(){Bignum T;T=1;*this=*this-T;return *this;}
	Bignum operator ++(int){Bignum T,tmp=*this;T=1;*this=*this+T;return tmp;}
	Bignum operator --(int){Bignum T,tmp=*this;T=1;*this=*this-T;return tmp;}
	Bignum operator +(value x){Bignum T;T=x;return *this+T;}
	Bignum operator -(value x){Bignum T;T=x;return *this-T;}
	Bignum operator *(value x){Bignum T;T=x;return *this*T;}
	Bignum operator *=(value x){*this=*this*x;return *this;}
	Bignum operator +=(value x){*this=*this+x;return *this;}
	Bignum operator -=(value x){*this=*this-x;return *this;}
	Bignum operator /=(value x){*this=*this/x;return *this;}
	Bignum operator %=(value x){*this=*this%x;return *this;}
	bool operator ==(value x){Bignum T;T=x;return *this==T;}
	bool operator !=(value x){Bignum T;T=x;return *this!=T;}
	bool operator <=(value x){Bignum T;T=x;return *this<=T;}
	bool operator >=(value x){Bignum T;T=x;return *this>=T;}
	bool operator <(value x){Bignum T;T=x;return *this<T;}
	bool operator >(value x){Bignum T;T=x;return *this>T;}
	Bignum operator =(value x)
	{
		len=0;
		while (x)a[++len]=x%base,x/=base;
		if (!len)a[++len]=0;
		return *this;
	}
	bool operator <(const Bignum &b)
	{
		if (len<b.len)	return 1;
		if (len>b.len)	return 0;
		for (int i=len;i;i--)
		{
			if (a[i]<b.a[i])	return 1;
			if (a[i]>b.a[i])	return 0;
		}
		return 0;
	}
	bool operator ==(const Bignum &b)
	{
		if (len!=b.len)	return 0;
		for (int i=len;i;i--)
		if (a[i]!=b.a[i])	return 0;
		return 1;
	}
	bool operator !=(const Bignum &b){return !(*this==b);}
	bool operator >(const Bignum &b){return !(*this<b||*this==b);}
	bool operator <=(const Bignum &b){return (*this<b)||(*this==b);}
	bool operator >=(const Bignum &b){return (*this>b)||(*this==b);}
	void read()
	{
		scanf("%s",s);
		int l=strlen(s);
		value x=0,y=1;len=0;
		for (int i=l-1;i>=0;--i)
		{
			x=x+(s[i]-'0')*y;
			y*=10;
			if (y==base)	a[++len]=x,x=0,y=1;
		}
		if (!len||x)	a[++len]=x;
	}
	void print()
	{
		printf("%d",(int)a[len]);
		for (int i=len-1;i;--i)
		{
			for (int j=base/10;j>=10;j/=10)
			{
				if (a[i]<j)	printf("0");else break;
			}
			printf("%d",(int)a[i]);
		}
		printf("\n");
	}
};
char Bignum::s[N*10];
#define maxn 710
struct Edge
{
	int v,next;
}	e[maxn<<1];
int g[maxn],tot;
void addedge(int x,int y)
{
	tot++;
	e[tot].v=y;
	e[tot].next=g[x];
	g[x]=tot;
}
Bignum f[maxn][maxn],tmp;
int size[maxn];
int n;

void dfs(int t,int fa)
{
	f[t][1]=1;
	size[t]=1;
	for (int i=g[t];i;i=e[i].next)
	if (e[i].v!=fa)
	{
		dfs(e[i].v,t);
		for (int j=size[t];j>=0;j--)
			for (int k=size[e[i].v];k>=0;k--)
			{
				tmp=f[e[i].v][k];
				tmp*=f[t][j];
				if (f[t][j+k]<tmp)	f[t][j+k]=tmp;
			}
		size[t]+=size[e[i].v];
	}
	for (int i=0;i<=size[t];i++)
	{
		Bignum tmp=f[t][i];
		tmp*=i;
		if (f[t][0]<tmp)	f[t][0]=tmp;
	}
}
int main()
{
	read(n);
	for (int i=1;i<n;i++)
	{
		int x,y;
		read(x),read(y);
		addedge(x,y);
		addedge(y,x);
	}
	dfs(1,0);
	f[1][0].print();
	return 0;
}