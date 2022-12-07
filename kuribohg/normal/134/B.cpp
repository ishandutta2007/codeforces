#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;
int n,ans=2000000000,con;
int gcd(int a,int b)
{
	if(b==0) return a;
	return gcd(b,a%b);
}
void calcgcd(int a,int b)
{
	if(b==0) return;
	con+=a/b;
	calcgcd(b,a%b);
}
int main()
{
	scanf("%d",&n);
	if(n==1) {puts("0");return 0;}
	for(int i=1;i<n;i++)
		if(gcd(i,n)==1)
		{
			con=0;
			calcgcd(n,i);
			ans=min(ans,con);
		}
	printf("%d\n",ans-1);
	return 0;
}