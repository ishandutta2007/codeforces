#include<cstdio>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=2e5+5;
template<typename T>void readmain(T &x)
{
	bool neg=false;
	unsigned int c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
template<typename T>T& read(T &x){readmain(x);return x;}
template<typename T,typename ...Tr>void read(T &x,Tr&... r){readmain(x);read(r...);}
int tt,n;
bool valid(const char *str)
{
	int sum=0;
	F(i,0,n)
	{
		sum+=str[i]=='('?1:-1;
		if(sum<0)return false;
	}
	return sum==0;
}
char s[N],r[N];
int main()
{
	read(tt);
	while(tt--)
	{
		n=0;
		scanf("%s",s);
		while(s[n])++n;
		if(n&1)
		{
			puts("NO");
			continue;
		}
		int d=0,e=0,o=0,c=0;
		F(i,0,n)if(s[i]=='(')++d;else if(s[i]==')')--d;else ++e;
		o=(e-d)>>1;c=(e+d)>>1;
		if(-e<=d&&d<=e)
		{
			int cnt=0;
			F(i,0,n)
			{
				if(s[i]=='?')
				{
					s[i]=cnt<o?'(':')';
					if(o&&c)r[i]=(cnt<o+1&&cnt!=o-1)?'(':')';
					++cnt;
				}
				else r[i]=s[i];
			}
			if(valid(s)&&!(o&&c&&valid(r)))puts("YES");
			else puts("NO");
		}
		else puts("NO");
	}
	return 0;
}