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
typedef pair <PLL, pair <int, ll> > PP;
typedef pair <PII, int> PPI;
typedef pair <int, PII> PIP;
typedef pair <ll, int> PLI;
typedef unsigned int ui;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
const int inf = 1e9+9;
const int mod = 998244353;
const ll MOD = 1e9+696969;
const long long INF = 1e18+3;
int n, m, a, b, c;
const int maxn = 1000100;
priority_queue <int> pos;

ll tab[maxn];
const int R = (1 << 19);
pair <PLL, int> dr[2 * R + 5];

void push(int gdzie)
{
	if (dr[gdzie].e1.e2 != 0)
	{
		dr[2 * gdzie].e1.e2 += dr[gdzie].e1.e2;
		dr[2 * gdzie].e1.e1 += dr[gdzie].e1.e2;
		
		dr[2 * gdzie + 1].e1.e2 += dr[gdzie].e1.e2;
		dr[2 * gdzie + 1].e1.e1 += dr[gdzie].e1.e2;
		
		dr[gdzie].e1.e2 = 0;
	}
}

void update(int gdzie)
{
	if (dr[2 * gdzie].e1.e1 > dr[2 * gdzie + 1].e1.e1)
	{
		assert(dr[gdzie].e1.e2 == 0);
		dr[gdzie].e1 = make_pair(dr[2 * gdzie + 1].e1.e1, 0);
		dr[gdzie].e2 = dr[2 * gdzie + 1].e2;
	}
	else
	{
		assert(dr[gdzie].e1.e2 == 0);
		dr[gdzie].e1 = make_pair(dr[2 * gdzie].e1.e1, 0);
		dr[gdzie].e2 = dr[2 * gdzie].e2;
	}
}

inline void add(int gdzie, int pocz, int kon, int x, int y, ll ile)
{
	//cout << gdzie << ' ' << pocz << ' ' << kon << ' ' <<x << ' ' << y << endl;
	if (x <= pocz && y >= kon)
	{
		dr[gdzie].e1.e1 += ile;
		dr[gdzie].e1.e2 += ile;
		return;
	}
	
	push(gdzie);
	int sr = (pocz + kon) >> 1;
	if (x <= sr) add(2 * gdzie, pocz, sr, x, y, ile);
	if (y > sr) add(2 * gdzie + 1, sr + 1, kon, x, y, ile);
	update(gdzie);
}

int perm[maxn];

int main()
{
	boost;
	cin >> n;
	FOR(i, n + 1, R) add(1, 1, R, i, i, INF);
	
	FOR(i, 1, n) {
		cin >> tab[i];
		dr[i + R - 1].e2 = i;
		add(1, 1, R, i, i, tab[i]);
	}
	for (int i = R - 1; i > 0; --i) update(i);

	FOR(step, 1, n) {
	
		while (dr[1].e1.e1 == 0)
		{
			int id = dr[1].e2;
			add(1, 1, R, id, id, INF);
			pos.push(id);
			
			dr[id + R - 1].e2 = inf;
		}
		
		int tp = pos.top();
		pos.pop();
		perm[tp] = step;
		if (tp < n) add(1, 1, R, tp + 1, n, -step);
	}
	
	FOR(i, 1, n) cout << perm[i] << ' ';
	
}