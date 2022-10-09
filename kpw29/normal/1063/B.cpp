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
const int inf = 2e9+9;
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
mt19937_64 rng(time(0));
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
const int maxn = 1000100;

void solve() {
	
}

int dist[2020][2020];
int lewo[2020][2020];
int prawo[2020][2020];

string tab[2020];
vector <PII> dirs_pion = {{-1, 0}, {1, 0}};

PII dodaj(PII a, PII b) {
	return {a.e1 + b.e1, a.e2 + b.e2};
}

int COMP[2020][2020];
int CC;

int main() {
	boost;
	int n, m, sx, sy, x, y;
	cin >> n >> m >> sx >> sy >> x >> y;	
	FOR(i, 1, n) {
		cin >> tab[i];
		tab[i] = "*" + tab[i] + "*";
	}
	
	deque <pair <int, PII> > q;
	dist[sx][sy] = 0;
	lewo[sx][sy] = prawo[sx][sy] = 0;
	FOR(i, 1, n) {
		FOR(j, 1, m) {
			if (i != sx || j != sy) {
				dist[i][j] = inf;
				lewo[i][j] = inf;
				prawo[i][j] = inf;
			}
		}
	}
	q.push_back({dist[sx][sy], {sx, sy}});
	 
	auto in = [&](PII pole) -> bool {
		int a = pole.e1; int b = pole.e2;
		bool flag = (1 <= a && a <= n && 1 <= b && b <= m);
		if (!flag) return false;
		if (tab[a][b] == '*') return false;
		else return true;
	};
	
	while (!q.empty()) {
		auto fro = q.front();
		q.pop_front();
		
		int d = fro.e1;
		PII node = fro.e2;
		
		for (auto u : dirs_pion) {
			PII nowy = dodaj(node, u);
			if (in(nowy) && dist[nowy.e1][nowy.e2] > d) {
				dist[nowy.e1][nowy.e2] = dist[node.e1][node.e2];
				lewo[nowy.e1][nowy.e2] = lewo[node.e1][node.e2];
				prawo[nowy.e1][nowy.e2] = prawo[node.e1][node.e2];
				
				q.push_front({dist[nowy.e1][nowy.e2], nowy});
			}
		}
		
		// idz w lewo
		PII nowy = dodaj(node, {0, -1});
		if (in(nowy) && dist[nowy.e1][nowy.e2] + 1 > d && lewo[node.e1][node.e2] < x) {
		
			dist[nowy.e1][nowy.e2] = 1 + dist[node.e1][node.e2];
			lewo[nowy.e1][nowy.e2] = 1 + lewo[node.e1][node.e2];
			prawo[nowy.e1][nowy.e2] = prawo[node.e1][node.e2];
			
			q.push_back({dist[nowy.e1][nowy.e2], nowy});
		}
		
		// i w prawo
		nowy = dodaj(node, {0, 1});
		if (in(nowy) && dist[nowy.e1][nowy.e2] + 1 > d && prawo[node.e1][node.e2] < y) {

			dist[nowy.e1][nowy.e2] = 1 + dist[node.e1][node.e2];
			lewo[nowy.e1][nowy.e2] = lewo[node.e1][node.e2];
			prawo[nowy.e1][nowy.e2] = 1 + prawo[node.e1][node.e2];
			
			q.push_back({dist[nowy.e1][nowy.e2], nowy});
		}
	}
	
	int occ = 0;
	FOR(i, 1, n) {
		FOR(j, 1, m) {
			if (in({i, j}) && lewo[i][j] <= x && prawo[i][j] <= y) ++occ;
		}
	}
	
	cout << occ << endl;
}