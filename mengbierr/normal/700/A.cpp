#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long
#define inline  __attribute__((always_inline))
using namespace std;
int read()
{
	char ch=getchar();int f=0,x=1;
	while(ch<'0'||ch>'9'){if(ch=='-') x=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){f=(f<<1)+(f<<3)+ch-'0';ch=getchar();}
	return f*x;
}
int main()
{
	double l,v1,v2;int n,k;
	n=read();l=read();v1=read();v2=read();k=read();
	k=n/k+(n%k?1:0);
	double k1=k;
	double y=(v2-v1)*l/(v2*v2-v1*(v2-2*(k1-1)*(v2-v1)*v2/(v1+v2)));
	double x=(l-v2*y)/v1;
	printf("%.10lf",x+y);
	
}