#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
int read()
{
	char ch=getchar();int f=0,x=1;
	while(ch<'0'||ch>'9') {if(ch=='-') x=-1;ch=getchar();}
	while(ch>='0'&&ch<='9') {f=f*10+(ch^48);ch=getchar();}
	return f*x;
}
int x1,y11,x2,y2;
int main()
{
	cin>>x1>>y11>>x2>>y2;
	if(x1==x2)
	{
		cout<<2*(abs(y11-y2)+3);
	}
	else if(y11==y2)
	{
		cout<<2*(abs(x1-x2)+3);
	}
	else 
	{
		cout<<2*(abs(x1-x2)+abs(y11-y2)+2);
	}
}