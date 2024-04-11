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
typedef pair <PLL, PLL > PP;
typedef pair <PII, int> PPI;
typedef pair <int, PII> PIP;
typedef pair <ll, int> PLI;
typedef unsigned int ui;
const int mod = 998244353;
const int inf = 1e9+9;
const ll MOD = 1e9+696969;
const long long INF = 4LL * 1000000LL * 1000000LL * 1000000LL;

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
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
inline void addmod(int &x, int val) {
	x += val;
	while (x >= mod) x -= mod;
}
const int maxn = 200100;

bool poss(int i, PII stan1, int j, PII stan2) {
	assert(i <= j);
	if (i == j) {
		return stan1 == stan2;
	}
	
	int dst = j - i - 1; //liczb pomiedzy
	if (stan1.e1 == stan2.e1) {
		return (stan1.e2 + dst + 1 == stan2.e2);
	}
	else {
		int must_be = (stan1.e2 == 1 ? 1 : 0);
		int more_copies = 5 - stan1.e2 - must_be; //ile jeszcze mozna wcisnac tego elementu
		must_be += stan2.e2 - 1;
		int MIN = must_be + (stan2.e1 - stan1.e1 - 1) * 2;
		int MAX = more_copies + must_be + (stan2.e1 - stan1.e1 - 1) * 5;
		//for init number
		return (MIN <= dst && dst <= MAX);
	}
}


int nast(int i, PII stan1, int j, PII stan2) {
	assert(i <= j);
	if (i == j) return stan1.e1;
	
	if (stan1.e1 == stan2.e1) return stan1.e1;

	int value = stan1.e1;
	if (stan1.e2 != 5) {
		if (poss(i + 1, make_pair(value, stan1.e2 + 1), j, stan2)) return value;
	}
	
	return value + 1;
}

int n;
vector <int> pos;
bool dp[maxn][6];
int tab[maxn];

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n;
	//init
	pos.push_back(0);
	dp[0][5] = 1;
	
	int lt = 0;
	for (int i=1; i<=n; ++i) {
		cin >> tab[i];
		if (tab[i] > 0) {
			pos.push_back(i);
			lt = i;
		}
	}
	
	int sz = pos.size();
	for (int i = 0; i + 1 < sz; ++i) {
		int lewe = pos[i], prawe = pos[i + 1];
		for (int a = 1; a <= 5; ++a) {
			if (dp[lewe][a]) {
				for (int b = 1; b <= 5; ++b) {
					if (poss(lewe, {tab[lewe], a}, prawe, {tab[prawe], b})) {
						debug(lewe, a, prawe, b);
						dp[prawe][b] = 1;
					}
				}
			}
		}
	}
	
	bool odp = false, ans = false;
	int ka = 0;
	if (tab[n] == 0) {
		for (int value = n; value > 0; --value) {
			for (int a=1; a<=5; ++a) {
				for (int b=2; b<=5; ++b) {
					if (!ans && dp[lt][a] && poss(lt, {tab[lt], a}, n, {value, b})) {
						tab[n] = value;
						dp[n][b] = true;
						pos.push_back(n); 
						ans = true;
					}
				}
			}
		}
	}
	
	for (int a=2; a<=5; ++a)
		if (dp[n][a]) odp = true, ka = a;
	
	if (!odp) OUT("-1");
	sz = pos.size();
	for (int i = sz - 2; i >= 0; --i) {
		int lewe = pos[i], prawe = pos[i + 1];
		for (int a = 1; a <= 5; ++a) {
			if (!dp[lewe][a]) continue;
			if (poss(lewe, {tab[lewe], a}, prawe, {tab[prawe], ka})) {
				int kal = a;
				for (int ruch = lewe; ruch + 1 < prawe; ++ruch) {
					int wstawie = nast(ruch, {tab[ruch], kal}, prawe, {tab[prawe], ka});
					if (wstawie == tab[ruch]) ++kal;
					else kal = 1;
					tab[ruch + 1] = wstawie;
				}
				
				ka = a;
				break;
			}
		}
	}
	
	cout << tab[n] << "\n";
	for (int i=1; i<=n; ++i) cout << tab[i] << ' ';
}