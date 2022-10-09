#include <bits/stdc++.h>
using namespace std;
#define e1 first
#define e2 second
#define pb push_back
#define mp make_pair
#define boost ios_base::sync_with_stdio(false)
#define eb emplace_back
#define OUT(x) {cout << x; exit(0); }
#define REYNA(i,a,b) for(int i=(a);i<(b);++i)
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define scanf(...) scanf(__VA_ARGS__)?:0
typedef long long int ll;
typedef unsigned long long ull;
typedef pair <int, int> PII;
typedef pair <ll, ll> PLL;
typedef pair <PLL, int> PLLI;
typedef pair <PII, PII > PP;
typedef pair <PII, int> PPI;
typedef pair <int, PII> PIP;
typedef pair <ll, int> PLI;
typedef unsigned int ui;
const int inf = 1e9+9;
const ll MOD = 1e9+696969;
const long long INF = 1e18+3;
const int maxn = 200100;
int n, m, k, c, s;

vector <int> v[maxn];
int MIN[maxn], MAX[maxn], ILE[maxn], D[maxn];
int where[maxn];
vector <int> ch[maxn];
int seq[maxn], place[maxn];

void dfs(int x, int p)
{
	for (auto u : v[x])
		if (u != p) {
			ch[x].pb(u);
			dfs(u, x);
		}

}
vector <int> ord;
queue <int> q;
bool cmp(int a, int b) {
	return place[a] < place[b];
}

void bfs(int start) {
	q.push(start);
	
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		ord.pb(x);
		sort(ch[x].begin(), ch[x].end(), cmp);
		for (auto u : ch[x]) q.push(u);
	}
	
}

int main()
{
	boost;
	cin >> n;
	FOR(i, 2, n) {
		int a, b;
		cin >> a >> b;
		v[a].pb(b);
		v[b].pb(a);
	}
	
	FOR(i, 1, n) cin >> seq[i], place[seq[i]] = i;
	dfs(1, 0);
	bfs(1);
	assert((int)ord.size() == n);
	for (int i=0; i<n; ++i)
		if (ord[i] != seq[i + 1]) OUT("No");
	
	cout << "Yes";
}