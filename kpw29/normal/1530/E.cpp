#include <bits/stdc++.h>
using namespace std;

#define e1 first
#define e2 second
#define pb push_back
#define mp make_pair
#define boost {ios_base::sync_with_stdio(false); cin.tie(0); }
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
int n, sm;

string res;

bool check(int k, vector <int> &ile, bool print) {
	int other = 0;
	for (int c = sm + 1; c < 26; ++c) other += ile[c];
	
	if (ile[sm] <= k + 1) {
		if (print) {
			res = "";
			rep(dig, 0, 26) {
				FOR(step, 1, ile[dig]) res += (char)(dig + 'a');
			}
		}
		
		return true;
	}
	else {
		res = "";
		FOR(step, 1, k + 1) {
			ile[sm]--;
			if (print) res += (char)(sm + 'a');
		}
		
		if ((ll)ile[sm] > (ll)k * other) return false;
		if (print) {
			int co = sm + 1;
			int ciag_a = k;
			while ((int)res.size() < n) {
				if (ile[sm] == 0 || ciag_a == k) {
					ciag_a = 0;
					while (ile[co] == 0) ++co;
					ile[co]--;
					res += (char)(co + 'a');
				}
				else {
					ciag_a++;
					ile[sm]--;
					res += (char)(sm + 'a');
				}
			}
		}
		
		return true;
	}
}

void solve() {
	res = "";
	string s;
	cin >> s;
	n = s.size();
	
	vector <int> ile(26, 0);
	vector <int> pom(26, 0);
	rep(i, 0, n) {
		ile[s[i] - 'a']++;
		pom[s[i] - 'a']++;
	}
	
	rep(i, 0, 26) {
		if (ile[i] == 1) {
			string wyn = "";
			rep(j, 0, n) {
				if (s[j] - 'a' != i) wyn += s[j];
			}
			
			sort(all(wyn));
			cout << (char)(i + 'a');
			cout << wyn << "\n";
			return;
		}
		
		if (ile[i] == n) {
			cout << s << "\n";
			return;
		}
	}
	
	// all chars at least 2 times
	
	sm = 0;
	while (ile[sm] == 0) ++sm;
	
	bool b = check(1, ile, 1);
	if (b) { //impossible starting with two same characters	
		cout << res << "\n";
	}
	else { //starting with string ab
		rep(j, 0, 26) ile[j] = pom[j];
		res = "";
		int aa = sm;
		int bb = aa + 1;
		while (ile[bb] == 0) ++bb;
		int cc = bb + 1;
		while (cc < 26 && ile[cc] == 0) ++cc;
		
		if (cc == 26) { //abbbbbbaaaaaaaa
			res = "";
			res += (char)(aa + 'a');
			FOR(step, 1, ile[bb]) res += (char)(bb + 'a');
			FOR(step, 2, ile[aa]) res += (char)(aa + 'a');
			cout << res << "\n";
		}
		else {
			res = "";
			res += (char)(aa + 'a');
			res += (char)(bb + 'a');
			ile[bb]--;
			FOR(step, 2, ile[aa]) res += (char)(aa + 'a');
			ile[cc]--;
			res += (char)(cc + 'a');
			rep(dig, bb, 26) {
				FOR(step, 1, ile[dig]) res += (char)(dig + 'a');
			}
			
			cout << res << "\n";
		}
		
	}
	
}

int main() {
	boost;
	int tests;
	//tests = 1;
	cin >> tests;
	while (tests--) {
		solve();
	}
}