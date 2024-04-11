#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

ll n;

int main()
{
	cin >> n;
	ll res1 = 6 * (1ll << 2 * (n - 2));
	ll res2 = (n - 3) * 9 * (1ll << 2 * (n - 3));
	cout << res1 + res2 << endl;
	return 0;
}