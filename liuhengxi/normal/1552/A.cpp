#include<cstdio>
#include<algorithm>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=50;
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
int T,n;
char s[N],t[N];
int main()
{
	read(T);
	while(T--)
	{
		int k=0;
		read(n);
		gets(s);
		F(i,0,n)t[i]=s[i];
		sort(t,t+n);
		F(i,0,n)if(s[i]!=t[i])++k;
		printf("%d\n",k);
	}
	return 0;
}