#include<cstdio>
#include<algorithm>
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
constexpr int N=1e5+5;
int tt,n,x[N],t[N],maxt;
bool check(int v,int tp)
{
	int l=-1e9,r=1e9;
	F(i,0,n)
	{
		l=max(l,x[i]-v+t[i]);
		r=min(r,x[i]+v-t[i]);
	}
	if(tp)return printf("%.10lf\n",(double)l*0.5),true;
	return l<=r;
}
int solve()
{
	int l=maxt-1,r=1e9,mid;
	while(r-l>1)
	{
		mid=(l+r)>>1;
		if(check(mid,0))r=mid;
		else l=mid;
	}
	return r;
}
int main()
{
	read(tt);
	while(tt--)
	{
		read(n);
		F(i,0,n)read(x[i])<<=1;
		maxt=0;
		F(i,0,n)maxt=max(maxt,read(t[i])<<=1);
		check(solve(),1);
	}
	return 0;
}