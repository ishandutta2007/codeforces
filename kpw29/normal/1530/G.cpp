#include <bits/stdc++.h>
using namespace std;

#define e1 first
#define e2 second
#define pb push_back
#define mp make_pair
#define boost {ios_base::sync_with_stdio(false); cin.tie(0); }
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
int n, k;

vector <PII> nowe;
vector <int> input;

void odwroc(int p1, int p2, int ile_lewo, int ile_prawo, vector <int> &v, vector <int> &pos) {
	int ile_jed = 0, gdzie = 1;
	int delta_lewo = pos[p1] - ile_lewo;
	int delta_prawo = pos[p2] - ile_prawo;
	
	while (ile_jed < p1) {
		if (v[gdzie] == 1) ++ile_jed;
		++gdzie;
	}
	gdzie += ile_lewo;
	
	int x = gdzie;
	while (ile_jed < p2) {
		if (v[gdzie] == 1) ++ile_jed;
		++gdzie;
	}
	--gdzie;
	gdzie += pos[p2] - ile_prawo;
	
	int y = gdzie; 
	pos[p1] = pos[p1] - delta_lewo + delta_prawo;
	pos[p2] = pos[p2] + delta_lewo - delta_prawo;

	for (int i=1; p1 + i <= p2 - i; ++i) {
		swap(pos[p1 + i], pos[p2 - i]);
	}
	
	reverse(v.begin() + x, v.begin() + y + 1);
	nowe.pb({x, y});
	debug(p1, p2);
	debug(pos);
}

vector <int> bij(vector <int> &v) {
	nowe.clear();
	
	vector <int> pos = {0};
	FOR(i, 1, n) {
		if (v[i] == 0) pos[pos.size() - 1]++;
		else {
			pos.pb(0);
		}
	}
	
	for (int i=0; i+k<(int)pos.size(); ++i) {
		odwroc(i, i+k, 0, pos[i + k], v, pos);
	}
	
	int steps = 2 * k;
	
	int sz = pos.size();
	if (sz - k - 2 < 0) return pos;
	
	if (k % 2) {
		// old system, everything will go into one place
		for (int step = 1; step <= steps; ++step) {
			if (step % 2 == 0) odwroc(sz - k - 1, sz - 1, 0, pos[sz - 1], v, pos);
			else odwroc(sz - k - 2, sz - 2, 0, pos[sz - 2], v, pos);
		}
	}
	else { //new system, pushing either to front or to back
		for (int step = 1; step <= steps; ++step) {
			if (step % 2 == 0) odwroc(sz - k - 1, sz - 1, 0, pos[sz - 1], v, pos);
			else odwroc(sz - k - 2, sz - 2, pos[sz - k - 2], 0, v, pos);
		}
	}
	
	
	return pos;
}

string A, B;
int tests;

void solve(int tc) {
	cin >> n >> k;
	vector <int> a, b;
	a.resize(n + 1);
	b.resize(n+1);
	string s;
	cin >> s;
	A = "#" + s;
	FOR(i, 1, n) {
		a[i] = s[i-1] - '0';
	}
	
	cin >> s;
	B = "#" + s;
	FOR(i, 1, n) {
		b[i] = s[i-1] - '0';
	}
	
	/*if (tests == 200 && tc == 27) {
		cout << n << '_' << k << '_' << A << B << endl;
		exit(0);
	}
	if (tests == 200) {
		return;
	}*/
	
	if (k == 0) {
		if (a == b) cout << "0\n";
		else cout << "-1\n";
		return;
	}
	
	debug("A");
	auto pie = bij(a);
	vector <PII> tmp = nowe;
	nowe.clear();
	debug("B");
	auto sec = bij(b);
	
	if (pie.size() != sec.size()) TCOUT(-1);

	if (pie != sec) {
		int R = pie.size();
		if (k + 1 == R) {
			odwroc(0, 0+k, pie[0], pie[0 + k], a, pie);
			if (pie != sec) TCOUT(-1);
		}
		else {
			TCOUT(-1);
		}
	}
	
	reverse(all(nowe));
	cout << (int)(tmp.size() + nowe.size()) << "\n";
	trav(u, tmp) {
		cout << u.e1 << ' ' << u.e2 << "\n";
		reverse(A.begin() + u.e1, A.begin() + u.e2 + 1);
	}
	
	trav(u, nowe) {
		cout << u.e1 << ' ' << u.e2 << "\n";
		reverse(A.begin() + u.e1, A.begin() + u.e2 + 1);
	}
	
	debug("results");
	debug(A);
	debug(B);
	
}

int main() {
	boost;
	//tests = 1;
	cin >> tests;
	FOR(z, 1, tests){
		solve(z);
	}
}