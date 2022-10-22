#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <string>
#include <cstring>
#include <sstream>
#include <algorithm>
using namespace std;

typedef long long ll;

const int Maxd = 175;

ll n, s;
ll res;

int Sum(ll x)
{
	int res = 0;
	while (x) { res += x % 10; x /= 10; }
	return res;
}

int main()
{
	cin >> n >> s;
	res = min(n, s - 1ll);
	for (int i = 0; i <= Maxd; i++)
		if (s + i <= n && i < Sum(s + i)) res++;
	res = n - res;
	cout << res << endl;
	return 0;
}