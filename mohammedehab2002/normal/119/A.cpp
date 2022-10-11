#include <iostream>
#include <algorithm>
using namespace std;
int gcd(int x,int y)
{
	int ans,i;
	for (i=1;i<=min(x,y);i++)
	{
		if (x%i==0 && y%i==0)
		ans=i;
	}
	return ans;
}
int main()
{
	int a,b,c,t=0;
	cin >> a >> b >> c;
	again: if (t%2)
	c-=gcd(c,b);
	else
	c-=gcd(c,a);
	if (c>0)
	{
		t++;
		goto again;
	}
	cout << t%2;
}