#include <bits/stdc++.h>
using namespace std;
using LL = long long;
#define e1 first
#define e2 second
#define pb push_back
#define OUT(x) {cout << x << "\n"; exit(0); }
#define TCOUT(x) {cout << x << "\n"; return; }
#define FOR(i, l, r) for(int i = (l); i <= (r); ++i)
#define rep(i, l, r) for(int i = (l); i < (r); ++i)
#define boost {ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0); }
#define sz(x) int(x.size())
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
//#include <atcoder/modint>
//using namespace atcoder;
//using mint = modint1000000007;
mt19937_64 rng(time(0));
int random(int l, int r) {
	return uniform_int_distribution<int>(l, r)(rng);
}
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

int n;

int get_id(string &s) {
	int wynik = 0;
	if (s[0] == '0') return -1;
	rep(i, 0, sz(s)) {
		if (!(s[i] >= '0' && s[i] <= '9')) return -1;
		wynik = 10 * wynik + s[i] - '0';
	}
	
	if (wynik > n) return -1; //also not good things
	return wynik;
}

int examples;


void solve(int tc) {
	cin >> n;
	vector <string> file(n);
	vector <bool> jest(n + 1, false);
	
	vi small(n);
	
	vi smalls;
	vi larges;
	
	examples = 0;
	rep(i, 0, n) {
		cin >> file[i] >> small[i];
		examples += small[i];
	}
	
	vi satisfied(n + 1, false);
	auto is_correct = [&](int i) -> bool {
		int id = get_id(file[i]);
		if (id == -1) return false;
		if (small[i] && id <= examples) {
			jest[id] = true;
			satisfied[id] = true;
			return true;
		}
		if (!small[i] && id > examples) {
			jest[id] = true;
			satisfied[id] = true;
			return true;
		}
		return false;
	};
	
	vector <string> wrong_smalls;
	vector <string> wrong_larges;
	
	rep(i, 0, n) {
		if (!is_correct(i)) { //we will do something
			int id = get_id(file[i]);
			if (id == -1) { //this is some wrong string
				if (small[i]) wrong_smalls.pb(file[i]);
				else wrong_larges.pb(file[i]);
			}
			else { //the string is correct, but on the wrong place
				if (small[i]) smalls.pb(id);
				else larges.pb(id);
			}
		}
	}
	
	debug(wrong_smalls);
	debug(wrong_larges);
	
	debug(smalls);
	debug(larges);
	
	debug(jest);
	vector <pair<string, string> > ans;
	
	auto print = [&]() {
		cout << sz(ans) << endl;
		trav(odp, ans) cout << "move " << odp.e1 << ' ' << odp.e2 << "\n";
		exit(0);
	};
	
	if (wrong_smalls.empty() && wrong_larges.empty()) { //the very annoying case
		assert(sz(smalls) == sz(larges));
		int k = sz(smalls);
		debug(smalls);
		debug(larges);
		string tmp = "tmp";
		if (k > 0) ans.pb(make_pair(to_string(larges[0]), tmp));
		rep(i, 0, k) {
			if (i > 0) ans.pb({to_string(larges[i]), to_string(smalls[i-1])});
			ans.pb({to_string(smalls[i]), to_string(larges[i])});
		}
		if (k > 0) ans.pb({tmp, to_string(smalls[k-1])});
		print();
	}
	
	// second case - no unnecessary moves
	int nast = 1;
	trav(u, smalls) jest[u] = 1;
	trav(u, larges) jest[u] = 1;
	
	while (jest[nast]) ++nast;
	assert(nast <= n);
	debug(nast);
	int is_small = (nast <= examples);
	
	while (!smalls.empty() && !larges.empty()) {
		int co;
		if (is_small) {
			co = smalls.back();
			smalls.pop_back();
		}
		else {
			co = larges.back();
			larges.pop_back();
		}
		
		ans.pb({to_string(co), to_string(nast)});
		satisfied[nast] = 1; //tam juz nie mozna polozyc
		nast = co;
		is_small ^= 1; //teraz zamieniamy
		debug(nast);
	}
	
	auto place = [&](string co, int &ID) {
		while (satisfied[ID]) ++ID;
		ans.pb({co, to_string(ID)});
		satisfied[ID] = 1;
	};
	
	int STS = 1, STL = examples + 1;
	while (!smalls.empty()) {
		int co = smalls.back();
		smalls.pop_back();
		
		place(to_string(co), STS);
	}
	
	while (!larges.empty()) {
		int co = larges.back();
		larges.pop_back();
		
		place(to_string(co), STL);
	}
	
	while (!wrong_larges.empty()) {
		string co = wrong_larges.back();
		wrong_larges.pop_back();
		place(co, STL);
	}
	
	while (!wrong_smalls.empty()) {
		string co = wrong_smalls.back();
		wrong_smalls.pop_back();
		place(co, STS);
	}
	
	print();
}

int main() {
	boost;
	int tests;
	//cin >> tests;
	tests = 1;
	FOR(test, 1, tests) {
		solve(test);
	}
}