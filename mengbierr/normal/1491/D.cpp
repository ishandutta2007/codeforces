#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
int read()
{
	char ch=getchar();int f=0,x=1;
	while(ch<'0'||ch>'9'){if(ch=='-') x=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){f=(f<<1)+(f<<3)+ch-'0';ch=getchar();}
	return f*x;
}
int s[100005],t[100005];
int main()
{
	int T=read();
	while(T--)
	{
		int a=read(),b=read();
		if(a>b)
		{
			puts("NO");
			continue;
		}
		for(int i=0;i<=30;i++)
		{
			s[i]=a%2;t[i]=b%2;
			a>>=1;b>>=1;
		}
		int cou=0;bool ok=1;
		for(int i=0;i<=30;i++)
		{
			cou+=s[i];
			if(t[i])
			{
				if(!cou) ok=0;
				else cou--;
			}
		}
		if(ok) puts("YES");
		else puts("NO");
	}
}