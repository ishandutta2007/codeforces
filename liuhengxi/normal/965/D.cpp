#include<cstdio>
#include<algorithm>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=1e5+5;
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
int l,w,a[N],s[N],ans=1e9+5;
int main()
{
	read(w);read(l);
	F(i,0,w-1)read(a[i]);
	F(i,0,w-1)s[i+1]=s[i]+a[i];
	F(i,0,w-l)ans=min(ans,s[i+l]-s[i]);
	printf("%d\n",ans);
	return 0;
}