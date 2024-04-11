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
int main()
{
	int a,b,c,ans=0;
	cin>>a>>b>>c;
	for(int i=1;i<=a;i++)
	{
		if(i+1<=b&&i+2<=c)
		{
			ans=3*i+3;
		}
		else break;
	}
	cout<<ans;
}