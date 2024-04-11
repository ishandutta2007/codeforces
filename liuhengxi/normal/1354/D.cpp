#include<cstdio>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=1<<20;
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
int n,lg,n1,q,a[N+1],c[N+1];
void add(int x,int y)
{
	for(++x;x<=n;x+=(x&-x))c[x]+=y;
}
int find(int k)
{
	int x=0;
	for(int i=lg-1,j=n>>1;~i;--i,j>>=1)
	{
		if(k>=c[x+j])k-=c[x+=j];
	}
	return x;
}
int main()
{
	read(n);n1=n;read(q);
	F(i,0,n)read(a[i]);
	++n;
	while(n!=(n&-n))n+=n&-n;
	while((1<<lg)!=n)++lg;
	F(i,0,n1)add(--a[i],1);
	while(q--)
	{
		int k;read(k);
		if(k<0)
		{
			k=-k-1;
			add(find(k),-1);
		}
		else add(--k,1);
	}
	if(c[n])printf("%d\n",find(0)+1);
	else puts("0");
	return 0;
}