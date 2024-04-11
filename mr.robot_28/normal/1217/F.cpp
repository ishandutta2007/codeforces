// awoo~

#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < int(n); i++)

using namespace std;

const int BUF = 10 * 1000 * 1000 + 13;
const int N = 300 * 1000 + 13;
const int M = 300 * 1000 + 13;
const int P = 400;

struct query{
	int t, x, y;
	int e0, e1;
};

int n, m;
query q[M];

int p[N], rk[N];

int cnt;
int* where[BUF];
int val[BUF];

void rollback(){
	while (cnt > 0){
		*where[cnt - 1] = val[cnt - 1];
		--cnt;
	}
}

int getp(int a){
	return (a == p[a] ? a : getp(p[a]));
}

void unite(int a, int b){
	a = getp(a), b = getp(b);
	if (a == b) return;
	if (rk[a] < rk[b]) swap(a, b);
	where[cnt] = &rk[a];
	val[cnt++] = rk[a];
	where[cnt] = &p[b];
	val[cnt++] = p[b];
	assert(cnt <= BUF);
	rk[a] += rk[b];
	p[b] = a;
}

int getpFast(int a){
	return (a == p[a] ? a : p[a] = getpFast(p[a]));
}

void uniteFast(int a, int b){
	a = getpFast(a), b = getpFast(b);
	if (a == b) return;
	if (rk[a] < rk[b]) swap(a, b);
	rk[a] += rk[b];
	p[b] = a;
}

struct edge{
	int v, u;
};

bool operator <(const edge &a, const edge &b){
	if (a.v != b.v)
		return a.v < b.v;
	return a.u < b.u;
}

edge edges[2 * M];
map<edge, int> rev;

bool used[2 * M];
bool state[2 * M];
int ans[M];
vector<int> cur;

void rebuild(int l){
	int r = min(m, l + P);
	forn(i, n) p[i] = i, rk[i] = 1;
	memset(used, 0, sizeof(used));
	memset(state, 0, sizeof(state));

	forn(i, l) if (q[i].t == 1){
		int e = (ans[i] ? q[i].e1 : q[i].e0);
		used[e] = true;
		state[e] ^= 1;
	}
	
	for (int i = l; i < r; ++i) if (q[i].t == 1)
		used[q[i].e0] = used[q[i].e1] = false;
	
	cur.clear();
	cnt = 0;
	forn(i, l) if (q[i].t == 1){
		int e = (ans[i] ? q[i].e1 : q[i].e0);
		if (used[e] && state[e]){
			state[e] = false;
			uniteFast(edges[e].v, edges[e].u);
		}
		else if (!used[e] && state[e]){
			state[e] = false;
			cur.push_back(e);
		}
	}
}

int get_edge(edge e){
	if (!rev.count(e)){
		int k = rev.size();
		edges[k] = e;
		rev[e] = k;
	}
	return rev[e];
}

int main(){
	scanf("%d%d", &n, &m);
	forn(i, m){
		scanf("%d%d%d", &q[i].t, &q[i].x, &q[i].y);
		--q[i].x, --q[i].y;
		if (q[i].t == 1){
			edge e({q[i].x, q[i].y});
			if (e.v > e.u) swap(e.v, e.u);
			q[i].e0 = get_edge(e);
			e.v = (e.v + 1) % n, e.u = (e.u + 1) % n;
			if (e.v > e.u) swap(e.v, e.u);
			q[i].e1 = get_edge(e);
		}
	}
	
	string res = "";
	ans[0] = 0;
	forn(i, m){
		if (i % P == 0)
			rebuild(i);
		
		int x = (q[i].x + ans[i]) % n;
		int y = (q[i].y + ans[i]) % n;
		if (x > y) swap(x, y);
		
		if (q[i].t == 1){
			rollback();
			int e = get_edge({x, y});
			auto it = find(cur.begin(), cur.end(), e);
			if (it == cur.end())
				cur.push_back(e);
			else
				cur.erase(it);
			ans[i + 1] = ans[i];
		}
		else{
			for (auto e : cur)
				unite(edges[e].v, edges[e].u);
			bool rc = (getp(x) == getp(y));
			ans[i + 1] = rc;
			res += ('0' + rc);
		}
	}
	
	puts(res.c_str());
	return 0;
}