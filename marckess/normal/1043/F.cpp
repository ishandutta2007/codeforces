#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb(x) push_back(x)

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 300005, mod = 1e9+7;
int n, a[MX];
ll sum[MX];
bitset<MX> bs[10];

void go (int l) {
	memset(sum, 0, sizeof(sum));

	for (int i = MX-1; i >= 1; i--) {
		ll x = 0, y = 0;

		for (int j = i; j < MX; j += i) {
			x += int(bs[l][j]);
			y += int(bs[0][j]);
			sum[i] += sum[j];
		}

		sum[i] = x * y - sum[i];
		bs[l+1][i] = sum[i];
	}

}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		bs[0][a[i]] = 1;
	}

	for (int i = 0; i < 7; i++) {
		if (bs[i][1]) {
			cout << i+1 << endl;
			return 0;
		}
		if (i + 1 < 7) go(i);
	}

	cout << -1 << endl;

	return 0;
}