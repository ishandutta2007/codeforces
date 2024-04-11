#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;

ll a, b, c;
ll res;

int main()
{
	cin >> a >> b >> c;
	res = a + b + c - 1ll;
	if (a % 2ll == b % 2ll) res = min(res, max(a, b));
	if (a % 2ll == c % 2ll) res = min(res, max(a, c));
	if (b % 2ll == c % 2ll) res = min(res, max(b, c));
	cout << res << endl;
	return 0;
}