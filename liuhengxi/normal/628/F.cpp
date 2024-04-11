#include<cstdio>
#include<algorithm>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
#define fail return puts("unfair"),0
using namespace std;
const int N=1e4+5;
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
struct hint
{
	int u,q;
	bool operator<(hint b)const{return u<b.u;}
	bool operator==(hint b)const{return u==b.u&&q==b.q;}
}h[N];
int n,b,q,l[N],r[N],c[N];
int count(int l,int r,int x,int m=5){return (r+m-1-x)/m-(l+m-1-x)/m;}
int main()
{
	read(n,b,q);
	F(i,0,q)read(h[i].u,h[i].q);
	h[q].u=b;h[q].q=n;++q;
	sort(h,h+q);
	q=unique(h,h+q)-h;
	F(i,0,q-1)if(h[i].u>=h[i+1].u)fail;
	else if(h[i].q>h[i+1].q)fail;
	l[0]=1;r[0]=h[0].u+1;c[0]=h[0].q;
	F(i,1,q)l[i]=h[i-1].u+1,r[i]=h[i].u+1,c[i]=h[i].q-h[i-1].q;
	F(i,1,32)
	{
		int need=__builtin_popcount(i)*n/5;
		F(j,0,q)
		{
			int sum=0;
			F(k,0,5)sum+=(i>>k&1)*count(l[j],r[j],k);
			need-=min(sum,c[j]);
		}
		if(need>0)fail;
	}
	puts("fair");
	return 0;
}