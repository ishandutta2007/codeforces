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
	ll res1 = (n + 4) * (n + 3) * (n + 2) * (n + 1) * n / (1 * 2 * 3 * 4 * 5);
	ll res2 = (n + 2) * (n + 1) * n / (1 * 2 * 3);
	cout << res1 * res2 << endl;
	return 0;
}