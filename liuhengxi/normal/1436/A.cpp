#include<cstdio>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=200;
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
int t,n,m,s,a[N];
int main()
{
	read(t);
	while(t--)
	{
		read(n);read(m);
		s=0;
		F(i,0,n)read(a[i]),s+=a[i];
		puts(s==m?"YES":"NO");
	}
	return 0;
}