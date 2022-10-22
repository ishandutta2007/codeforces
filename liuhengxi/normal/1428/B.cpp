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
int t,n;
char s[N+1];
int main()
{
	read(t);
	while(t--)
	{
		bool cl=true,ac=true;
		read(n);
		scanf("%s",s);
		F(i,0,n)if(s[i]=='<')cl=false;
		else if(s[i]=='>')ac=false;
		if(cl||ac)printf("%d\n",n);
		else
		{
			int cnt=0;
			F(i,0,n)if(s[i]=='-'||s[(i+1)%n]=='-')++cnt;
			printf("%d\n",cnt);
		}
	}
	return 0;
}