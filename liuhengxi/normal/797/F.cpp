#include<cstdio>
#include<algorithm>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=5005;
const long long LLINF=0x3fffffffffffffffll;
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
struct monoqueue
{
	long long v[N];
	int q[N],qf,qr,ind;
	void clear(){qf=qr=ind=0;}
	void push(long long val)
	{
		v[ind]=val;
		while(qf<qr&&v[q[qr-1]]>=/*<=*/val)--qr;
		q[qr++]=ind++;
	}
	void del(int id){while(qf<qr&&q[qf]<id)++qf;}
	long long getmin/*max*/(){return qf<qr?v[q[qf]]:/*-*/LLINF;}
}q;
struct hole
{
	int p,c;
	bool operator<(hole b)const{return p<b.p;}
}h[N];
int n,m,x[N];
long long sum[N][N],fi[N],fi1[N],ans=LLINF;
int main()
{
	read(n);read(m);
	F(i,0,n)read(x[i]);
	sort(x,x+n);
	F(i,0,m)read(h[i].p),read(h[i].c);
	sort(h,h+m);
	F(i,0,m)F(j,0,n)sum[i][j+1]=sum[i][j]+abs(x[j]-h[i].p);
	F(j,1,n+1)fi[j]=LLINF;
	F(i,0,m)
	{
		q.clear();
		F(j,0,n+1)
		{
			q.push(fi[j]-sum[i][j]);
			q.del(j-h[i].c);
			fi1[j]=q.getmin()+sum[i][j];
		}
		ans=min(ans,fi1[n]);
		F(j,0,n+1)fi[j]=fi1[j];
	}
	if(ans>=(LLINF>>1))ans=-1;
	printf("%lld\n",ans);
	return 0;
}