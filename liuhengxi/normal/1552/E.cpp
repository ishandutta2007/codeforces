#include<cstdio>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=105,N2=10005;
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
int n,k,last[N],a[N],b[N],s[N2],lim;
int main()
{
	read(n);read(k);
	lim=(n-1)/(k-1)+1;
	F(i,0,n)last[i]=-1,a[i]=-1,b[i]=-1;
	F(i,0,n*k)
	{
		int c;
		read(c);--c;
		if(~last[c]&&!~a[c])
		{
			bool ok=true;
			F(j,last[c],i)if(s[j]>=lim)ok=false;
			if(ok)
			{
				F(j,last[c],i+1)++s[j];
				a[c]=last[c],b[c]=i;
			}
		}
		last[c]=i;
	}
	F(i,0,n)printf("%d %d\n",a[i]+1,b[i]+1);
	return 0;
}