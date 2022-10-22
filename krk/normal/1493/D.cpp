#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int mod = 1000000007;
const int Maxn = 200005;

int mx[Maxn];
int n, q;
int a[Maxn];
int res = 1;
map <int, int> M[Maxn];
multiset <int> S[Maxn];

void Add(int ind, int pr, int cnt)
{
	int was = S[pr].size() < n? 0: *S[pr].begin();
	auto it = M[ind].find(pr);
	if (it == M[ind].end()) {
		M[ind].insert(make_pair(pr, cnt));
		S[pr].insert(cnt);
	} else {
		S[pr].erase(S[pr].lower_bound(it->second));
		it->second += cnt;
		S[pr].insert(it->second);
	}
	int nw = S[pr].size() < n? 0: *S[pr].begin();
	while (was < nw) {
		res = ll(res) * pr % mod;
		was++;
	}
}

int main()
{
	for (int i = 2; i < Maxn; i++) if (mx[i] == 0)
		for (int j = i; j < Maxn; j += i)
			mx[j] = i;
	scanf("%d %d", &n, &q);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		while (a[i] > 1) {
			int cur = mx[a[i]];
			int cnt = 0;
			while (mx[a[i]] == cur) {
				a[i] /= cur;
				cnt++;
			}
			Add(i, cur, cnt);
		}
	}
	while (q--) {
		int ind, val; scanf("%d %d", &ind, &val);
		while (val > 1) {
			int cur = mx[val];
			int cnt = 0;
			while (mx[val] == cur) {
				val /= cur;
				cnt++;
			}
			Add(ind, cur, cnt);
		}
		printf("%d\n", res);
	}
    return 0;
}