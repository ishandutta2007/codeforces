#include <iostream>
#include <cstdio>
#include <map>
#include <set>
#include <queue>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <functional>
#include <cmath>
#include <ctime>
#include <cassert>

using namespace std;

#define all(v) (v).begin(), (v).end()

using li = long long;
using vi = vector<int>;
void solve();


int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	auto start = clock();
#endif
	cout.sync_with_stdio(0);
	cin.tie(0);
	cout.precision(10);
	cout << fixed;
	int t;
	//cin >> t;
	t = 1;
	while (t--) {
		solve();
	}
#ifdef LOCAL
	cerr << endl << endl << (clock() - start) / double(CLOCKS_PER_SEC) << endl;
#endif
	return 0;
}

//#define int li

auto& in = std::cin;
auto& out = std::cout;

void solve() {
	int n;
	in >> n;
	vector<int> v(n);
	for (int i = 0; i < n; ++i) {
		in >> v[i];
		--v[i];
	}

	struct Query {
		int l, r;
		int id;
	};

	int q;
	in >> q;

	int blockSize = 300;
	int MAGIC = 100000;

	vector<vector<Query>> queries(n / blockSize + 1);
	for (int i = 0; i < q; ++i) {
		Query q;
		in >> q.l >> q.r;
		--q.l;
		q.id = i;
		queries[q.l / blockSize].push_back(q);
	}

	vector<int> cnts(n + 1);
	vector<int> next(n + 2, n + 1);
	vector<int> prev(n + 2, -1);
	vector<int> freq(MAGIC);
	int first = n + 1;

	vector<int> ans(q);


	queue<pair<int, int>> cur, fut;
	auto haf = [&]() {
		//cerr << "test" << endl;
		while (!cur.empty()) {
			cur.pop();
		}
		while (!fut.empty()) {
			fut.pop();
		}

		int pos = first;
		while (pos != n + 1) {
			if (pos > 0) {
				cur.emplace(pos, cnts[pos]);
				//cerr << pos << ' ' << cnts[pos] << endl;
			}
			pos = next[pos];
		}

		int ans = 0;

		cur.emplace(1000000000, 0);

		while (true) {
			int mn = cur.front().first;
			if (!fut.empty()) {
				mn = min(mn, fut.front().first);
			}
			if (mn == 1000000000) {
				break;
			}
			int sum = 0;
			if (cur.front().first == mn) {
				sum += cur.front().second;
				cur.pop();
			}
			if (!fut.empty() && fut.front().first == mn) {
				sum += fut.front().second;
				fut.pop();
			}

			if (sum > 1) {
				ans += (sum / 2) * 2 * mn;
				fut.emplace(2 * mn, sum / 2);
				sum %= 2;
			}
			if (sum == 1) {
				int mn2 = cur.front().first;
				if (!fut.empty()) {
					mn2 = min(mn2, fut.front().first);
				}
				if (mn2 == 1000000000) {
					break;
				}
				if (cur.front().first == mn2) {
					--cur.front().second;
					if (cur.front().second == 0) {
						cur.pop();
					}
				} else {
					--fut.front().second;
					if (fut.front().second == 0) {
						fut.pop();
					}
				}
				ans += mn + mn2;
				fut.emplace(mn2 + mn, 1);
			}
		}

		return ans;

	};

	for (int b = 0; b < queries.size(); ++b) {
		sort(all(queries[b]), [](const Query& y, const Query& u) {
			return y.r < u.r;
		});
		cnts.assign(n + 1, 0);
		next.assign(n + 2, n + 1);
		
		prev.assign(n + 2, -1);
		freq.assign(MAGIC, 0);

		cnts[0] = n + 59;
		first = 0;

		int l = blockSize * b;
		int r = blockSize * b;

		auto add = [&](int val) {
			int oldF = freq[val];
			++freq[val];
			
			int newF = freq[val];
			++cnts[newF];
			if (cnts[newF] == 1) {
				prev[newF] = oldF;
				next[newF] = next[oldF];
				prev[next[oldF]] = newF;
				next[oldF] = newF;
			}

			--cnts[oldF];
			if (cnts[oldF] == 0) {
				prev[newF] = prev[oldF];
				if (prev[oldF] == -1) {
					first = newF;
				}
				else {
					next[prev[oldF]] = newF;
				}
			}
		};

		auto del = [&](int val) {
			int oldF = freq[val];
			--freq[val];

			int newF = freq[val];
			++cnts[newF];
			if (cnts[newF] == 1) {
				prev[newF] = prev[oldF];
				next[newF] = oldF;
				if (prev[oldF] == -1) {
					first = newF;
				} else {
					next[prev[oldF]] = newF;
				}
				prev[oldF] = newF;
			}

			--cnts[oldF];
			if (cnts[oldF] == 0) {
				next[newF] = next[oldF];
				prev[next[oldF]] = newF;
			}
		};

		for (const Query& q : queries[b]) {
			while (l > q.l) {
				--l;
				add(v[l]);
			}
			while (r < q.r) {
				add(v[r]);
				++r;
			}
			while (l < q.l) {
				del(v[l]);
				++l;
			}
			while (r > q.r) {
				--r;
				del(v[r]);
			}
			ans[q.id] = haf();
		}
	}


	for (int x : ans) {
		out << x << "\n";
	}
}