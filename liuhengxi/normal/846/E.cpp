#include<cstdio>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
#define quit(str) return puts(str),0;
using namespace std;
const int N=1e5+5;
const long long LIM=1000000000000000000;
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
int n;
long long a[N],b[N],f[N],k[N],x[N];
bool exceed(long long a,long long b){return LIM/a<b;}
int main()
{
	read(n);
	F(i,0,n)read(b[i]);
	F(i,0,n)read(a[i]);
	F(i,0,n)f[i]=b[i]-a[i];
	F(i,1,n)read(x[i]),read(k[i]),--x[i];
	for(int i=n-1;i;--i)
	{
		if(f[i]>=0)f[x[i]]+=f[i];
		else
		{
			if(exceed(k[i],-f[i]))quit("NO");
			if((f[x[i]]+=k[i]*f[i])<-LIM)quit("NO");
		}
	}
	quit(f[0]>=0?"YES":"NO");
	return 0;
}