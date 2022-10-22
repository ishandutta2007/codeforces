#include<cstdio>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=15;
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
int t,n,a[N];
int main()
{
	read(t);
	while(t--)
	{
		bool ans=false;
		read(n);
		F(i,0,n)read(a[i]);
		F(i,1,1<<n)
		{
			for(int j=i;;j=(j-1)&i)
			{
				int sum=0;
				F(k,0,n)if(i>>k&1)sum+=a[k];
				F(k,0,n)if(j>>k&1)sum-=2*a[k];
				if(sum==0)ans=true;
				if(j==0)break;
			}
		}
		puts(ans?"YES":"NO");
	}
	return 0;
}