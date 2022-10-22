#include<cstdio>
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
int tt,n,m,a[N],b[N],c[N];
bool fsb[N];
int main()
{
	read(tt);
	while(tt--)
	{
		read(n);read(m);
		F(i,0,n)fsb[i]=false;
		F(i,0,m)read(a[i]),read(b[i]),read(c[i]),--a[i],--b[i],--c[i],fsb[b[i]]=true;
		F(i,0,n)if(!fsb[i])
		{
			F(j,0,i)printf("%d %d\n",i+1,j+1);
			F(j,i+1,n)printf("%d %d\n",i+1,j+1);
			break;
		}
	}
	return 0;
}