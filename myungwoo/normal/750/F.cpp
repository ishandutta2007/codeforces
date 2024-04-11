#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define fr first
#define sc second
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
typedef long long lld;
typedef pair<int, int> pii;

int T, N, K;
vector <int> con[128];

vector <int> ask(int n)
{
	if (sz(con[n])) return con[n];
	printf("? %d\n", n); fflush(stdout);
	int sz;
	scanf("%d", &sz);
	vector <int> ret(sz);
	for (int i=0;i<sz;i++) scanf("%d", &ret[i]);
	return con[n] = ret;
}

void report(int n){ printf("! %d\n", n); fflush(stdout); }

vector <int> get_candidate(int n, int from, int bound)
{
	vector <int> ret = {n};
	if (!bound) return ret;
	for (int t: ask(n)) if (t != from){
		auto arr = get_candidate(t, n, bound-1);
		for (int v: arr) ret.pb(v);
	}
	return ret;
}

void work(int n, int from, int lvl)
{
	if (lvl == K){ report(n); return; }

	if (K-lvl < 3){
		auto arr = get_candidate(n, from, K-lvl);
		int last = arr.back(); arr.pop_back();
		for (int nd: arr) if (sz(ask(nd)) == 2){
			report(nd); return;
		}
		report(last); return;
	}

	vector <int> path(lvl-2, 0);
	path.pb(from);
	for (int nd=n,f=from;nd;){
		path.pb(nd);
		auto arr = ask(nd);
		if (sz(arr) == 2){ report(nd); return; }
		int nxt = 0;
		for (int t: arr) if (t != f) nxt = t;
		f = nd; nd = nxt;
	}

	int m = sz(path);
	int t = path[m/2], a = path[m/2-1], b = path[m/2+1];
	int up = 0;
	for (int nd: ask(t)) if (nd != a && nd != b) up = nd;
	work(up, t, m/2+2);
}

void proc()
{
	vector <int> path = {1};
	auto arr = ask(1);
	// is root
	if (sz(arr) == 2){ report(1); return; }

	// is leaf
	if (sz(arr) == 1){ work(arr[0], 1, 2); return; }

	// is internal
	for (int n=arr[0],from=1;n;){
		path.pb(n);
		auto arr = ask(n);
		if (sz(arr) == 2){ report(n); return; }
		int nxt = 0;
		for (int t: arr) if (t != from) nxt = t;
		from = n; n = nxt;
	}
	reverse(all(path));
	for (int n=arr[1],from=1;n;){
		path.pb(n);
		auto arr = ask(n);
		if (sz(arr) == 2){ report(n); return; }
		int nxt = 0;
		for (int t: arr) if (t != from) nxt = t;
		from = n; n = nxt;
	}
	int m = sz(path);
	int t = path[m/2], a = path[m/2-1], b = path[m/2+1];
	int up = 0;
	for (int nd: ask(t)) if (nd != a && nd != b) up = nd;
	work(up, t, m/2+2);
}

int main()
{
	for (scanf("%d", &T);T--;){
		scanf("%d", &K); N = (1<<K)-1;
		for (int i=1;i<=N;i++) con[i].clear();

		proc();
	}
}