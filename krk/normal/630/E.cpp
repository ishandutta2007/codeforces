#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

const int shift = 1000000002;

ll X1, Y1, X2, Y2;

int main()
{
	cin >> X1 >> Y1 >> X2 >> Y2;
	ll res1 = (X2 - X1) / 2 * (Y2 - Y1) / 2;
	ll res2 = (X2 - X1 + 2) / 2 * (Y2 - Y1 + 2) / 2;
	cout << res1 + res2 << endl;
	return 0;
}