#include<cstdio>
#include<algorithm>
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
struct point
{
	int id,x,y;
	bool operator<(point b)const{return x>>10!=b.x>>10?x<b.x:(x&1024?y<b.y:y>b.y);}
}p[N];
int n;
int main()
{
	read(n);
	F(i,0,n)read(p[i].x),read(p[i].y),p[i].id=i;
	sort(p,p+n);
	F(i,0,n)printf("%d ",p[i].id+1);
	puts("");
	return 0;
}