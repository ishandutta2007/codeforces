#include<cstdio>
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
int n;
char a[N],b[N];
bool cmp()
{
	int dif=0;
	F(i,0,n)
	{
		dif=(dif<<1)+(b[i]-a[i]);
		if(dif>=2)return true;
	}
	return false;
}
int main()
{
	read(n);
	scanf("%s%s",a,b);
	if(a[0]!=b[0])
	{
		F(i,0,n)printf("1");
		puts("");
		return 0;
	}
	if(cmp())b[n-1]='1';
	puts(b);
	return 0;
}