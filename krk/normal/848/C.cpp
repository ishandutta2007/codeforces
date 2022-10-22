#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;
typedef long long ll;

const int Maxn = 100005;
const int Maxm = 524288;

int n, m;
int a[Maxn];
int cur[Maxn];
set <int> S[Maxn];
vector <ii> all;
int qa[Maxn], qb[Maxn], qc[Maxn];
vector <int> st[Maxm];
vector <ll> BIT[Maxm];

void addNew(int v, int l, int r, int a, int b, int val)
{
	if (l == a && r == b) {
		if (st[v].empty() || st[v].back() != val)
			st[v].push_back(val);
	} else {
		int m = l + r >> 1;
		if (a <= m) addNew(2 * v, l, m, a, min(m, b), val);
		if (m + 1 <= b) addNew(2 * v + 1, m + 1, r, max(m + 1, a), b, val);
	}
}

void createBITs(int v, int l, int r)
{
	BIT[v].resize(st[v].size() + 1, 0);
	if (l < r) {
		int m = l + r >> 1;
		createBITs(2 * v, l, m);
		createBITs(2 * v + 1, m + 1, r);
	}
}

ll Get(const vector <ll> &BIT, int ind)
{
	ind++;
	ll res = 0;
	for (int i = ind; i > 0; i -= i & -i)
		res += BIT[i];
	return res;
}

void Update(vector <ll> &BIT, int ind, ll val)
{
	ind++;
	for (int i = ind; i < BIT.size(); i += i & -i)
		BIT[i] += val;
}

void Update(int v, int l, int r, int a, int b, int R, ll val)
{
	if (l == a && r == b) {
		int ind = lower_bound(st[v].begin(), st[v].end(), R) - st[v].begin();
		Update(BIT[v], ind, val);
	} else {
		int m = l + r >> 1;
		if (a <= m) Update(2 * v, l, m, a, min(m, b), R, val);
		if (m + 1 <= b) Update(2 * v + 1, m + 1, r, max(m + 1, a), b, R, val);
	}
}

ll Get(int v, int l, int r, int x, int R)
{
	int ind = upper_bound(st[v].begin(), st[v].end(), R) - st[v].begin() - 1;
	ll res = Get(BIT[v], ind);
	if (l < r) {
		int m = l + r >> 1;
		if (x <= m) res += Get(2 * v, l, m, x, R);
		else res += Get(2 * v + 1, m + 1, r, x, R);
	}
	return res;
}

void Rem(int lef, int rig) { Update(1, 1, n, 1, lef, rig, -(rig - lef)); }

void Add(int lef, int rig) { Update(1, 1, n, 1, lef, rig, rig - lef); }

void Rem(set <int> &S, int ind, bool apply)
{
	auto it = S.find(ind);
	set <int>::iterator lef = it;
	set <int>::iterator rig = it; rig++;
	if (lef != S.begin()) {
		lef--;
		if (apply) Rem(*lef, ind);
		if (rig != S.end())
			if (apply) {
				Rem(ind, *rig);
				Add(*lef, *rig);
			} else all.push_back(ii(*lef, *rig));
	} else if (rig != S.end()) {
		if (apply) Rem(ind, *rig);
	}
	S.erase(it);
}

void Add(set <int> &S, int ind, bool apply)
{
	set <int>::iterator rig = S.upper_bound(ind);
	set <int>::iterator lef = rig;
	if (lef != S.begin()) {
		lef--;
		if (apply) Add(*lef, ind);
		else all.push_back(ii(*lef, ind));
		if (rig != S.end())
			if (apply) {
				Rem(*lef, *rig);
				Add(ind, *rig);
			} else all.push_back(ii(ind, *rig));
	}  else if (rig != S.end())
		if (apply) Add(ind, *rig);
		else all.push_back(ii(ind, *rig));
	S.insert(ind);
}

void Switch(int ind, int val, bool apply)
{
	if (val == cur[ind]) return;
	Rem(S[cur[ind]], ind, apply);
	cur[ind] = val;
	Add(S[cur[ind]], ind, apply);
}

bool Less(const ii &a, const ii &b) { return a.second < b.second; }

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]); cur[i] = a[i];
		if (!S[a[i]].empty())
			all.push_back(ii(*S[a[i]].rbegin(), i));
		S[a[i]].insert(i);
	}
	for (int i = 1; i <= m; i++) {
		scanf("%d %d %d", &qa[i], &qb[i], &qc[i]);
		if (qa[i] == 1) Switch(qb[i], qc[i], false);
	}
	sort(all.begin(), all.end(), Less);
	for (int i = 0; i < all.size(); i++)
		addNew(1, 1, n, 1, all[i].first, all[i].second);
	createBITs(1, 1, n);
	for (int i = 1; i <= n; i++)
		S[i].clear();
	for (int i = 1; i <= n; i++) {
		cur[i] = a[i];
		if (!S[a[i]].empty())
			Add(*S[a[i]].rbegin(), i);
		S[a[i]].insert(i);
	}
	for (int i = 1; i <= m; i++)
		if (qa[i] == 1) Switch(qb[i], qc[i], true);
		else printf("%I64d\n", Get(1, 1, n, qb[i], qc[i]));
	return 0;
}