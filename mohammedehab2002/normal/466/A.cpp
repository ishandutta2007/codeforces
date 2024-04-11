#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;
int main()
{
	int a,b,c,d;
	cin >> a >> b >> c >> d;
	if (b*c<=d)
	cout << a*c;
	else
	{
		int ans=0;
		ans+=a/b*d;
		a-=a/b*b;
		if (a)
		ans+=min(d,a*c);
		cout << ans;
	}
}