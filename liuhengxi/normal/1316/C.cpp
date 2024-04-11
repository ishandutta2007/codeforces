#include<cstdio>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=1e6+5;
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
int n,m,p,a[N],b[N],ans;
int main()
{
	read(n);read(m);read(p);
	F(i,0,n)read(a[i]);
	F(i,0,m)read(b[i]);
	F(i,0,n)if(a[i]%p){ans+=i;break;}
	F(i,0,m)if(b[i]%p){ans+=i;break;}
	printf("%d\n",ans);
	return 0;
}