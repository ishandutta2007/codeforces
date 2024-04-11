#include <iostream>
using namespace std;
typedef long long ll;
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		if (360%(180-n))
		cout << "NO" << endl;
		else
		cout << "YES" << endl;
	}
}