#include<bits/stdc++.h>

using namespace std;

#define x first
#define y second
#define pb push_back
#define eb emplace_back
#define rep(i,a,b) for(auto i = (a); i != (b); ++i)
#define REP(i,n) rep(i,0,n)
#define all(v) (v).begin(), (v).end()

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

struct Edge { int u, v, w; };

const int maxn = 1e5;
int n, m, k, s[maxn];

int par[maxn] = {}, rnk[maxn] = {}, nsp[maxn] = {};

int find(int u) { return !par[u] ? u : par[u] = find(par[u]); }
bool merge(int a, int b) {
	if ((a=find(a)) == (b=find(b))) return false;
	if (rnk[a] > rnk[b]) swap(a, b);
	if (rnk[a] == rnk[b]) rnk[b]++;

	nsp[b] += nsp[a];
	par[a] = b;
	return true;
	// merge a, b
}


Edge edges[maxn];

bool operator<(Edge a, Edge b) { return a.w < b.w; }
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m >> k;
	REP(i, k) { int x; cin >> x; nsp[x]++; }
	REP(i, m) cin >> edges[i].u >> edges[i].v >> edges[i].w;

	sort(s, s + k);
	sort(edges, edges + m);

	// one based!
	REP(i, m) {
		Edge e = edges[i];
		// cerr  << "MERGE: " << e.u << " " << e.v << endl;
		if (!merge(e.u, e.v)) continue;

		// cerr << e.u << ": " << nsp[find(e.u)] << endl;
		if (nsp[find(e.u)] == k) {
			REP(j, k) {
				printf("%d%c", e.w, " \n"[j==n-1]);
			}
			return 0;
		}
	}

	printf("oops.\n");
}