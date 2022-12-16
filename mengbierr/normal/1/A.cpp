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
	long long n,m,a;
	cin>>n>>m>>a;
	long long x=n/a+(n%a?1:0),y=m/a+(m%a?1:0);
	cout<<x*y;
}