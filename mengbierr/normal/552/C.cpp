#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
int read()
{
	char ch=getchar();int f=0;
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9'){f=(f<<1)+(f<<3)+ch-'0';ch=getchar();}
	return f;
}
int w,m;
int main()
{
	w=read(),m=read();
	if(w<=3) puts("YES");
	else
	{
		while(m)
		{
			if(m%w==0||m%w==1);
			else if(m%w==w-1) m+=w;
			else
			{
				puts("NO");
				return 0;
			}
			m/=w;
		}
		puts("YES");
		return 0;
	}
	
}