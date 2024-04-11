#include<cstdio>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=3e5+5;
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
int t,n,c0,c1,c2;
char s0[N],s1[N],s2[N];
int main()
{
	read(t);
	while(t--)
	{
		read(n);
		gets(s0);gets(s1);gets(s2);
		F(i,2*n,3*n)s0[i]=s1[i]=s2[i]='0';
		c0=c1=c2=0;
		F(i,0,3*n)
		{
			if(c0==2*n)
			{
				if(c1>c2)putchar(s1[c1++]);
				else putchar(s2[c2++]);
			}
			else if(c1==2*n)
			{
				if(c0>c2)putchar(s0[c0++]);
				else putchar(s2[c2++]);
			}
			else if(c2==2*n)
			{
				if(c0>c1)putchar(s0[c0++]);
				else putchar(s1[c1++]);
			}
			else if(s0[c0]==s1[c1])
			{
				putchar(s0[c0]);
				++c0;++c1;
			}
			else if(s0[c0]==s2[c2])
			{
				putchar(s0[c0]);
				++c0;++c2;
			}
			else if(s2[c2]==s1[c1])
			{
				putchar(s2[c2]);
				++c2;++c1;
			}
		}
		putchar('\n');
	}
	return 0;
}