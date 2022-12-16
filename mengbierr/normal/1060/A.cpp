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
int num1,num2,n;
char s[100005];
int main()
{
	n=read();
	scanf("%s",s+1);
	for(int i=1;i<=n;i++)
	{
		if(s[i]=='8') num1++;
		else num2++;
	}
	int ans=min(num1,n/11);
	cout<<ans;
}