#include <map>
#include <set>
#include <cmath>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
#pragma comment(linker, "/STACK:16000000")
using namespace std;

typedef long long ll;

const int mod1 = 1000000007;
const int mod2 = 1000000009;
const int arg1 = 41;
const int arg2 = 1000007;
const int Maxn = 300005;

typedef pair <int, int> ii;
typedef pair <int, char> ic;

int n;
vector <ic> neigh[Maxn];
ii fir[Maxn], sec[Maxn];
ii firinv[Maxn], secinv[Maxn];
map <ii, int> my[Maxn];
int par[Maxn]; 
int res[Maxn];

int Inv(int a, int mod)
{
	int p = mod - 2;
	int res = 1;
	while (p) {
		if (p & 1) res = ll(res) * a % mod;
		p >>= 1; a = ll(a) * a % mod;
	}
	return res;
}

int Conv(int my, int mod, const ii &apply, const ii &go)
{
	my = (ll(my) * apply.first + ll(apply.second)) % mod;
	my = (my + go.second) % mod;
	my = ll(my) * go.first % mod;
	return my;
}

void Rem(map <ii, int> &M, const ii &h, int val)
{
	map <ii, int>::iterator it = M.find(h);
	if (it->second == val) M.erase(it);
	else it->second -= val;
}

void Add(int v, char ch)
{
	fir[par[v]].first = ll(fir[par[v]].first) * arg1 % mod1;
	fir[par[v]].second = (ll(fir[par[v]].second) * arg1 + ll(ch - 'a' + 1)) % mod1;
	sec[par[v]].first = ll(sec[par[v]].first) * arg2 % mod2;
	sec[par[v]].second = (ll(sec[par[v]].second) * arg2 + ll(ch - 'a' + 1)) % mod2;
	firinv[par[v]].first = Inv(fir[par[v]].first, mod1);
	firinv[par[v]].second = (mod1 - fir[par[v]].second) % mod1;
	secinv[par[v]].first = Inv(sec[par[v]].first, mod2);
	secinv[par[v]].second = (mod2 - sec[par[v]].second) % mod2;
}

void Traverse(int v, int p = 0, int l = 0)
{
	res[l]++;
	par[v] = v; fir[v].first = firinv[v].first = 1; sec[v].first = secinv[v].first = 1;
	for (int i = 0; i < neigh[v].size(); i++) {
		ic u = neigh[v][i];
		if (u.first == p) continue;
		Traverse(u.first, v, l + 1);
		if (my[par[u.first]].size() > my[par[v]].size()) par[v] = par[u.first];
	}
	for (int i = 0; i < neigh[v].size(); i++) {
		ic u = neigh[v][i];
		if (u.first == p || par[u.first] == par[v]) continue;
		for (map <ii, int>::iterator it = my[par[u.first]].begin(); it != my[par[u.first]].end(); it++) {
			ii h = ii(Conv(it->first.first, mod1, fir[par[u.first]], firinv[par[v]]), 
					  Conv(it->first.second, mod2, sec[par[u.first]], secinv[par[v]]));
			res[l + 1] += my[par[v]][h] > 0;
			my[par[v]][h] += it->second;
		}
	}
	char ch = '?';
	for (int i = 0; i < neigh[v].size(); i++) {
		ic u = neigh[v][i];
		if (u.first == p) continue;
		if (par[u.first] == par[v]) { ch = u.second; continue; }
		for (map <ii, int>::iterator it = my[par[u.first]].begin(); it != my[par[u.first]].end(); it++) {
			ii h = ii(Conv(it->first.first, mod1, fir[par[u.first]], firinv[par[v]]), 
					  Conv(it->first.second, mod2, sec[par[u.first]], secinv[par[v]]));
			Rem(my[par[v]], h, it->second);
		}
	}
	if (ch != '?') {
		ii newh = ii(Conv(0, mod1, ii(0, 0), firinv[par[v]]), Conv(0, mod2, ii(0, 0), secinv[par[v]]));
		my[par[v]][newh]++;
		Add(v, ch);
	}
	for (int i = 0; i < neigh[v].size(); i++) {
		ic u = neigh[v][i];
		if (u.first == p || par[u.first] == par[v]) continue;
		ii newh = ii(Conv(0, mod1, ii(0, 0), firinv[par[u.first]]), Conv(0, mod2, ii(0, 0), secinv[par[u.first]]));
		my[par[u.first]][newh]++;
		Add(u.first, u.second);
		for (map <ii, int>::iterator it = my[par[u.first]].begin(); it != my[par[u.first]].end(); it++) {
			ii h = ii(Conv(it->first.first, mod1, fir[par[u.first]], firinv[par[v]]), 
					  Conv(it->first.second, mod2, sec[par[u.first]], secinv[par[v]]));
			my[par[v]][h] += it->second;
		}
	}
/*	printf("res[%d] = %d\n", l, res[l]);
	printf("v = %d\n", v);
	printf("fir = (%d, %d)\n", fir[par[v]].first, fir[par[v]].second);
	printf("sec = (%d, %d)\n", sec[par[v]].first, sec[par[v]].second);
	for (map <ii, int>::iterator it = my[par[v]].begin(); it != my[par[v]].end(); it++)
		printf(" (%d, %d) (%d)\n", it->first.first, it->first.second, it->second);*/
}

int main() 
{
	scanf("%d", &n);
	for (int i = 0; i < n - 1; i++) {
		int a, b; char c; scanf("%d %d %c", &a, &b, &c);
		neigh[a].push_back(ic(b, c));
		neigh[b].push_back(ic(a, c));
	}
	Traverse(1);
	/*for (int i = 1; i <= n; i++)
		printf("res[%d] = %d\n", i, n - res[i]);*/
	int bi = 1;
	for (int i = 2; i <= n; i++)
		if (res[i] > res[bi]) bi = i;
	printf("%d\n", n - res[bi]);
	printf("%d\n", bi);
    return 0;
}