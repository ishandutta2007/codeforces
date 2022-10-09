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
const int inf = 1e9+9;
const ll MOD = 1e9+696969;
const long long INF = 1e18+3;
const int maxn = 100100;

ll sm[maxn], lar[maxn];
ll result;
int SQ;
ll sal[maxn];

inline ll f(int x) {return (ll)sm[x] * lar[x]; }
vector <int> upd[maxn];
vector <int> v[maxn];

int zap,n, m;
set <PII> q;

void update(int x, int cz, vector <int> &vec) {
	result -= f(x);
	for (auto u : vec) {
		result -= f(u);
		if (sal[u] > sal[x]) {
			sm[u]--; lar[x]--;
		}
		else {
			sm[x]--; lar[u]--;
		}
	}
	
	sal[x] = cz;
	for (auto u : vec) {
		if (sal[u] > sal[x]) {
			sm[u]++; lar[x]++;
		}
		else {
			sm[x]++; lar[u]++;
		}
		result += f(u);
	}
	result += f(x);
}
int pytania[maxn];

int main()
{
	boost; cin.tie(0);
	cin >> n >> m;
	FOR(i, 1, n) sal[i] = i;
	
	FOR(i, 1, m) {
		int a, b;
		cin >> a >> b;
		v[a].pb(b);
		v[b].pb(a);
		q.insert({a, b});
		q.insert({b, a});
		if (sal[a] > sal[b]) {
			sm[a]++; lar[b]++;
		}
		else {
			sm[b]++; lar[a]++;
		}
	}
	
	FOR(i, 1, n) result += f(i);
	cout << result << "\n";
	SQ = sqrt(m / 4) + 1;
	cin >> zap;
	FOR(z, 1, zap) {
		int id;
		cin >> id;
		if (upd[id].empty() || upd[id].back() + SQ < z) update(id, z + n, v[id]);
		else
		{
			//new update
			int val = upd[id].back();
			vector<int> xdd = {};
			for (int step = val + 1; step < z; ++step) {
				if (q.find({id, pytania[step]}) != q.end()) xdd.pb(pytania[step]);
			}
			
			sort( xdd.begin(), xdd.end() );
			xdd.erase( unique( xdd.begin(), xdd.end() ), xdd.end() );
			update(id, z + n, xdd);
		}
		
		upd[id].pb(z);
		pytania[z] = id;
		cout << result << "\n";
	}
}