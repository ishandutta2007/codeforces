#include<bits/stdc++.h>

using namespace std;

#define x first
#define y second
#define pb push_back
#define eb emplace_back
#define rep(i,a,b) for(auto i = (a); i != (b); ++i)
#define REP(i,n) rep(i,0,n)
#define all(v) (v).begin(), (v).end()

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

int main() {
	int ntc;
	cin >> ntc;
	while (ntc--) {
		int k;
		cin >> k;

		vi v(k);
		for (auto &x : v) cin >> x;

		int i = 1;
		bool found = false;
		while (i < k) {
			if (abs(v[i] - v[i-1]) >= 2) {
				found = true;
				break;
			}
			i++;
		}
		if (!found) cout << "NO\n";
		else cout << "YES\n" << (i) << " " << (i+1) << endl;
	}
	return 0;
}