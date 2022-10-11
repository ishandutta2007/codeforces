#include <iostream>
using namespace std;
string ask(int x)
{
	cout << x << ' ' << 1 << endl;
	fflush(stdout);
	string ans;
	cin >> ans;
	return ans;
}
int main()
{
	int n;
	cin >> n;
	string init=ask(0);
	int st=0,en=1e9-1;
	while (--n)
	{
		int mid=(st+en)/2;
		if (ask(mid)==init)
		st=mid;
		else
		en=mid;
	}
	cout << st << ' ' << 0 << ' ' << st+1 << ' ' << 2 << endl;
	fflush(stdout);
}