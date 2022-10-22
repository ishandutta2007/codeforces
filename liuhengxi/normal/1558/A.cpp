#include<cstdio>
#include<cmath>
#include<algorithm>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=2e5+5;
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
int t,c[N];
int main()
{
	read(t);
	while(t--)
	{
		int a,b,m=0,x,y;read(a);read(b);
		F(i,0,a+b+1)c[i]=0;
		x=(a+b)/2;y=a+b-x;
		for(int i=min(abs(a-x),abs(a-y)),end=max(min(x+a,x+y+y-a),min(y+a,x+y+x-a));i<=end;i+=2)c[i]=1;
		F(i,0,a+b+1)c[i]=c[i]||c[a+b-i];
		F(i,0,a+b+1)if(c[i])++m;
		printf("%d\n",m);
		F(i,0,a+b+1)if(c[i])printf("%d ",i);
		puts("");
	}
	return 0;
}