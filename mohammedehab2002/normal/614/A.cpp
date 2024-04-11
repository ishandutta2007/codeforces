#include <iostream>
#include <vector>
using namespace std;
int main()
{
	long long l,r,k,p=1;
	bool b=true;
	cin >> l >> r >> k;
	while (p<=r)
	{
		if (p>=l)
		{
			cout << p << ' ';
			b=false;
		}
		if (r/k<p)
		break;
		p*=k;
	}
	if (b)
	cout << -1;
}