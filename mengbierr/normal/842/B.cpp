#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
int read()
{
	char ch=getchar();int f=0;
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9') {f=f*10+(ch^48);ch=getchar();}
	return f;
}
int d,R;
int main()
{
	int n,ans=0;
	d=read(),R=d-read();
	n=read();
	for(int i=1;i<=n;i++)
	{
		double x,y,r;
		scanf("%lf%lf%lf",&x,&y,&r);
		double len=sqrt(x*x+y*y);
		if(len-r>=R&&len+r<=d)
		ans++;
	}
	cout<<ans;
}