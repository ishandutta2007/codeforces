#include <iostream>
using namespace std;
int go(int n,char c)
{
	int cur=0,x=1;
	printf("%c",c);
	while (cur+x<=n)
	{
		printf("%c",c);
		cur+=x;
		x++;
	}
	return cur;
}
int main()
{
	int n;
	scanf("%d",&n);
	char c='a';
	do
	{
		n-=go(n,c);
		c++;
	} while (n);
}