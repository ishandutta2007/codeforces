#include<cstdio>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
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
int q,n,m;
char s[N],t[N];
int main()
{
	read(q);
	while(q--)
	{
		bool ans=false;
		gets(s);gets(t);
		n=0;while(s[n])++n;
		m=0;while(t[m])++m;
		F(i,0,n)F(j,0,n)
		{
			if(i+j<n&&i+j-m+j>=-1)
			{
				bool ok=true;
				F(k,0,j)if(s[i+k]!=t[k])ok=false;
				F(k,0,m-j)if(s[i+j-k]!=t[j+k])ok=false;
				if(ok)ans=true;
			}
		}
		puts(ans?"Yes":"No");
	}
	return 0;
}