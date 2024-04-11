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
int n, m, k;

int A[maxn], B[maxn];
int key[maxn], pref[maxn];
vector <PPI> e;
vector <PII> wie;
int needed[maxn], odw[maxn];
vector <int> graf[maxn];
bool hasNew[maxn];

void solve(int x, int y, vector <PII> &ver, vector <PPI> &edges)
{
	if (x > y) return;
	/*cout << "Solvuje: " << x << ' ' << y << endl;
	for (auto u : ver) cout << u.e1 << ' ' << u.e2 << endl;
	cout << "Edges: \n";
	for (auto u : edges) cout << u.e1.e1 << ' ' << u.e1.e2 << ' ' << u.e2 << endl;*/
	
	int mid = (x + y) / 2;
	for (auto u : ver)
	{
		graf[u.e1].clear();
		odw[u.e1] = 0;
		needed[u.e1] = u.e2;
		hasNew[u.e1] = 0;
	}
	for (auto u : edges)
	if (u.e2 <= mid)
	{
		graf[u.e1.e1].pb(u.e1.e2);
		graf[u.e1.e2].pb(u.e1.e1);
		needed[u.e1.e1]--; needed[u.e1.e2]--;
	}
	
	queue <int> q;
	for (auto u : ver)
		if (needed[u.e1] > 0) q.push(u.e1), odw[u.e1] = 1;
	
	while (!q.empty())
	{
		int tmp = q.front();
		q.pop();
		for (auto u : graf[tmp])
		{
			needed[u]++;
			if (needed[u] > 0 && !odw[u])
			{
				q.push(u);
				odw[u] = 1;
			}
		}
	}
	
	for (auto u : ver) needed[u.e1] = u.e2;
	for (auto u : ver)
	{
		if (!odw[u.e1])
		{
			key[u.e1] = min(key[u.e1], mid);
			for (auto sec : graf[u.e1]) needed[sec]--;
		}
	}
	
	vector <PII> v1, v2;
	vector <PPI> e1, e2;
	for (auto u : edges)
	{
		if (u.e2 > mid) hasNew[u.e1.e1] = hasNew[u.e1.e2] = 1;
		if (!odw[u.e1.e1] && !odw[u.e1.e2] && u.e2 <= mid) e1.pb(u);
		else if ((odw[u.e1.e1] && odw[u.e1.e2]) || u.e2 > mid) e2.pb(u);
	}
		 
	for (auto u : ver)
	{
		if (!odw[u.e1]) 
		{
			v1.pb(u);
			if (hasNew[u.e1]) v2.pb(mp(u.e1, -n));
		}
		else v2.pb(mp(u.e1, needed[u.e1]));
	}
	
	solve(x, mid - 1, v1, e1);
	solve(mid + 1, y, v2, e2);
}

int main()
{
	boost;
	cin >> n >> m >> k;
	FOR(i, 1, n) key[i] = m+1;
	
	FOR(i, 1, m) {
		cin >> A[i] >> B[i];
		e.pb(mp(mp(A[i], B[i]), i));
	}
	FOR(i, 1, n) wie.pb(mp(i, k));
	
	solve(1, m, wie, e);
	//FOR(i, 1, n) cout << key[i] << ' ';
	//cout << endl;
	
	FOR(i, 1, n) pref[key[i]]++;
		
	FOR(i, 1, m) pref[i] += pref[i-1];
	FOR(i, 1, m) cout << pref[i] << "\n";
}