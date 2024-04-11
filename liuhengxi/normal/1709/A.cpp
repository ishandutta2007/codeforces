#include<cstdio>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
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
int tt,x,a,b,c;
int main()
{
	read(tt);
	while(tt--)
	{
		bool ans=true;
		read(x,a,b,c);
		if(a==2&&b==1)ans=false;
		if(a==3&&c==1)ans=false;
		if(c==2&&b==3)ans=false;
		if(a==1||b==2||c==3)ans=false;
		puts(ans?"YES":"NO");
	}
	return 0;
}