#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n, m, a, b;

int main()
{
	cin >> n >> m >> a >> b;
	ll nd = n / m * m;
	ll res = b * (n - nd);
	nd += m;
	res = min(res, a * (nd - n));
	cout << res << endl;
	return 0;
}