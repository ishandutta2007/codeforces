#include<cstdio>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=50005;
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
struct ath
{
	int a[5];
	bool operator>(ath b)
	{
		int win=0;
		F(i,0,5)if(a[i]<b.a[i])++win;
		return win>=3;
	}
}a[N];
int t,n;
int main()
{
	read(t);
	while(t--)
	{
		int best=0;
		read(n);
		F(i,0,n)F(j,0,5)read(a[i].a[j]);
		F(i,1,n)if(a[i]>a[best])best=i;
		F(i,0,n)if(i!=best)
		{
			if(!(a[best]>a[i]))
			{
				best=-1;break;
			}
		}
		if(~best)++best;
		printf("%d\n",best);
	}
	return 0;
}