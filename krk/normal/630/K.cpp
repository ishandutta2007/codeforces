#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

ll n;

ll F(ll x) { return n / x; }

int main()
{
	cin >> n;
	ll res = n - F(2) - F(3) - F(5) - F(7) + F(2 * 3) + F(2 * 5) + F(2 * 7) + F(3 * 5) + F(3 * 7) + F(5 * 7) -
		     F(2 * 3 * 5) - F(2 * 3 * 7) - F(2 * 5 * 7) - F(3 * 5 * 7) + F(2 * 3 * 5 * 7);
	cout << res << endl;
	return 0;
}