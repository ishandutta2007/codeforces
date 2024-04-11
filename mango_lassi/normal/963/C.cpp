#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;

template<class T>
int bins(const vector<T>& vec, T v) {
	int low = 0;
	int high = (int)vec.size() - 1;
	while(low != high) {
		int mid = (low + high) >> 1;
		if (vec[mid] < v) low = mid + 1;
		else high = mid;
	}
	return low;
}

ll gcd(ll a, ll b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

const int N = 2 * (int)1e5;
ll cou[N];
ll row_gcd[N];
ll col_gcd[N];
ll tot_gcd;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	vector<ll> h_col(n);
	vector<ll> w_col(n);
	vector<pair<pair<ll, ll>, ll>> vec(n);
	for (int i = 0; i < n; ++i) {
		cin >> h_col[i];
		cin >> w_col[i];
		ll c;
		cin >> c;
		vec[i] = {{h_col[i], w_col[i]}, c};
	}

	sort(h_col.begin(), h_col.end());
	sort(w_col.begin(), w_col.end());
	h_col.erase(unique(h_col.begin(), h_col.end()), h_col.end());
	w_col.erase(unique(w_col.begin(), w_col.end()), w_col.end());

	int h = h_col.size();
	int w = w_col.size();
	if (h*w != n) {
		cout << "0\n";
	} else {
		for (int y = 0; y < h; ++y) {
			for (int x = 0; x < w; ++x) {
				cou[x+y*w] = -1;
			}
		}
		for (int i = 0; i < n; ++i) {
			int y = bins(h_col, vec[i].first.first);
			int x = bins(w_col, vec[i].first.second);
			ll c = vec[i].second;
			cou[x+y*w] = c;
			row_gcd[y] = gcd(row_gcd[y], c);
			col_gcd[x] = gcd(col_gcd[x], c);
			tot_gcd = gcd(tot_gcd, c);
		}
		// c_{x,y} = a_{y} * b_{x} = (row_gcd[y]/tot_gcd) * (col_gcd[x]/tot_gcd) * tot_gcd
		for (int y = 0; y < h; ++y) row_gcd[y] /= tot_gcd;
		for (int x = 0; x < w; ++x) col_gcd[x] /= tot_gcd;

		bool fail = false;
		for (int y = 0; y < h; ++y) {
			for (int x = 0; x < w; ++x) {
				ll tmp = cou[x+y*w];

				if (tmp % row_gcd[y] != 0) fail = true;
				else tmp /= row_gcd[y];

				if (tmp % col_gcd[x] != 0) fail = true;
				else tmp /= col_gcd[x];

				if (tmp != tot_gcd) fail = true;
			}
		}
		if (fail) {
			cout << "0\n";
		} else {
			ll divs = 0;
			for (ll i = 1; i*i <= tot_gcd; ++i) {
				if (tot_gcd % i == 0) {
					if (i*i == tot_gcd) divs += 1;
					else divs += 2;
				}
			}
			cout << divs << '\n';
		}
	}
}