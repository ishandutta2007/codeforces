#include<cstdio>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=1e3+5;
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
int n,m;
bool b[N],c[N];
int main()
{
	read(n);read(m);
	F(i,0,n)
	{
		int a;read(a);a%=m;
		F(j,0,m)c[j]=b[j]||b[(j-a+m)%m];
		F(j,0,m)b[j]=c[j];
		b[a]=true;
		if(b[0])return puts("YES"),0;
	}
	puts("NO");
	return 0;
}