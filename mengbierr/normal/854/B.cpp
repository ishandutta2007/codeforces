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
	int n=read(),k=read();
	if(k==0)
	{
		cout<<"0 ";
	}
	else if(n<=k)
	{
		cout<<"0 0";
		return 0;
	}
	else
	cout<<"1 ";
	cout<<min(n-k,k*2);
}