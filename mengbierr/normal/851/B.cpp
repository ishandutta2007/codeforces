#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
const double eps=1e-10;
int read()
{
	char ch=getchar();int f=0;
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9') {f=f*10+(ch^48);ch=getchar();}
	return f;
}
/*unsigned*/ long long sqr(long long x)
{
	return x*x;
}
int main()
{
	long long ax,ay,bx,by,cx,cy;
	cin>>ax>>ay>>bx>>by>>cx>>cy;
	
	if(ax==bx&&bx==cx)
	{
		puts("No");
		return 0;
	}
	if(ay==by&&by==cy)
	{
		puts("No");
		return 0;
	}
	double q=ax,w=ay,e=bx,r=by,t=cx,y=cy;
	if(sqr(ax-bx)+sqr(ay-by)==sqr(bx-cx)+sqr(by-cy)&&fabs((r-w)/(e-q)-(y-r)/(t-e))>eps)
	cout<<"Yes";
	else cout<<"No";
}