#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int read()
{
	char ch=getchar();int f=0;
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9') {f=f*10+(ch^48);ch=getchar();}
	return f;
}
int main()
{
	int q=read();
	while(q--)
	{
		int n=read();
		if(n%4==0)
		{
			printf("%d\n",n/4);
		}
		else if(n%4==2)
		{
			if(n<6) printf("%d\n",-1);
			else printf("%d\n",(n-6)/4+1);
		}
		else if(n%4==1)
		{
			if(n<9) printf("-1\n");
			else printf("%d\n",(n-9)/4+1);
		}
		else
		{
			if(n<15) printf("-1\n");
			else printf("%d\n",(n-15)/4+2);
		}
	}
}