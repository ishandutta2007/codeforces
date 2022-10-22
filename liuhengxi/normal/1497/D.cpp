#include<cstdio>
#include<algorithm>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=5e3+5;
template<typename T>void readmain(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
template<typename T>T& read(T &x){readmain(x);return x;}
template<typename T,typename ...Tr>void read(T &x,Tr&... r){readmain(x);read(r...);}
int tt,n,tag[N],s[N];
long long f[N],ans;
int main()
{
	read(tt);
	while(tt--)
	{
		read(n);
		F(i,0,n)read(tag[i]);
		F(i,0,n)read(s[i]);
		f[0]=ans=0;
		F(i,1,n)
		{
			f[i]=0;
			for(int j=i;~--j;)if(tag[i]!=tag[j])
			{
				long long tmp=f[j];
				f[j]=max(f[j],f[i]+(s[i]>s[j]?s[i]-s[j]:s[j]-s[i]));
				f[i]=max(f[i],tmp+(s[i]>s[j]?s[i]-s[j]:s[j]-s[i]));
			}
		}
		F(i,0,n)ans=max(ans,f[i]);
		printf("%lld\n",ans);
	}
	return 0;
}