#include<cstdio> 
#include<iostream>
using namespace std;
inline int read()
{
	int s=0,w=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
	while(ch>='0' && ch<='9')s=(s<<3)+(s<<1)+(ch^48),ch=getchar();
	return s*w;
}
int n;
int main()
{
	//freopen("in.txt","r",stdin);
	n=read();
	for(int i=1;i<=n;++i)
	{
		int x=read(),y=read();
		int w=(x<<1)-y,e=(y<<1)-x;
		if(w%3==0 && e%3==0 && w>=0 && e>=0)printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}