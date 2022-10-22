#include <bits/stdc++.h>
#define x first
#define y second
#define sz(a) int((a).size())
#define par pair<int, int>
#define pb push_back
#define eb emplace_back
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef double db;
const int N = 100 + 10;

ll ask(int l, int r) {
	cout << "? " << l <<" " << r << endl;
	ll res;
	cin >> res;
	return res;
}

void solve() {
	int n;
	cin >> n;
	int l = 1, r = n, best = -1;
	while(l <= r) {
		int mid = (l + r) / 2;
		if(ask(1, mid) > 0) best = mid, r = mid - 1;
		else l = mid + 1;
	}
	best--;
	ll sum1 = ask(best, n), sum2 = ask(best + 1, n);
	int len1 = sum1 - sum2 + 1;
	best += len1;
	sum1 = ask(best, n), sum2 = ask(best + 1, n);
	int len2 = sum1 - sum2 + 1;
	cout << "! " << best - len1 <<" " << best <<" " << best + len2 - 1 << endl;
	return;
}

int main() {
	int T;
	for(cin >> T; T--; solve());
	return 0;
}