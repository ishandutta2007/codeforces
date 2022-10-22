#include<cstdio>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=2e5+5;
template<typename T>T& read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
	return x;
}
int n,a[N],v[32],s[N],ans;
bool insert(int x)
{
	for(int i=29;~i;--i)if(x>>i&1)
	{
		if(!v[i])return v[i]=x,true;
		x^=v[i];
	}
	return false;
}
int main()
{
	F(i,0,read(n))read(a[i]);
	F(i,0,n)s[i+1]=s[i]^a[i];
	if(!(ans+=insert(s[n])))return puts("-1"),0;
	F(i,0,n)ans+=insert(s[i]);
	printf("%d\n",ans);
	return 0;
}