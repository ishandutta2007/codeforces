#include<cstdio>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=5e3+5,INF=0x3fffffff;
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
int n,a[N];
int solve(int l,int r)
{
	int min=INF,last=l,ans;
	if(r-l==0)return 0;
	F(i,l,r)if(a[i]<min)min=a[i];
	ans=min;
	F(i,l,r)
	{
		a[i]-=min;
		if(!a[i])
		{
			ans+=solve(last,i);
			last=i+1;
		}
	}
	ans+=solve(last,r);
	if(ans>r-l)ans=r-l;
	return ans;
}
int main()
{
	read(n);
	F(i,0,n)read(a[i]);
	printf("%d\n",solve(0,n));
	return 0;
}