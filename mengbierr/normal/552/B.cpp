#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int read()
{
	char ch=getchar();int f=0;
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9'){f=(f<<1)+(f<<3)+ch-'0';ch=getchar();}
	return f;
}
int main()
{
	int temp=9;long long ans=0;
	int n=read();
	while(n>0)
	{
		ans+=n;
		n-=temp;
		temp*=10;
	}
	cout<<ans;
}