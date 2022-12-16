#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int read()
{
	char ch=getchar();int f=0;
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9')
	{f=(f<<1)+(f<<3)+ch-'0';
	ch=getchar();}
	return f;
}
int main()
{
	long long n,k;
	cin>>n>>k;
	long long x=n/k;
	if(x%2==0)
	printf("NO");
	else printf("YES");
}