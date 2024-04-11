#include<cstdio>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=1e6+5;
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
int n,m,dx,dy,o[N],x,y,c[N],ans;
int main()
{
	read(n);read(m);read(dx);read(dy);
	if(n==1)return puts("0 0"),0;
	F(i,0,n)o[x]=y,(x+=dx)%=n,(y+=dy)%=n;
	F(i,0,m)
	{
		read(x);read(y);
		++c[(y-o[x]+n)%n];
	}
	F(i,0,n)if(c[i]>c[ans])ans=i;
	printf("0 %d\n",ans);
	return 0;
}