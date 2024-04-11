#include<cstdio>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=2027;
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
int t,n,a[N],m,ans[5*N];
bool check()
{
	F(i,0,n)if((i&1)!=(a[i]&1))return false;
	return true;
}
void op(int len)
{
	F(i,0,len/2)a[i]^=a[len-1-i]^=a[i]^=a[len-1-i];
	ans[m++]=len;
}
void solve(int n)
{
	int apos,bpos;
	if(n==1)return;
	F(i,0,n)if(a[i]==n-1)bpos=i;
	op(++bpos);
	F(i,0,n)if(a[i]==n-2)apos=i;
	op(apos);op(apos+2);
	op(3);op(n);
	solve(n-2);
}
int main()
{
	read(t);
	while(t--)
	{
		read(n);
		F(i,0,n)read(a[i]),--a[i];
		if(check())
		{
			m=0;
			solve(n);
			printf("%d\n",m);
			F(i,0,m)printf("%d ",ans[i]);
			puts("");
		}
		else puts("-1");
	}
	return 0;
}