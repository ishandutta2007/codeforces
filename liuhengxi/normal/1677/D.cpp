#include<cstdio>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int MOD=998244353;
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
int tt,n,k;
int main()
{
	read(tt);
	while(tt--)
	{
		int v;
		long long ans=1;
		read(n,k);
		F(i,0,n)
		{
			read(v);
			if(i<n-k)
			{
				if(~v){if(!v)(ans*=k+1)%=MOD;}
				else (ans*=i+k+1)%=MOD;
			}
			else ans*=v<1;
		}
		F(i,1,k+1)(ans*=i)%=MOD;
		printf("%lld\n",ans);
	}
	return 0;
}