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
int t,len;
char s[N+1];
int main()
{
	read(t);
	while(t--)
	{
		int n=0;
		scanf("%s",s);
		while(s[n])++n;
		len=0;
		F(i,0,n)
		{
			if(s[i]=='A')++len;
			else if(len)--len;else ++len;
		}
		printf("%d\n",len);
	}
	return 0;
}