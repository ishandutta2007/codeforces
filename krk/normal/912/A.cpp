#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <string>
#include <cstring>
#include <sstream>
#include <queue>
#include <iomanip>
#include <algorithm>
using namespace std;

typedef long long ll;

ll A, B;
ll x, y, z;
ll res;

int main()
{
	cin >> A >> B;
	cin >> x >> y >> z;
	ll needA = 2 * x + y;
	ll needB = y + 3 * z;
	if (needA > A) res += needA - A;
	if (needB > B) res += needB - B;
	cout << res << endl;
	return 0;
}