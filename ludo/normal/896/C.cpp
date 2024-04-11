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

const int maxn = 1e5;
ll N, M, vmax, seed;
ll A[maxn];

ll rnd() {
	ll ret = seed;
	seed = (seed * 7LL + 13) % 1000000007LL;
	return ret;
}

const int INIT = 50;

ll powmod(ll b, ll e, ll m)
{
	b %= m;
	ll r = 1;
	while (e) {
		if (e & 1) r = r * b % m;
		e >>= 1;
		b = b * b % m;
	}
	return r;
}

// parts :: left -> (right, value)
map<int, pair<int, ll>> parts;

void partition_array() {
	for (int i = 0; i < N;) {
		int j = i;
		while (j < N && A[j] == A[i]) j++;

		// process [i, j)
		parts[i] = pair<int, ll>(j, A[i]);

		i = j;
	}
}

void flatten() {
	auto it = parts.begin();
	while (it != parts.end()) {
		auto nxtit = it;
		nxtit++;
		if (nxtit != parts.end() && it->y.y == nxtit->y.y) {
			// merge these two
			it->y.x = nxtit->y.x;
			nxtit = parts.erase(nxtit);
		}
		it = nxtit;
	}
}

void split_at(int val) {
	auto it = parts.lower_bound(val);
	if (it == parts.begin() || (it != parts.end() && it->x == val)) return;
	--it;
	assert(it->x < val);
	if (it->y.x <= val) return;
	// split at val
	int r = it->y.x;
	ll v = it->y.y;
	it->y.x = val;
	parts.emplace(val, pair<int, ll>(r, v));
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M >> seed >> vmax;
	for (int i = 0; i < N; i++) {
		// A[i] = rnd();
		A[i] = (rnd() % vmax) + 1;
//		cerr << A[i] << " ";
	}
//	cerr << endl;

	ll ret, x, y;
	for (int q = 1; q <= M; q++) {
		ret = 0;

		int op = (rnd() % 4) + 1, l = rnd() % N, r = rnd() % N;
		if (l > r) swap(l, r);
		r++;

		if (op == 3) x = rnd() % (r - l);
		else         x = (rnd() % vmax) + 1;

		if (op == 4) y = (rnd() % vmax) + 1;

/*		cerr << op << " " << l << " " << r << " " << x << " ";
		if (op == 4) cerr << y;
		cerr << endl;*/
		
		if (q < INIT) {
			if (op == 1) {
				for (int i = l; i < r; i++) A[i] += x;
			} else if (op == 2) {
				for (int i = l; i < r; i++) A[i] = x;
			} else if (op == 3) {
				vector<ll> test(r - l);
				copy(A + l, A + r, test.begin());
				nth_element(test.begin(), test.begin() + x, test.end());
//				for (int i : test) cerr << i << " "; cerr << endl;
				ret = test[x];
			} else {
				for (int i = l; i < r; i++)
					ret = (ret + powmod(A[i], x, y)) % y;
			}
		} else {
			if (q == INIT) partition_array();

			split_at(l);
			split_at(r);
			auto it = parts.lower_bound(l);
			assert(it->x == l);
			if (op == 1) {
				while (it != parts.end() && it->y.x <= r) {
					it->y.y += x;
					++it;
				}
				assert(it == parts.end() || it->x == r);
			} else if (op == 2) {
				while (it != parts.end() && it->y.x <= r) {
					it = parts.erase(it);
				}
				assert(it == parts.end() || it->x == r);
				parts.emplace(l, pair<int, ll>(r, x));
			} else if (op == 3) {
				// quick_select on this one.
				vector<pair<ll, int>> vals;
				while (it != parts.end() && it->y.x <= r) {
					vals.eb(it->y.y, it->y.x - it->x);
					++it;
				}
				assert(it == parts.end() || it->x == r);
				sort(vals.begin(), vals.end());
				int idx = 0;
				while (x >= vals[idx].y) {
					x -= vals[idx].y;
					idx++;
				}
				ret = vals[idx].x;
			} else if (op == 4) {
				// calc powmods
				ret = 0;
				while (it != parts.end() && it->y.x <= r) {
					ll width = (it->y.x - it->x) % y;
					ll aval = it->y.y;
					ret = (ret + powmod(aval, x, y) * width) % y;
					++it;
				}
				assert(it == parts.end() || it->x == r);
			}
			flatten();
		}

		if (op == 3 || op == 4) {
			cout << ret << endl;
		}
//		for (int j = 0; j < N; j++) cerr << A[j] << " "; cerr << endl;
	}

	return 0;
}