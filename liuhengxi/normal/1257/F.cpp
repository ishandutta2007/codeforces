#include<cstdio>
#include<algorithm>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
#define low(x) ((x)&0x00007fff)
#define high(x) (((x)&0x3fff8000)>>15)
using namespace std;
const int N=110,M=(1<<15)+5;
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
int n,a[N],b[M][N],c[M][N],cmp;
struct aaa
{
	int *val,ind;
	bool operator<(aaa b)const{return val[cmp]<b.val[cmp];}
}bb[M],cc[M];
int popcount(int x){return x==0?0:popcount(x^(x&-x))+1;}
bool less1(aaa a,aaa b)
{
	F(i,0,n)if(a.val[i]!=b.val[i])return a.val[i]<b.val[i];
	return false;
}
bool equ(aaa a,aaa b)
{
	F(i,0,n)if(a.val[i]!=b.val[i])return false;
	return true;
}
int main()
{
	read(n);F(i,0,n)read(a[i]);
	F(k,0,1<<15)
	{
		int a0=popcount(low(a[0])^k);
		F(i,0,n)b[k][i]=a0-popcount(low(a[i])^k);
	}
	F(k,0,1<<15)
	{
		int a0=popcount(high(a[0])^k);
		F(i,0,n)c[k][i]=popcount(high(a[i])^k)-a0;
	}
	F(k,0,1<<15)
	{
		bb[k].val=b[k];bb[k].ind=k;
		cc[k].val=c[k];cc[k].ind=k;
	}
	cmp=n;
	while(cmp--)stable_sort(bb,bb+(1<<15)),stable_sort(cc,cc+(1<<15));
	for(int i=0,j=0;i<(1<<15);++i)
	{
		while(j<(1<<15)&&less1(cc[j],bb[i]))++j;
		if(j<(1<<15)&&equ(cc[j],bb[i]))
		{
			printf("%d\n",(cc[j].ind<<15)^bb[i].ind);
			return 0;
		}
	}
	puts("-1");
	return 0;
}