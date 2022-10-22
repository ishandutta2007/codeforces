#include<cstdio>
#include<algorithm>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=50;
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
int T,n,a[N];
int main()
{
	read(T);
	while(T--)
	{
		bool ans=true;
		read(n);
		F(i,0,n)read(a[i]);
		sort(a,a+n);
		F(i,0,n-1)if(a[i+1]-a[i]>1)ans=false;
		puts(ans?"YES":"NO");
	}
	return 0;
}