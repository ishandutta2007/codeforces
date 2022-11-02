#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define x first
#define y second
#define pb push_back
#define eb emplace_back

const int maxn = 1e5;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	vi a(n);
	ll hsum = 0, csum = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		hsum += a[i];
	}

	if (hsum & 1) {
		cout << "NO" << endl;
		return 0;
	}
	hsum /= 2;

	set<ll> seen;
	map<ll, int> unseen;
	for (int i = 0; i < n; i++) {
		unseen[a[i]]++;
	}
	seen.insert(0);
	for (int i = 0; i < n; i++) {
		csum += a[i];
		seen.insert(a[i]);
		unseen[a[i]]--;

		if (seen.find(csum - hsum) != seen.end() || unseen[hsum - csum] > 0) {
			cout << "YES" << endl;
			return 0;
		}
	}
	cout << "NO" << endl;
	return 0;
}