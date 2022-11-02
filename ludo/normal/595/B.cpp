#include <bits/stdc++.h>

using namespace std;

#define INF 2147483647
#define MOD 1000000007
#define MAX 100010

typedef long long ll;
typedef pair<int, int> pii;

ostream& operator<<(ostream &out, const pii &a) { return out << '(' << a.first << ", " << a.second << ')'; }
istream& operator>>(istream &in, pii &a) { return in >> a.first >> a.second; }

int n, k, m;
int a[MAX], b[MAX];

// limit inclusive

int main()
{
#ifdef LOCAL
//    assert(freopen("input.txt", "r", stdin));
#else
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
#endif // LOCAL

	cin >> n >> k;
	m = n / k;
	for (int i = 0; i < m; i++) cin >> a[i];
	for (int i = 0; i < m; i++) cin >> b[i];

	ll powK = 1;
	for (int i = 0; i < k; i++) powK *= 10;

	ll answer = 1;

	for (int i = 0; i < m; i++) {
		ll local = (powK - 1) / a[i] + 1;
		if (b[i] == 0) {
			local -= (powK / 10 - 1) / a[i] + 1;
		} else {
			local -= (powK / 10 * (b[i] + 1) - 1) / a[i];
			local += (powK / 10 * b[i] - 1) / a[i];
		}

//		cerr << "LOCAL: " << local << " - " << (powK / a[i]) << endl;
//		cerr << " " << ((powK / 10 * (b[i] + 1) - 1) / a[i]) << endl;

		answer *= local;
		answer %= MOD;
	}
	cout << answer << endl;
    return 0;
}