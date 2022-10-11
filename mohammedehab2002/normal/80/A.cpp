#include <iostream>
using namespace std;
int main()
{
	int a,b,i,x,ans=0,nextprime=0;
	cin >> a >> b;
	for (i=a+1;i<=b;i++)
	{
		for (x=2;x<=i;x++)
		{
			if (i%x)
			ans++;
		}
		if (ans==i-2)
		{
			nextprime=i;
			break;
		}
		ans=0;
	}
	if (nextprime==b)
	cout << "YES";
	else
	cout << "NO";
}