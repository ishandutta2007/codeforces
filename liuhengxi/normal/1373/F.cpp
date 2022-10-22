#include<cstdio>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=1e6+5;
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
int tt,n,a[N],b[N];
int main()
{
	read(tt);
	while(tt--)
	{
		long long sum=0,max=0,now=0;
		bool ok;
		read(n);
		F(i,0,n)read(a[i]),sum-=a[i];
		F(i,1,n+1)read(b[i%n]),sum+=b[i%n];
		ok=sum>=0;
		F(i,0,2*n)
		{
			int x=a[i%n],y=b[i%n],z=b[(i+1)%n];
			now+=y-x;
			if(now>max)max=now;
			if(now+z<max)ok=false;
		}
		puts(ok?"YES":"NO");
	}
	return 0;
}