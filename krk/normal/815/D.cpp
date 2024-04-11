#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;
typedef long long ll;

const int Maxn = 500005;

int n, A, B, C;
vector <ii> seq[Maxn];
map <int, int> M;
ll cur;
ll res;

void Add(int key, int val)
{
	auto it = M.lower_bound(key);
	if (it != M.end() && it->second >= val) return;
	it = M.upper_bound(key);
	int from = key;
	int oldval = it == M.end()? 0: it->second;
	while (it != M.begin()) {
		it--;
		cur += ll(val - oldval) * (from - it->first);
		if (it->second > val) { M.insert(make_pair(key, val)); return; }
		from = it->first; oldval = it->second;
		M.erase(it++);
	}
	cur += ll(val - oldval) * from;
	M.insert(make_pair(key, val));
}

int main()
{
	scanf("%d %d %d %d", &n, &A, &B, &C);
	for (int i = 0; i < n; i++) {
		int a, b, c; scanf("%d %d %d", &a, &b, &c);
		seq[A].push_back(ii(b, c));
		seq[a].push_back(ii(B, c));
		seq[a].push_back(ii(b, C));
	}
	res = ll(A) * B * C;
	for (int i = A; i > 0; i--) {
		for (int j = 0; j < seq[i].size(); j++)
			Add(seq[i][j].first, seq[i][j].second);
		res -= cur;
	}
	cout << res << endl;
    return 0;
}