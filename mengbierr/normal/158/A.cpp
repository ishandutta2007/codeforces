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
int cmp(const int &x,const int &y)
{
	return x>y;
}
int main()
{
	int n=read(),k=read(),low;
	for(int i=1;i<=n;i++) a[i]=read();
	sort(a+1,a+n+1,cmp);
	if(a[k]>0) low=a[k];
	else low=1;int ans=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i]>=low) ans++;
	}
	cout<<ans;
}