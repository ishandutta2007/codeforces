#include<cstdio>
#include<cmath>
#include<algorithm>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=1e5+5;
const long double PI=acos(-1.0);
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
struct vec
{
	long double a;
	int id;
	bool operator<(vec b)const{return a<b.a;}
}a[N];
int n,u,v;long double mindif;
int main()
{
	read(n);
	F(i,0,n)
	{
		int x,y;read(x);read(y);
		a[i].a=atan2(x,y);a[i].id=i;
	}
	sort(a,a+n);
	mindif=a[1].a-a[0].a;u=a[0].id,v=a[1].id;
	F(i,1,n-1)if(a[i+1].a-a[i].a<mindif)mindif=a[i+1].a-a[i].a,u=a[i].id,v=a[i+1].id;
	if(a[0].a-a[n-1].a+2*PI<mindif)u=a[0].id,v=a[n-1].id;
	printf("%d %d\n",u+1,v+1);
	return 0;
}