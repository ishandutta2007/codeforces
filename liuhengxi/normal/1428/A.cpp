#include<cstdio>
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
int t,x1,x2,y1,y2;
int main()
{
	read(t);
	while(t--)
	{
		int xx,yy;
		read(x1);read(y1);read(x2);read(y2);
		xx=x1>x2?x1-x2:x2-x1;
		yy=y1>y2?y1-y2:y2-y1;
		if(xx==0&&yy==0)puts("0");
		if(xx!=0&&yy==0)printf("%d\n",xx);
		if(xx==0&&yy!=0)printf("%d\n",yy);
		if(xx!=0&&yy!=0)printf("%d\n",xx+yy+2);
	}
	return 0;
}