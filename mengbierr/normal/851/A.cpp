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
int n,k,t;
int main()
{
	n=read(),k=read(),t=read();
	if(t<=k)
	{
		cout<<t;
		return 0;
	}
	else if(t<=n)
	{
		cout<<k;
		return 0;
	}
	else
	{
		cout<<n+k-t;
		return 0;
	}
}