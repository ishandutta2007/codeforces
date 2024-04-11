#include <bits/stdc++.h>

using namespace std;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int n_ = n;
		vector<pair<int, int>> prime_divs;
		for (int i = 2; i * i <= n; i++)
			if (n % i == 0) {
				int cnt = 0;
				while (n % i == 0)
					cnt++, n /= i;
				prime_divs.emplace_back(i, cnt);
			}

		if (n != 1)
			prime_divs.emplace_back(n, 1);

		n = n_;
		vector<int> divs{n};
		for (int i = 2; i * i <= n; i++)
			if (n % i == 0) {
				divs.push_back(i);
				if (i * i != n)
					divs.push_back(n / i);
			}
		assert((int) divs.size() != 1);

		if ((int) prime_divs.size() == 2 && prime_divs[0].second == 1 && prime_divs[1].second == 1) {
			assert((int) divs.size() == 3);
			cout << divs[0] << ' ' << divs[1] << ' ' << divs[2] << '\n';
			cout << "1\n";
			continue;
		}
		if ((int) prime_divs.size() == 2) {
			if (prime_divs[0].second > prime_divs[1].second)
				swap(prime_divs[0], prime_divs[1]);
			int p = prime_divs[0].first;
			int q = prime_divs[1].first;
			int cp = prime_divs[0].second;
			int cq = prime_divs[1].second;
			assert(cq > 1);
			vector<int> all_p;
			{
				int now = p;
				for (int i = 0; i < cp; i++) {
					all_p.push_back(now);
					now *= p;
				}
			}
			vector<int> all_q;
			{
				int now = q;
				for (int i = 0; i < cq; i++) {
					all_q.push_back(now);
					now *= q;
				}
			}
			for (auto x : all_p)
			    cout << x << ' ';
			{
				int now_p = p;
				for (int i = 0; i < cp; i++, now_p *= p) {
					int now_q = q;
					for (int j = 0; j < cq; j++, now_q *= q)
						if (i != 0 || j > 1)
							cout << now_p * now_q << ' ';
				}
			}
			cout << p * q << ' ';
			for (auto x : all_q)
			    cout << x << ' ';
			cout << p * q * q << '\n';
			cout << "0\n";
			continue;
		}
		if ((int) prime_divs.size() == 1) {
			for (auto x : divs)
				cout << x << ' ';
			cout << '\n';
			cout << "0\n";
			continue;
		}

		unordered_map<int, int> index;
		for (int i = 0; i < (int) prime_divs.size(); i++)
			index[prime_divs[i].first] = i;
		vector<vector<int>> ord(prime_divs.size());
		for (int i = 0; i < (int) prime_divs.size(); i++)
			ord[i].push_back(prime_divs[i].first);
		auto find_first = [&](int x) {
			int pos = 0;
			while (pos < (int) prime_divs.size() && x % prime_divs[pos].first)
				pos++;
			assert(pos != (int) prime_divs.size());
			return pos;
		};
		for (auto x : divs) {
			int i = find_first(x);
			int p = prime_divs[i].first;
			if (x == p)
				continue;
			int j = find_first(x / p);
			int q = prime_divs[j].first;
			if (q * p == x && (i + 1 == j || (i == 0 && j == (int) prime_divs.size() - 1)))
				continue;
			int id = index[p];
			ord[id].push_back(x);
		}
		for (auto x : divs) {
			int i = find_first(x);
			int p = prime_divs[i].first;
			if (x == p)
				continue;
			int j = find_first(x / p);
			int q = prime_divs[j].first;
			if (q * p == x && (i + 1 == j || (i == 0 && j == (int) prime_divs.size() - 1))) {
				int id = (j == (int) prime_divs.size() - 1 && i == 0 ? index[q] : index[p]);
				ord[id].push_back(x);
			}
		}

		for (auto xs : ord)
			for (auto x : xs)
				cout << x << ' ';
		cout << '\n';
		cout << "0\n";
	}
}