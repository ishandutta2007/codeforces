#include<cstdio>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=3e5+5,M=5e5+5,INF=0x3fffffff;
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
int n,x[N],y[N],lx,rx,ly,ry,lxy,rxy;
char s[M];
bool check(int v)
{
	lx=x[0]-v,rx=x[0]+v,ly=y[0]-v,ry=y[0]+v,
	lxy=x[0]-y[0]-v,rxy=x[0]-y[0]+v;
	F(i,1,n)
	{
		int nlx=x[i]-v,nrx=x[i]+v,nly=y[i]-v,nry=y[i]+v,
		nlxy=x[i]-y[i]-v,nrxy=x[i]-y[i]+v;
		if(nlx>lx)lx=nlx;
		if(nly>ly)ly=nly;
		if(nlxy>lxy)lxy=nlxy;
		if(nrx<rx)rx=nrx;
		if(nry<ry)ry=nry;
		if(nrxy<rxy)rxy=nrxy;
	}
	if(lx>rx)return false;
	if(ly>ry)return false;
	if(lx-ry>lxy)lxy=lx-ry;
	if(rx-ly<rxy)rxy=rx-ly;
	if(lxy>rxy)return false;
	return true;
}
int solve()
{
	int l=-1,r=1.5e6,mid;
	while(r-l>1)
	{
		mid=(l+r)>>1;
		if(check(mid))r=mid;
		else l=mid;
	}
	return r;
}
int main()
{
	int ans=0;
	read(n);
	F(i,0,n)
	{
		scanf("%s",s);
		for(int j=0;s[j];++j)
			if(s[j]=='B')++x[i];
			else ++y[i];
	}
	printf("%d\n",ans=solve());
	check(ans);
	if(ry+lxy<rx)rx=ry+lxy;
	else if(ry+rxy>rx)ry=rx-rxy;
	while(rx--)putchar('B');
	while(ry--)putchar('N');
	putchar('\n');
	return 0;
}