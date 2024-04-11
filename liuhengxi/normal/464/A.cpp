#include<cstdio>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
#define fail return puts("NO"),0;
#define ok(i) ((i<1||s[i]!=s[i-1])&&(i<2||s[i]!=s[i-2]))
using namespace std;
const int N=1005;
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
int n,p;
char s[N];
int main()
{
	read(n);read(p);
	scanf("%s",s);
	if(n==1)
	{
		if(s[0]==96+p)fail;
		++s[0];return puts(s),0;
	}
	if(n==2)
	{
		++s[1];
		if(s[1]>96+p)s[1]='a',++s[0];
		if(s[1]==s[0])++s[1];
		if(s[1]>96+p)s[1]='a',++s[0];
		if(s[0]>96+p)fail;
		if(s[0]==s[1])fail;
		return puts(s),0;
	}
	//p>=3
	++s[n-1];
	for(int i=n-1;~i;--i)
	{
		if(i&&s[i]>96+p)
		{
			s[i]='a';
			++s[i-1];
			continue;
		}
		if(ok(i))
		{
			F(j,i+1,n)
			{
				s[j]='a';
				while(!ok(j))++s[j];
			}
			break;
		}
		while(s[i]<=96+p&&!ok(i))++s[i];
		if(s[i]<=96+p)
		{
			F(j,i+1,n)
			{
				s[j]='a';
				while(!ok(j))++s[j];
			}
			break;
		}
		else if(i)++s[i-1];
	}
	if(s[0]<=96+p)puts(s);
	else fail;
	return 0;
}