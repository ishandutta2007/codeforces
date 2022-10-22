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
	ll res = n * (n - 1) * (n - 2) * (n - 3) * (n - 4) / (1 * 2 * 3 * 4 * 5);
	res += n * (n - 1) * (n - 2) * (n - 3) * (n - 4) * (n - 5) / (1 * 2 * 3 * 4 * 5 * 6);
	res += n * (n - 1) / 2 * (n - 2) / 3 * (n - 3) * (n - 4) / 5 * (n - 5) * (n - 6) / (4 * 6 * 7);
	cout << res << endl;
	return 0;
}