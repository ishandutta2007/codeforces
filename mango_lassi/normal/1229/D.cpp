#include <iostream>
#include <vector>
#include <algorithm>
#include <array>
using namespace std;
using ll = long long;

const int K = 5;
const int C = 120; // = K!
const int N = 2 * (int)1e5;
int app[N][C];
int trick[N];
int comb[C][C];

int getInd(array<int, K> perm) {
	int fact = 5*4*3*2*1;
	int res = 0;
	for (int i = 0; i < K; ++i) {
		fact /= (K-i);
		for (int j = 0; j < perm[i]; ++j) res += fact;
		for (int j = i+1; j < K; ++j) {
			if (perm[j] > perm[i]) --perm[j];
		}
	}
	return res;
}
array<int, K> getPerm(int ind) {
	int fact = 5*4*3*2*1;
	array<int, K> res;
	for (int i = 0; i < K; ++i) {
		fact /= (K - i);
		for (res[i] = 0; ind >= fact; ++res[i]) ind -= fact;
	}

	vector<bool> used(K, false);
	for (int i = 0; i < K; ++i) {
		for (int j = 0; j <= res[i]; ++j) {
			if (used[j]) ++res[i];
		}
		used[res[i]] = true;
	}
	return res;
}
array<int, K> apply(const array<int, K>& a, const array<int, K>& b) {
	array<int, K> res;
	for (int i = 0; i < K; ++i) res[i] = a[b[i]];
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	for (int c1 = 0; c1 < C; ++c1) {
		for (int c2 = 0; c2 < C; ++c2) {
			array<int, K> p1 = getPerm(c1);
			array<int, K> p2 = getPerm(c2);
			array<int, K> p3 = apply(p1, p2);
			comb[c1][c2] = getInd(p3);
		}
	}

	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; ++i) {
		array<int, K> perm;
		for (int j = 0; j < k; ++j) {
			cin >> perm[j];
			--perm[j];
		}
		for (int j = k; j < K; ++j) perm[j] = j;
		trick[i] = getInd(perm);
	}

	for (int c = 0; c < C; ++c) app[n-1][c] = n;
	app[n-1][trick[n-1]] = n-1;

	for (int i = n-2; i >= 0; --i) {
		for (int c = 0; c < C; ++c) app[i][c] = app[i+1][c];
		app[i][trick[i]] = i;
	}
	
	ll res = 0;
	for (int i = 0; i < n; ++i) {
		vector<bool> act(C, false);
		vector<int> que = {0};
		vector<int> gens;
		act[0] = true; // identity

		int cur = i;
		while(cur < n) {
			int nxt = n;
			for (int c = 0; c < C; ++c) {
				if (! act[c]) nxt = min(nxt, app[cur][c]);
			}
			res += (ll)(nxt - cur) * que.size();

			cur = nxt;
			if (cur < n) {
				gens.push_back(trick[cur]);
				for (int j = 0; j < que.size(); ++j) {
					for (auto v : gens) {
						int t = comb[que[j]][v];
						if (act[t] == false) {
							act[t] = true;
							que.push_back(t);
						}
					}
				}
			}
		}
	}
	cout << res << '\n';
}