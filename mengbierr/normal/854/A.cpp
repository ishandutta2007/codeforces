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
int gcd(int a,int b)
{
	return !b?a:gcd(b,a%b);
}
int main()
{
	int n,maxx=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		if(i>=(n-i))
		break;
		if(gcd(i,n-i)==1&&(double)((double)i/(double)(n-i))>(double)((double)maxx/(double)(n-maxx)))
		{
			maxx=i;
		}
	}
	cout<<maxx<<" "<<n-maxx;
}