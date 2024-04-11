#include<cstdio>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=(1<<18)+5;
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
int n,r,c[N];
long long sum;
int main()
{
	read(n,r);n=1<<n;
	F(i,0,n)sum+=read(c[i]);
	printf("%.9lf\n",sum/(double)n);
	while(r--)
	{
		int z,g;read(z,g);sum-=c[z];sum+=c[z]=g;
		printf("%.9lf\n",sum/(double)n);
	}
	return 0;
}