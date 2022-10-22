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

int n;

ll Pos(ll p, ll pw, ll extr)
{
	ll res = 0;
	for (ll i = 0; i < p; i++) {
		ll lft = 9 - i;
		if (lft < i) {
			res += pw;
			if (lft == 0) res--;
		}
	}
	ll lft = 9 - p;
	if (lft < p) {
		res += extr + 1;
		if (lft == 0 && extr == pw - 1) res--;
	}
	return res;
}

ll Imp(ll p, ll pw, ll extr)
{
	if (pw == 1) { return p * (p - 1) / 2; }
	ll res = (pw * p * p - 2 * p) / 2;
	res += (extr + 1) * p;
	if (pw > 1) {
		pw /= 10;
		res += Pos(extr / pw, pw, extr % pw);
	}
	return res;
}

int main()
{
	cin >> n;
	int num = n, pw = 1;
	while (num >= 10) { pw *= 10; num /= 10; }
	if (num < 5) printf("%I64d\n", Imp(num, pw, n % pw));
	else printf("%I64d\n", Pos(num, pw, n % pw));
	return 0;
}