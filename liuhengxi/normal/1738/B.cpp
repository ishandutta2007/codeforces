#include<cstdio>
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
int tt,n,k;
long long s[N],a[N];
int main()
{
	read(tt);
	while(tt--)
	{
		read(n,k);
		F(i,n-k,n)read(s[i+1]);
		if(k==1)
		{
			puts("YES");
			continue;
		}
		bool ans=true;
		if(k==n)
		{
			F(i,0,n)a[i]=s[i+1]-s[i];
			F(i,0,n-1)if(a[i]>a[i+1])ans=false;
		}
		else
		{
			F(i,n-k+1,n)a[i]=s[i+1]-s[i];
			F(i,n-k+1,n-1)if(a[i]>a[i+1])ans=false;
			ans=ans&&a[n-k+1]*(long long)(n-k+1)>=s[n-k+1];
		}
		puts(ans?"YES":"NO");
	}
	return 0;
}