#include <iostream>
#include <math.h>
using namespace std;
int main()
{
	int h1,h2,a,b;
	cin >> h1 >> h2 >> a >> b;
	h1+=8*a;
	if (h1>=h2)
	{
		cout << 0;
		return 0;
	}
	if (a<=b)
	{
		cout << -1;
		return 0;
	}
	int c=12*a-12*b;
	int ans=(h2-h1)/c;
	if ((h2-h1)%c)
	ans++;
	cout << ans;
}