#include <bits/stdc++.h>

using namespace std;

//#define endl '\n'
#define MP make_pair
#define DB(x) cout << #x << "=" << x << endl

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int maxn = 151;

struct matrix{
	int sz;	
	vector<bitset<maxn>> m;
	vector<bitset<maxn>> t;

	matrix(int SZ){
		sz = SZ;
		m = vector<bitset<maxn>>(sz);
		t = vector<bitset<maxn>>(sz);
	}

	void set(int i, int j){
		m[i].set(j);
		t[j].set(i);
	}

	matrix operator *(const matrix &o){
		matrix ans(sz);
		for (int i = 0; i < sz; ++i)
			for (int j = 0; j < sz; ++j)
				if ( (m[i] & o.t[j]).any() )
					ans.set(i, j);
		return ans;
	}

	bitset<maxn> operator *(const bitset<maxn> &o){
		bitset<maxn> ans;
		for (int i = 0; i < sz; ++i)
			if ( (m[i] & o).any() ) ans.set(i);
		return ans;
	}

	void print(){
		for (int i = 0; i < sz; ++i)
			cout << m[i] << endl;
		cout << endl;
	}
};

matrix fast_exp(matrix g, int p){
	if (p == 1) return g;
	matrix ans = fast_exp(g * g, p / 2);
	if (p & 1) ans = ans * g;
	return ans;
}

int n, m;
int dist[maxn];

int bfs(matrix &g, bitset<maxn> &p){
	memset(dist, -1, sizeof dist);

	queue<int> q;
	for (int i = 0; i < n; ++i){
		if (p.test(i)){
			dist[i] = 0;
			q.push(i);
		}
	}

	while (!q.empty()){
		int cur = q.front(); q.pop();
		if (cur + 1 == n)
			return dist[cur];

		for (int i = 0; i < n; ++i){
			if (g.m[i].test(cur) && dist[i] == -1){
				dist[i] = dist[cur] + 1;
				q.push(i);
			}
		}
	}

	return -1;
}

pair<int, pii> e[maxn];

int main(){

#ifdef MARX
	freopen("data.in", "r", stdin);
	// freopen("data.out", "w", stdout);
#endif

	cin >> n >> m;

	for (int i = 0; i < m; ++i){
		int u, v, d;
		cin >> u >> v >> d;
		u--; v--;
		e[i] = make_pair(d, make_pair(u, v));
	}

	sort(e, e + m);
	bitset<maxn> cur(1);

	matrix graph(n);

	if (e[0].first > 0){
		cout << "Impossible" << endl;
		exit(0);
	}

	for (int i = 0, j; i < m; i = j){
		if (i) cur = fast_exp(graph, e[i].first - e[i - 1].first) * cur;

		for (j = i; j < m && e[j].first == e[i].first; ++j){
			graph.set(e[j].second.second, e[j].second.first);
		}

		int val = bfs(graph, cur);

		if (val != -1){
			cout << val + e[i].first << endl;
			exit(0);
		}
	}

	cout << "Impossible" << endl;

	return 0;
}