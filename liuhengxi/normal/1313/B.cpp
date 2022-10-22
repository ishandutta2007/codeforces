#include<cstdio>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
int t,n,x,y;
int solve(int n,int x,int y,int f)
{
	int ans=x+y+f<n?x+y+f:n;
	return ans>1?ans:1;
}
int main()
{
	read(t);
	while(t--)
	{
		read(n);read(x);read(y);
		printf("%d %d\n",n-solve(n,n-x,n-y,0)+1,solve(n,x-1,y-1,1));
	}
	return 0;
}