#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n;
bool is_prime(int n)
{
	if(n==1) return false;
	for(int i=2;i*i<=n;i++)
		if(n%i==0) return false;
	return true;
}
int x,y;
int main()
{
	scanf("%d",&n);
	for(int i=n;i>=1;i--)
		if(is_prime(i)) {x=i;break;}
	y=n-x;
	if(y==0) {puts("1");printf("%d\n",n);return 0;}
	if(y==2) {puts("2");printf("%d 2\n",n-2);return 0;}
	for(int i=1;i<y;i++)
		if(is_prime(i)&&is_prime(y-i))
		{
			puts("3");
			printf("%d %d %d\n",x,i,y-i);
			return 0;
		}
	return 0;
}