#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define x first
#define y second
#define pb push_back
#define eb emplace_back

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	(cout << fixed).precision(7);

	ll sum = 0;

	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		ll x;
		cin >> x;
		int weight = min(min(k, n - k + 1), min(i + 1, n - i));
		// int weight = 1;
		sum += 1LL * weight * x;
	}
	long double ret = 1.0;
	ret *= sum;
	ret /= (n - k + 1);
	cout << ret << endl;
	return 0;
}