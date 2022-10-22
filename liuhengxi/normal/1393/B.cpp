#include<cstdio>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=1e5+5;
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
int n,c[N],q,sq,sm;
int main()
{
	read(n);
	F(i,0,n)
	{
		int a;read(a);
		++c[--a];
		if(c[a]%4==0)++sq,--sm;
		if(c[a]%2==0&&c[a]%4!=0)++sm;
	}
	read(q);
	while(q--)
	{
		char ch='\0';
		while(ch!='+'&&ch!='-')ch=getchar();
		int x;
		read(x);--x;
		if(ch=='+')
		{
			++c[x];
			if(c[x]%4==0)++sq,--sm;
			if(c[x]%2==0&&c[x]%4!=0)++sm;
		}
		else
		{
			if(c[x]%4==0)--sq,++sm;
			if(c[x]%2==0&&c[x]%4!=0)--sm;
			--c[x];
		}
		if(sq>=2)puts("YES");
		else if(sq>=1&&sm>=2)puts("YES");
		else puts("NO");
	}
	return 0;
}