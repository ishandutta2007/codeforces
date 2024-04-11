#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;
typedef long long ll;

const int Maxn = 200005;

int T;
int n, p;
int a[Maxn];
int lef[Maxn], rig[Maxn];
vector <ii> seq;
int par[Maxn], siz[Maxn];
int L[Maxn], R[Maxn];

int getPar(int x) { return par[x] == x? x: par[x] = getPar(par[x]); }

void unionSet(int a, int b)
{
	a = getPar(a), b = getPar(b);
	if (a == b) return;
	if (siz[a] < siz[b]) swap(a, b);
	siz[a] += siz[b]; par[b] = a;
	L[a] = min(L[a], L[b]);
	R[a] = max(R[a], R[b]);
}

int main()
{
	scanf("%d", &T);
	while (T--) {
		scanf("%d %d", &n, &p);
		seq.clear();
		for (int i = 1; i <= n; i++) {
			scanf("%d", &a[i]);
			par[i] = i; siz[i] = 1;
			L[i] = R[i] = i;
			seq.push_back(ii(a[i], i));
		}
		lef[1] = 1;
		for (int i = 2; i <= n; i++) {
			int nxt = i - 1;
			while (nxt > 0 && a[nxt] % a[i] == 0) nxt = lef[nxt] - 1;
			lef[i] = nxt + 1;
		}
		rig[n] = n;
		for (int i = n - 1; i >= 1; i--) {
			int nxt = i + 1;
			while (nxt <= n && a[nxt] % a[i] == 0) nxt = rig[nxt] + 1;
			rig[i] = nxt - 1;
		}
		ll res = 0;
		sort(seq.begin(), seq.end());
		for (int i = 0; i < seq.size() && seq[i].first < p; i++) {
			int ind = seq[i].second;
			while (L[getPar(ind)] > 1)
				if (lef[ind] <= L[getPar(ind)] - 1) {
					unionSet(L[getPar(ind)] - 1, ind);
					res += seq[i].first;
				} else break;
			while (R[getPar(ind)] < n)
				if (R[getPar(ind)] + 1 <= rig[ind]) {
					unionSet(R[getPar(ind)] + 1, ind);
					res += seq[i].first;
				} else break;
		}
		res -= p;
		for (int i = 1; i <= n; i++)
			if (L[getPar(i)] == i) res += p;
		printf("%I64d\n", res);
	}
    return 0;
}