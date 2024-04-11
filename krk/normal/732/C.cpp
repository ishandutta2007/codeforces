#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

typedef long long ll;

ll a, b, c;

ll Solve(ll a, ll b, ll c, int s, int t)
{
	ll res = 0ll;

	if (c > 0) c--;
	else res++;
	if (s <= 1)
		if (b > 0) b--;
		else res++;
	if (s <= 0)
		if (a > 0) a--;
		else res++;

	if (a > 0) a--;
	else res++;
	if (t >= 1)
		if (b > 0) b--;
		else res++;
	if (t >= 2)
		if (c > 0) c--;
		else res++;
	ll days = max(max(a, b), c);
	res += 3 * days - a - b - c;
	return res;
}

int main()
{
	cin >> a >> b >> c;
	if (a <= 1 && b <= 1 && c <= 1) printf("0\n");
	else {
		ll res = 5000000000000000000ll;
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++) 
				res = min(res, Solve(a, b, c, i, j));
		cout << res << endl;
	}
	return 0;
}