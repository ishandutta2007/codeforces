#include<cstdio>
#include<algorithm>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
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
	long long x,y;
	bool operator<(point b){return x!=b.x?x>b.x:y>b.y;}
}p[4];
int t;
long long penalty,min1,max1,min2,max2;
long long fsb(long long x){return 2*(x<min1?min1-x:(x>max1?x-max1:0))+2*(x<min2?min2-x:(x>max2?x-max2:0))+penalty;};
int main()
{
	read(t);
	while(t--)
	{
		long long ans=1e18;
		F(i,0,4)read(p[i].x),read(p[i].y);
		sort(p,p+4);
		do
		{
			penalty=abs(p[0].x-p[1].x)+abs(p[2].x-p[3].x)+abs(p[0].y-p[2].y)+abs(p[1].y-p[3].y);
			min1=min(p[0].x,p[1].x)-max(p[2].x,p[3].x),max1=max(p[0].x,p[1].x)-min(p[2].x,p[3].x);
			min2=min(p[0].y,p[2].y)-max(p[1].y,p[3].y),max2=max(p[0].y,p[2].y)-min(p[1].y,p[3].y);
			if(min1>=0)ans=min(ans,fsb(min1));
			if(max1>=0)ans=min(ans,fsb(max1));
			if(min2>=0)ans=min(ans,fsb(min2));
			if(max2>=0)ans=min(ans,fsb(max2));
			ans=min(ans,fsb(0));
		}while(next_permutation(p,p+4));
		printf("%lld\n",ans);
	}
	return 0;
}