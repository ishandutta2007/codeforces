#include <bits/stdc++.h>
using namespace std;

#define e1 first
#define e2 second
#define pb push_back
#define mp make_pair
#define boost {ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0); }
#define eb emplace_back
#define OUT(x) {cout << x; exit(0); }
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define scanf(...) scanf(__VA_ARGS__)?:0
typedef long long int ll;
typedef unsigned long long ull;
typedef pair <int, int> PII;
typedef pair <ll, ll> PLL;
typedef pair <PLL, int> PLLI;
typedef pair <PII, PII> PP;
typedef pair <PII, int> PPI;
typedef pair <int, PII> PIP;
typedef pair <ll, int> PLI;
typedef unsigned int ui;
const int inf = 1e9+9;
const ll MOD = 1e9+696969;
#ifdef DEBUG
template<class T> int size(T &&x) {
	return int(x.size());
}
template<class A, class B> ostream& operator<<(ostream &out, const pair<A, B> &p) {
	return out << '(' << p.first << ", " << p.second << ')';
}
template<class T> auto operator<<(ostream &out, T &&x) -> decltype(x.begin(), out) {
	out << '{';
	for(auto it = x.begin(); it != x.end(); ++it)
		out << *it << (it == prev(x.end()) ? "" : ", ");
	return out << '}';
}
void dump() {}
template<class T, class... Args> void dump(T &&x, Args... args) {
	cerr << x << ";  ";
	dump(args...);
}
#endif
#ifdef DEBUG
  struct Nl{~Nl(){cerr << '\n';}};
# define debug(x...) cerr << (strcmp(#x, "") ? #x ":  " : ""), dump(x), Nl(), cerr << ""
#else
# define debug(...) 0 && cerr
#endif
mt19937_64 rng(0);
int random(int l, int r) {
	return uniform_int_distribution<int>(l, r)(rng);
}

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long LL;
typedef pair<int, int> pii;
typedef vector<int> vi;
const LL INF = 1e18;
const int maxn = 300200;
int n, m, w;

inline int num(int i, int j) {
	return i * m + j;
}
inline int fi(int nm) {
	return nm / m;
}
inline int sec(int nm) {
	return nm % m;
}

vector <vector <int> > graf;
vector <PII> neighbors = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
PII operator+(PII a, PII b) {
	return {a.e1 + b.e1, a.e2 + b.e2};
}

vector <int> distances(int start){
	queue <int> q;
	q.push(start);
	vector <int> dist(n * m, inf);
	dist[start] = 0;
	while (!q.empty()) {
		int pocz = q.front();
		q.pop();
		
		PII pos = {fi(pocz), sec(pocz)};
		trav(option, neighbors) {
			PII nowy = pos + option;
			if (0 <= nowy.e1 && 0 <= nowy.e2 && nowy.e1 < n && nowy.e2 < m) {
				int val = num(nowy.e1, nowy.e2);
				if (graf[nowy.e1][nowy.e2] != -1 && dist[val] == inf) {
					dist[val] = dist[pocz] + 1;
					q.push(val);
				}
			}
		}
	}
	
	return dist;
}

void solveone() {
	cin >> n >> m >> w;
	graf.clear();
	graf.resize(n, vector<int>(m));
	FOR(i, 0, n-1) {
		FOR(j, 0, m-1) cin >> graf[i][j];
	}
	
	ll START = INF, FINISH = INF;
	
	vi to = distances(num(0, 0));
	vi from = distances(num(n-1, m-1));
	
	ll BEST = INF;
	
	if (from[0] != inf) BEST = min(BEST, (ll)from[0] * w);
	
	FOR(i, 0, n-1) {
		FOR(j, 0, m-1) {
			if (graf[i][j] > 0) {
				if (to[num(i, j)] != inf)   START = min(START, (ll)w * to[num(i, j)] + graf[i][j]);
				if (from[num(i, j)] != inf) FINISH = min(FINISH, (ll)w * from[num(i, j)] + graf[i][j]);
			}
		}
	}
	
	BEST = min(BEST, START + FINISH);
	
	if (BEST == INF) cout << "-1\n";
	else cout << BEST << "\n";
}

int main() {
	boost;
	int tests;
	tests = 1;
	//cin >> tests;
	FOR(_, 1, tests) {
		solveone();
	}
}