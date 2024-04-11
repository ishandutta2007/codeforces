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
int q,n,m;
char s[N],t[N];
int main()
{
	read(q);
	while(q--)
	{
		int last=-1,j=0;
		n=0;m=0;
		gets(s);gets(t);
		while(s[n])++n;
		while(t[m])++m;
		F(i,0,n/2)s[i]^=s[n-i-1]^=s[i]^=s[n-i-1];
		F(i,0,m/2)t[i]^=t[m-i-1]^=t[i]^=t[m-i-1];
		F(i,0,n)
		{
			if(j<m&&((i-last)&1)&&t[j]==s[i]){++j;last=i;}
		}
		puts(j==m?"YES":"NO");
	}
	return 0;
}