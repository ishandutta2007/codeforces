#include<cstdio>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=2e5+5,INF=0x3fffffff;
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
struct min_queue
{
	int *a,n,q[N],qf,qr;
	void clear(){qf=qr=0;}
	void init(int *b,int m){a=b;n=m;}
	void push(int p)
	{
		if(p<0||p>=n)return;
		while(qf<qr&&a[q[qr-1]]>=a[p])--qr;
		q[qr++]=p;
	}
	void pop(int p)
	{if(qf<qr&&q[qf]==p)++qf;}
	int min(){return qf==qr?INF:a[q[qf]];}
}q1,q2;
int n,k,f[N],g[N];
int min(int a,int b){return a<b?a:b;}
int main()
{
	read(n);read(k);
	F(i,1,2*n+1)f[i]=INF;
	q1.init(f,2*n);q2.init(f,2*n);
	F(i,0,k)
	{
		int l,r;read(l);read(r);
		q1.clear();q2.clear();
		for(int j=r;j>=l;--j)q1.push(j);
		q2.push(0);
		F(j,0,2*n+1)
		{
			g[j]=min(f[j],min(q1.min()+1,q2.min()+2));
			q1.pop(r-j);q1.push(l-j-1);
			q2.pop(j-r+l);q2.push(j+1);
		}
		F(j,0,2*n+1)f[j]=g[j];
	}
	if(f[n]<INF)
	{
		puts("Full");
		printf("%d\n",f[n]);
	}
	else puts("Hungry");
	return 0;
}