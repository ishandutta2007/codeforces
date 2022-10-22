#include <cstdio>
#include <vector>
#include <map>
#include <algorithm>
#pragma comment(linker, "/STACK:16000000")
using namespace std;

typedef long long ll;
typedef pair <int, int> ii;

const int Maxn = 200005;
const int Maxm = 1048576;
const int Inf = 2000000000;

int n, m;
ll x[Maxn], t[Maxn], e[Maxn];
ll p[Maxn], b[Maxn];
vector <ll> un;
map <int, int> fid, mid;
int fl[Maxm], mn[Maxm];
int mos[Maxm];
vector <int> toind[Maxn];

void Create(int v, int l, int r)
{
	fl[v] = mn[v] = Inf;
	if (l < r) {
		int m = l + r >> 1;
		Create(2 * v, l, m); Create(2 * v + 1, m + 1, r);
	}
}

void Down(int v)
{
	if (fl[v] != Inf) {
		fl[2 * v] = min(fl[2 * v], fl[v]); mn[2 * v] = min(mn[2 * v], fl[v]);
		fl[2 * v + 1] = min(fl[2 * v + 1], fl[v]); mn[2 * v + 1] = min(mn[2 * v + 1], fl[v]);
		fl[v] = Inf;
	}
}

void Union(int v)
{
	mn[v] = min(mn[2 * v], mn[2 * v + 1]);
}

void Update(int v, int l, int r, int a, int b, int x)
{
	if (l == a && r == b) { fl[v] = min(fl[v], x); mn[v] = min(mn[v], x); }
	else {
		Down(v);
		int m = l + r >> 1;
		if (a <= m) Update(2 * v, l, m, a, min(m, b), x);
		if (m + 1 <= b) Update(2 * v + 1, m + 1, r, max(m + 1, a), b, x);
		Union(v);
	}
}

int Get(int v, int l, int r, int x)
{
	if (l == r) return mn[v];
	else {
		Down(v);
		int m = l + r >> 1;
		return x <= m? Get(2 * v, l, m, x): Get(2 * v + 1, m + 1, r, x);
	}
}

void updateMos(int v, int l, int r, int x, int add)
{
	mos[v] += add;
	if (l < r) {
		int m = l + r >> 1;
		if (x <= m) updateMos(2 * v, l, m, x, add);
		else updateMos(2 * v + 1, m + 1, r, x, add);
	}
}

int getMos(int v, int l, int r, int a, int b)
{
	if (l == a && r == b && mos[v] == 0) return -1; 
	if (l == r) return l;
	else {
		int m = l + r >> 1;
		int res = -1;
		if (res == -1 && a <= m) res = getMos(2 * v, l, m, a, min(m, b));
		if (res == -1 && m + 1 <= b) res = getMos(2 * v + 1, m + 1, r, max(m + 1, a), b);
		return res;
	}
}

void updateFrog(int f)
{
	int lef = lower_bound(un.begin(), un.end(), x[f]) - un.begin();
	int rig = upper_bound(un.begin(), un.end(), x[f] + t[f]) - un.begin() - 1;
	if (lef <= rig) {
		int mind = getMos(1, 0, un.size() - 1, lef, rig);
		if (mind != -1) {
			e[f]++; t[f] += toind[mind].back(); toind[mind].pop_back();
			updateMos(1, 0, un.size() - 1, mind, -1);
			updateFrog(f);
		} else Update(1, 0, un.size() - 1, lef, rig, x[f]);
	}
}

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%I64d %I64d", &x[i], &t[i]);
		fid[x[i]] = i;
	}
	for (int i = 1; i <= m; i++) {
		scanf("%I64d %I64d", &p[i], &b[i]);
		un.push_back(p[i]);
	}
	sort(un.begin(), un.end()); un.erase(unique(un.begin(), un.end()), un.end());
	Create(1, 0, un.size() - 1);
	for (int i = 1; i <= n; i++)
		updateFrog(i);
	for (int i = 1; i <= m; i++) {
		int ind = lower_bound(un.begin(), un.end(), p[i]) - un.begin();

		int fx = Get(1, 0, un.size() - 1, ind);
		if (fx != Inf) {
			int fr = fid[fx];
			e[fr]++; t[fr] += b[i];
			updateFrog(fr);
		} else { 
			toind[ind].push_back(b[i]);
			updateMos(1, 0, un.size() - 1, ind, 1);
		}
	}
	for (int i = 1; i <= n; i++)
		printf("%I64d %I64d\n", e[i], t[i]);
	return 0;
}