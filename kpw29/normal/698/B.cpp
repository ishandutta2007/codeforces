#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define boost ios_base::sync_with_stdio(false)
#define pb push_back
#define e1 first
#define e2 second
#define tysiac 1010
#define milion 1000100
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define OUT(x) { cout << x; return 0; }
#define scanf(...) scanf(__VA_ARGS__)?:0
typedef long long int ll;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef double ld;
typedef pair <int, int> PII;
typedef pair <ll, ll> PLL;
typedef pair <ld, ld> PDD;
typedef pair <PII, PII> PP;
typedef pair <ll, int> PLI;
const int mod = 1e9+7;
const int inf = 1e9+9;
const int MOD = 1e9+696969;
const ll INF = 1e18+3;
#define maxn 1000100

int t[maxn], n, a;

int indeg[maxn];

int start[maxn];

bool odw[maxn];
vector <int> v[maxn];

void BFS() {
	queue <int> q;
	
	FOR(i, 1, n)
	  if (indeg[i] == 0) q.push(i);
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		odw[x] = 1;
		for (auto u : v[x]) {
			indeg[u]--;
			if (indeg[u] == 0) q.push(u);
		}
	}
}

int main() {
	int root = 0;
	scanf("%d", &n);
	FOR(i, 1, n) {
		scanf("%d", &t[i]);
		v[i].pb(t[i]);
		indeg[t[i]]++;
		start[i] = t[i];
		if (t[i] == i) root = i;
	}
	
	BFS();
	if (!root) FOR(i, 1, n)
	  if (!odw[i]) root = i;
	if (t[root] != root) t[root] = root;
	int j = root;
	while (!odw[j]) {
		odw[j] = 1;
		j = start[j];
	}
	
	FOR(i, 1, n) {
		if (i == root) continue;
		if (!odw[i]) {
			int j = i;
			while (!odw[j]) {
				odw[j] = 1;
				j = t[j];
			}
			t[i] = root;
		}
	}
	
	int wyn = 0;
	FOR(i, 1, n)
	  if (t[i] != start[i]) ++wyn;
	printf("%d\n", wyn);
	FOR(i, 1, n) printf("%d ", t[i]);
}