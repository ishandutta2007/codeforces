#include <bits/stdc++.h>

using namespace std;

typedef long long int64;
typedef vector<int> vi;
typedef pair<int,int> pii;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;
const int maxn = 100010;

bool check(int i, int v1, int v2){
	if (i % 2 == 0 && v1 >= v2) return false;
	if (i % 2 == 1 && v1 <= v2) return false;
	return true;
}

bool ok(vi &v, vi &e, int a, int b){
	if (a) if (!check(a - 1, v[a - 1], v[a])) return false;
	if (a + 1 < (int)v.size()) if (!check(a, v[a], v[a + 1])) return false;
	if (b) if (!check(b - 1, v[b - 1], v[b])) return false;
	if (b + 1 < (int)v.size()) if (!check(b, v[b], v[b + 1])) return false;

	for (auto i : e)
		if (!check(i, v[i], v[i + 1])) return false;

	return true;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n; cin >> n;
	vi v(n);

	vi bad;

	for (int i = 0; i < n; ++i){
		cin >> v[i];
		if (i){
			if (i % 2 == 0 && v[i] >= v[i - 1])
				bad.push_back(i - 1);
			if (i % 2 == 1 && v[i] <= v[i - 1])
				bad.push_back(i - 1);
		}
	}

	if (bad.size() >= 5)
		cout << 0 << endl;
	else{
		set<pii> s;
		for (auto i : bad){
			for (int k = 0; k < 2; ++k){
				int p = i + k;

				for (int j = 0; j < n; ++j){
					if (j == p) continue;
					swap(v[p], v[j]);
					if (ok(v, bad, j, p)) s.insert({min(p, j), max(p, j)});
					swap(v[p], v[j]);
				}
			}
		}

		cout << s.size() << endl;
	}

	return 0;
}