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
char s[N],a[N],b[N];
int main()
{
	read(t);
	while(t--)
	{
		int	cnt=0,now=0,now2=0;
		read(n);scanf("%s",s);
		F(i,0,n)if(s[i]=='1')++cnt;
		if(cnt&1||s[0]!='1'||s[n-1]!='1')puts("NO");
		else
		{
			F(i,0,n)if(s[i]=='1')
			{
				if(now<cnt/2)a[i]=b[i]='(';
				else a[i]=b[i]=')';
				++now;
			}
			else
			{
				if(now2&1)a[i]='(',b[i]=')';
				else a[i]=')',b[i]='(';
				++now2;
			}
			a[n]=b[n]='\0';
			puts("YES");
			puts(a);puts(b);
		}
	}
	return 0;
}