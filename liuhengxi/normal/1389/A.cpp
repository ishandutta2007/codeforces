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
int l,r;
int main()
{
	int t;read(t);
	while(t--)
	{
		read(l);read(r);
		if(l*2>r)printf("-1 -1\n");
		else printf("%d %d\n",l,2*l);
	}
	return 0;
}