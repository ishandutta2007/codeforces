#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int64 oo = 100000000000000000LL;
const double eps = 1e-9;
const int maxn = 100000 + 10;

int64 phi(int64 n)
{
	int64 ans = n;

	for (int64 x = 2; x * x <= n; ++x)
		if (n % x == 0)
		{
			ans -= ans / x;
			while (n % x == 0)
				n /= x;
		}

	if (n > 1)
		ans -= ans / n;

	return ans;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int64 a, b;

	cin >> a >> b;

	b = (b + 1) / 2;

	while (b-- && a > 1)
		a = phi(a);

	cout << a % 1000000007 << endl;

	return 0;
}