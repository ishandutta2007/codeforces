#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <string>
#include <cstring>
#include <sstream>
#include <algorithm>
#pragma comment(linker, "/STACK:16000000")
using namespace std;

typedef long long ll;
typedef pair <int, int> ii;
typedef pair <ll, int> lli;

const int Maxn = 200005;
const ll Inf = 1000000000000000000ll;

int n;
int a[Maxn], b[Maxn], c[Maxn];
vector <ii> neigh[Maxn];
int tk[Maxn], par[Maxn], parind[Maxn];
bool inloop[Maxn];
int slen, seq[Maxn];
ll w[Maxn];
ll H[Maxn], T[Maxn];
set <lli> upp, low;
ll old[Maxn];
ll forsure;
ll res = Inf;

bool Traverse(int v, int p, int ind)
{
	if (tk[v] == 1) {
		int u = p; seq[slen] = u; w[slen] = c[ind]; inloop[ind] = true; slen++;
		while (u != v) {
			ind = parind[u];
			u = par[u]; seq[slen] = u; w[slen] = c[ind]; inloop[ind] = true; slen++;
		}
		return true;
	} else if (tk[v] == 2) return false;
	tk[v] = 1;
	par[v] = p; parind[v] = ind;
	for (int i = 0; i < neigh[v].size(); i++) if (neigh[v][i].first != par[v])
		if (Traverse(neigh[v][i].first, v, neigh[v][i].second)) return true;
	tk[v] = 2;
	return false;
}

void Solve(int v, int p = -1)
{
	for (int i = 0; i < neigh[v].size(); i++) {
		ii u = neigh[v][i];
		if (u.first == p || inloop[u.second]) continue;
		Solve(u.first, v);
		T[v] = max(T[v], H[v] + H[u.first] + c[u.second]);
		T[v] = max(T[v], T[u.first]);
		H[v] = max(H[v], H[u.first] + c[u.second]);
	}
}

ll Get()
{
	set <lli>::iterator it = upp.end(); it--;
	set <lli>::iterator it2 = low.begin();
	if (it->second != it2->second) return it->first - it2->first;
	it--;
	ll best = it->first - it2->first;
	it++;
	it2++;
	best = max(best, it->first - it2->first);
	return best;
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d %d", &a[i], &b[i], &c[i]);
		neigh[a[i]].push_back(ii(b[i], i));
		neigh[b[i]].push_back(ii(a[i], i));
	}
	Traverse(1, -1, -1);
	for (int i = 0; i < slen; i++) {
		Solve(seq[i]);
		forsure = max(forsure, T[seq[i]]);
	}
	ll cur = 0;
	for (int i = 0; i < slen; i++) {
		cur += w[i];
		old[i] = cur;
		upp.insert(lli(cur + H[seq[i]], seq[i]));
		low.insert(lli(cur - H[seq[i]], seq[i]));
	}
	for (int i = 0; i < slen; i++) {
		res = min(res, max(forsure, Get()));
		upp.erase(lli(old[i] + H[seq[i]], seq[i]));
		low.erase(lli(old[i] - H[seq[i]], seq[i]));
		cur += w[i];
		upp.insert(lli(cur + H[seq[i]], seq[i]));
		low.insert(lli(cur - H[seq[i]], seq[i]));
	}
	printf("%I64d\n", res);
	return 0;
}