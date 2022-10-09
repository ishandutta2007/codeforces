#include <bits/stdc++.h>
using namespace std;
#define e1 first
#define e2 second
#define pb push_back
#define mp make_pair
#define boost {ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0); }
#define eb emplace_back
#define OUT(x) {cout << x; exit(0); }
#define FOR(i, a, b) for(int i=(a); i<=(b); ++i)
#define scanf(...) scanf(__VA_ARGS__)?:0
typedef long long ll;
typedef unsigned long long ull;
typedef pair <int, int> PII;
typedef pair <ll, ll> PLL;
typedef pair <PII, PII> PP;
typedef pair <PII, int> PPI;
typedef pair <int, PII> PIP;
typedef pair <ll, int> PLI;
typedef unsigned int ui;
typedef vector <int> vi;
const int mod = 1e9+7;
const int inf = 1e9+10;
const ll MOD = 1e9+696969;
const ll INF = 1e18;
const int W = 1e9;
#define maxn 100100
int n, m, M, DISS[maxn], tab[maxn], w[maxn], b[maxn], mon[maxn];
bool kupione[maxn];
ll Total = 0;

int main()
{
	boost;
	cin >> n >> m;
	FOR(i, 1, n) cin >> tab[i];
	FOR(i, 1, n) cin >> w[i];
	
	multiset<PII> q;
	q.clear();
	ll overallCost = 0;
	FOR(i, 1, n)
	{
		b[i] = (tab[i] / 100);
		mon[i] = (tab[i] % 100);
		if (mon[i] == 0) continue;
		DISS[i] = w[i] * (100 - mon[i]);
		q.insert(mp(DISS[i], i));
		if (m < mon[i])
		{
			PII x = *q.begin();
			q.erase(q.begin());
			overallCost += x.e1;
			kupione[x.e2] = 1;
			m += 100;
		}
		m -= mon[i];
	}
	
	cout << overallCost << "\n";
	FOR(i, 1, n)
	if (kupione[i]) cout << b[i] + 1 << " 0\n";
	else cout << b[i] << ' ' << mon[i] << "\n";
}