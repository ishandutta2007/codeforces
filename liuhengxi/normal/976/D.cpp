#include<cstdio>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=1005,M=1e6+5;
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
int n,d[N],m,u[M],v[M];
void adline(int x,int y){u[m]=x,v[m++]=y;}
void solve(int l,int r,int x,int y)
{
	if(l==r)return;
	if(r-l==1){F(i,x,y)F(j,x,i)adline(i,j);return;}
	F(i,y-d[l],y)F(j,x,i)adline(j,i);
	F(i,l+1,r-1)d[i]-=d[l];
	solve(l+1,r-1,x+d[r-1]-d[r-2]-d[l],y-d[l]);
}
int main()
{
	read(n);
	F(i,0,n)read(d[i]);
	solve(0,n,0,d[n-1]+1);
	printf("%d\n",m);
	F(i,0,m)printf("%d %d\n",u[i]+1,v[i]+1);
	return 0;
}