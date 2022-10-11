#include <iostream>
using namespace std;
void solve(int n,int g)
{
	if (n==1)
	{
		printf("%d",g);
		return;
	}
	if (n==3)
	{
		printf("%d %d %d",g,g,3*g);
		return;
	}
	for (int i=1;i<=n;i+=2)
	printf("%d ",g);
	solve(n/2,g*2);
}
int main()
{
	int n;
	scanf("%d",&n);
	solve(n,1);
}