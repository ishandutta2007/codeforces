#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <int, int> ii;
typedef pair <int, ii> iii;

const int Maxn = 100005;

int T;
int n;
ll S;
vector <iii> neigh[Maxn];
ll has;
int cnt[Maxn];
vector <ll> A, B;

void Traverse(int v, int p)
{
	if (int(neigh[v].size()) - (v != 1) == 0)
		cnt[v] = 1;
	else {
		cnt[v] = 0;
		for (int i = 0; i < neigh[v].size(); i++) {
			iii u = neigh[v][i];
			if (u.first == p) continue;
			Traverse(u.first, v);
			cnt[v] += cnt[u.first];
			has += ll(cnt[u.first]) * u.second.first;
			while (u.second.first > 0) {
				ll val = ll(u.second.first + 1) / 2ll * ll(cnt[u.first]);
				u.second.first /= 2;
				if (u.second.second == 1) A.push_back(val);
				else B.push_back(val);
			}
		}
	}
}

int main()
{
	scanf("%d", &T);
	while (T--) {
		scanf("%d %I64d", &n, &S);
		for (int i = 1; i <= n; i++)
			neigh[i].clear();
		for (int i = 0; i < n - 1; i++) {
			int a, b, c, d = 1; scanf("%d %d %d", &a, &b, &c);
			neigh[a].push_back(iii(b, ii(c, d)));
			neigh[b].push_back(iii(a, ii(c, d)));
		}
		A.clear();
		B.clear();
		has = 0;
		Traverse(1, 0);
		if (has <= S) { printf("0\n"); continue; }
		sort(A.rbegin(), A.rend());
		sort(B.rbegin(), B.rend());
		ll res = 1000000000000000000ll;
		int pnt = 0;
		ll cand = 0;
		while (pnt < B.size() && has > S) { has -= B[pnt++]; cand += 2; }
		if (has <= S) res = min(res, cand);
		for (int i = 0; i < A.size(); i++) {
			has -= A[i]; cand++;
			while (pnt > 0 && has + B[pnt - 1] <= S) { has += B[--pnt]; cand -= 2; }
			if (has <= S) res = min(res, cand);
		}
		printf("%I64d\n", res);
	}
    return 0;
}