#include<cstdio>
#include<algorithm>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
template<typename T>void readmain(T &x)
{
	bool neg=false;
	unsigned int c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
template<typename T>T& read(T &x){readmain(x);return x;}
template<typename T,typename ...Tr>void read(T &x,Tr&... r){readmain(x);read(r...);}
constexpr int N=1e5+5;
int tt,n,a[N],s[N],ans;
int main()
{
	read(tt);
	while(tt--)
	{
		read(n);
		F(i,0,n)s[i+1]=s[i]+read(a[i]);
		ans=n;
		F(i,0,n+1)
		{
			ans=min(ans,max(s[i],(n-i)-(s[n]-s[i])));
		}
		printf("%d\n",ans);
	}
	return 0;
}