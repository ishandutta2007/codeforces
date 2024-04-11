#include<cstdio>
#include<algorithm>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=1005;
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
struct circle
{
	int x,y,r;
	bool operator<(circle b)const{return r<b.r;}
}c[N];
int n;
long long ans;
bool in(circle a,circle b)
{
	long long xx=a.x-b.x,yy=a.y-b.y,rr=b.r-a.r;
	return xx*xx+yy*yy<=rr*rr;
}
int main()
{
	read(n);
	F(i,0,n)read(c[i].x),read(c[i].y),read(c[i].r);
	sort(c,c+n);
	F(i,0,n)
	{
		int k=0;
		F(j,i+1,n)if(in(c[i],c[j]))++k;
		if(k==0||(k&1))ans+=(long long)c[i].r*c[i].r;
		else ans-=(long long)c[i].r*c[i].r;
	}
	printf("%.10lf\n",ans*3.141592653589793);
	return 0;
}