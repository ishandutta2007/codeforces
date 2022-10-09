#include <bits/stdc++.h>
using namespace std;

#define e1 first
#define e2 second
#define pb push_back
#define mp make_pair
#define boost {ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0); }
#define eb emplace_back
#define OUT(x) {cout << x; exit(0); }
#define TCOUT(x) {cout << x << "\n"; return; }
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

/*namespace Color {
enum Code {
  FG_RED     = 31,
  FG_GREEN   = 32,
  FG_YELLOW  = 33,
  FG_BLUE    = 34,
  FG_DEFAULT = 39
};
class ColorDebugger {
  Code code;
 public:
  ColorDebugger(Code pCode) : code(pCode) {}
  template <class T>
  ColorDebugger& operator<<(const T &other) {
    cout << "\033[" << code << "m" << other << "\033[" << FG_DEFAULT << "m";
    return *this;
  }
  ColorDebugger& operator<<(ostream&(*pManip)(ostream&)){
    (*pManip)(cout);
    return *this;
  }
};
}

using namespace Color;
ColorDebugger gout(FG_GREEN);
ColorDebugger rout(FG_RED);*/

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
typedef vector <ll> vll;

const LL INF = 1e18;
const int maxn = 1000100;
vector <PII> ans;

int par[maxn];
const int N = 20;

void add(int x, int y) {
	par[x] = y;
	ans.pb({x, y});
}

void move(int &curr_node, int &gdzie, vector <PII> &vec, int i) {
	if (curr_node % 2 == 0) curr_node = par[curr_node];
	else {
		assert(i != gdzie);
		if (i > gdzie) ++gdzie;
		else --gdzie;
		curr_node = vec[gdzie].e2;
	}
}

int floyd[110][110];
int desired[110];

void solve() {
	ans.clear();
	int n = N;
	cin >> n;
	FOR(i, 1, 2 * n) par[i] = 0;
	vector <PII> vec;
	
	for (int i=1; i<=2*n; i+=2) {
		int a;
		cin >> a;
		//a = rand()%n + 1;
		desired[i] = a;
		vec.pb({a, i});
	}
	
	/*FOR(i, 1, 2 * n) 
	FOR(j, 1, 2 * n) floyd[i][j] = inf;
	FOR(i, 1, 2 * n) floyd[i][i] = 0;*/
	
	sort(all(vec), greater<PII>());
	rep(i, 1, n) add(vec[i].e2, vec[i - 1].e2);

	// gdzie na sciezce
	int gdzie = vec[0].e1 - 1;
	add(vec[0].e2 ^ 1, vec[gdzie].e2);
	// jaki ost node
	int last_node = vec[0].e2 ^ 1;
	
	// the first node is added
	rep(i, 1, n) {
		int curr_node = vec[i].e2 ^ 1;
		// first move according to the change
		if (gdzie < i) { //oddalilismy sie, move 2 w aktualna strone
			move(last_node, gdzie, vec, i);
			move(last_node, gdzie, vec, i);
		}
		int delta = vec[i - 1].e1 - vec[i].e1;
		FOR(step, 1, delta) move(last_node, gdzie, vec, i); //przyblizamy sie, bo jest potrzeba
		add(curr_node, last_node);
		last_node = curr_node;
	}
	
	/*trav(u, ans) {
		int a = u.e1 + 1, b = u.e2 + 1;
		floyd[a][b] = 1;
		floyd[b][a] = 1;
	}
	
	FOR(k, 1, 2 * n)
		FOR(i, 1, 2 * n)
			FOR(j, 1, 2 * n) floyd[i][j] = min(floyd[i][j], floyd[i][k] + floyd[k][j]);
	
	for (int i=1; i<2*n; i+=2) {
		if (floyd[i][i+1] != desired[i]) {
			debug(vec);
			FOR(j, 1, 2*n) {
				FOR(k, 1, 2*n) cout << floyd[j][k] << ' ';
				cout << endl;
			}
			debug(i);
			exit(0);
		}
	}*/
	
	trav(u, ans) cout << 1 + u.e1 << ' ' << 1 + u.e2 << "\n";
}

int main() {
	srand(2137);
	boost;
	int tests;
	tests = 1;
	//cin >> tests;
	while (tests--) {
		solve();
	}
}