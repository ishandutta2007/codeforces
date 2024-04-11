#include<cstdio>
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
int t,n;
int main()
{
	read(t);
	while(t--)
	{
		read(n);
		if(n==36)printf("YES\n5 6 10 15\n");
		else if(n==40)printf("YES\n9 6 10 15\n");
		else if(n==44)printf("YES\n13 6 10 15\n");
		else if(n>30)printf("YES\n6 10 14 %d\n",n-30);
		else printf("NO\n");
	}
	return 0;
}