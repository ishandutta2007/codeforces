#include<cstdio>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
#define alice {puts("Yes");goto die;}
#define bob {puts("No");goto die;}
using namespace std;
const int N=3e5+5;
template<typename T>void readmain(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
template<typename T>T& read(T &x){readmain(x);return x;}
template<typename T,typename ...Tr>void read(T &x,Tr&... r){readmain(x);read(r...);}
int q,a,b;
char s[N];
int main()
{
	for(read(q);q--;)
	{
		int cnt=0,one=0;
		bool c0=false,c1=false;
		read(a,b);
		scanf("%s",s);
		for(int i=0;s[i]||(s[i]='X',s[i+1]=0);++i);
		for(int i=0,c=0;s[i];++i)
		{
			if(s[i]=='X')
			{
				if(c>=b)
				{
					if(c<a)bob
					else if(c<2*b)++one;
					else if(c>=a)
					{
						++one;++cnt;c-=a;
						c0=(0<=c&&c<2*b-1)||(2*a<=c&&c<4*b-1);
						c1=(a<=c&&c<3*b-1);
						if(!c0&&!c1)bob
					}
				}
				c=0;
			}
			else ++c;
		}
		if(cnt>1)bob
		if(cnt==1&&((!c0)||(c1&&!(one&1))))++one;
		if(one&1)alice
		else bob
		die:;
	}
	return 0;
}