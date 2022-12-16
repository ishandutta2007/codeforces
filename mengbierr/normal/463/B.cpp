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
int a[100005];
int main()
{
	int n=read();
	for(int i=1;i<=n;i++)
	a[i]=read();
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		ans=max(ans,a[i]);
	}
	cout<<ans;
}