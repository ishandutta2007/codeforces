#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:16000000")
using namespace std;

typedef long long ll;
typedef pair <ll, ll> llll;

const int Maxn = 100005;
const ll Inf = 4000000000000000000ll;

struct Less {
	bool operator()(const llll &a, const llll &b) const {
		if (a.first != b.first) return a.first > b.first;
		return a.second > b.second;
	}
};

int n;
int a[Maxn];
int b[Maxn];
vector <int> neigh[Maxn];
map <llll, ll, Less> M[Maxn];
map <ll, llll> X[Maxn];
int par[Maxn];
ll res[Maxn];

ll getX(const llll &a, const llll &b)
{
	ll fir = b.second - a.second;
	ll sec = a.first - b.first;
	if (fir <= 0) return fir / sec;
	return (fir - 1) / sec + 1;
}

void Remove(int ind, const llll &a)
{
	map <llll, ll, Less>::iterator it = M[ind].find(a);
	X[ind].erase(it->second); M[ind].erase(it);
}

void Set(int ind, const llll &a, const ll &b)
{
	map <llll, ll, Less>::iterator it = M[ind].find(a);
	if (it == M[ind].end()) { M[ind][a] = b; X[ind][b] = a; }
	else { X[ind].erase(it->second); it->second = b; X[ind][it->second] = a; }
}

void Insert(int ind, const llll &a)
{
	map <llll, ll, Less>::iterator it = M[ind].lower_bound(llll(a.first, Inf));
	if (it != M[ind].end() && it->first.first == a.first)
		if (it->first.second <= a.second) return;
		else { llll rem = it->first; it++; Remove(ind, rem); }
	ll X = -Inf;
	while (it != M[ind].begin()) {
		it--;
		X = getX(it->first, a);
		if (X <= it->second) { llll rem = it->first; it++; Remove(ind, rem); }
		else { it++; break; }
	} 
	if (it != M[ind].end()) {
		ll cand = getX(a, it->first);
		if (cand <= X) return;
		llll rem = it->first; it++;
		while (it != M[ind].end()) {
			ll cand2 = getX(a, it->first);
			if (cand2 <= cand) { Remove(ind, rem); cand = cand2; rem = it->first; it++; }
			else break;
		}
		Set(ind, rem, cand);
	}
	Set(ind, a, X);
}

ll Get(int ind, ll x)
{
	map <ll, llll>::iterator it = X[ind].upper_bound(x);
	it--;
	return x * it->second.first + it->second.second;
}

void Merge(int a, int b)
{
	if (M[par[a]].size() < M[par[b]].size()) swap(a, b);
	for (map <llll, ll, Less>::iterator it = M[par[b]].begin(); it != M[par[b]].end(); it++)
		Insert(par[a], it->first);
	M[par[b]].clear(); X[par[b]].clear();
	par[b] = par[a];
}

void Traverse(int v, int p = 0)
{
	par[v] = v;
	if (neigh[v].size() - (p != 0) == 0)
		Insert(par[v], llll(b[v], 0));
	else {
		for (int i = 0; i < neigh[v].size(); i++) {
			int u = neigh[v][i];
			if (u == p) continue;
			Traverse(u, v);
			Merge(v, u);
		}
		res[v] = Get(par[v], a[v]);
		Insert(par[v], llll(b[v], res[v]));
	}
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	for (int i = 1; i <= n; i++)
		scanf("%d", &b[i]);
	for (int i = 0; i < n - 1; i++) {
		int a, b; scanf("%d %d", &a, &b);
		neigh[a].push_back(b);
		neigh[b].push_back(a);
	}
	Traverse(1);
	for (int i = 1; i <= n; i++)
		printf("%I64d%c", res[i], i + 1 <= n? ' ': '\n');
	return 0;
}