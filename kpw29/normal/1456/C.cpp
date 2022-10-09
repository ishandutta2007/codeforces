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

const int maxn = 500100;
int n, m, k;
ll bet[maxn];
ll tab[maxn];
ll pref[maxn];
ll sumpref[maxn];
ll jump_k[maxn];
vector <ll> uje, dod;
ll pref_uje[maxn];

int dd;

ll scoreDod(int value) {
	value += dod.size();
	return sumpref[value] - pref[value];
}

ll cost_neg, last_ind = 0;

int sufit(int i, int j) {
	if (i % j == 0) return i/j;
	return 1+i/j;
}

void upd(int i) {
	ll elem = (ll) i * (k + 1);
	ll ind = (ll)uje.size() - elem;
	
	int natural_max = sufit(uje.size() - last_ind - 1, k + 1) - 1;
	int high_number = i - 1;
	debug(high_number, natural_max);
	if (ind < 0) {
		debug("HERE");
		if (high_number > natural_max) {
			++last_ind;
			debug("Biore: ", i);
			
			//base change
			debug(i, natural_max, pref_uje[last_ind]);
			ll total_deduct = 0;
			total_deduct += pref_uje[last_ind];
			//if last element then also one more
			int exc = high_number - natural_max;
			if ((uje.size() - exc) % (k + 1) == 0) {
				++last_ind;
				total_deduct += uje[last_ind];
			}
			
			cost_neg += total_deduct;
			debug(total_deduct);
		}
		return;
	}
	cost_neg -= jump_k[ind];
}

void solveone() {
	cin >> n >> k;
	last_ind = -1;
	FOR(i, 1, n) {
		cin >> tab[i];
		if (tab[i] >= 0) {
			dod.pb(tab[i]);
		}
		else {
			uje.pb(tab[i]);
		}
	}
	
	sort(tab+1, tab+n+1, greater<int>());
	if (k == 0 || uje.empty()) {
		ll r = 0;
		FOR(i, 1, n) r += (ll)(n - i) * tab[i];
		OUT(r);
	}
	
	dd = dod.size();
	sort(dod.begin(), dod.end(), greater<int>());
	FOR(i, 1, n) {
		if (i <= dd) bet[i] = dod[i - 1];
		else bet[i] = 0;
		
		pref[i] = pref[i - 1] + bet[i];
		sumpref[i] = sumpref[i - 1] + pref[i];
	}
	
	sort(uje.begin(), uje.end(), greater<int>());
	//zaczynamy od tego ze nie bierzemy zadnej ujemnej
	int sz = uje.size();
	for (int il = 0; il < sz; ++il) {
		pref_uje[il] = uje[il];
		if (il > 0) pref_uje[il] += pref_uje[il - 1];
		
		jump_k[il] = uje[il];
		if (il >= k) jump_k[il] += jump_k[il - k];
	}
	
	int freq = 0, pozostalo = k;
	
	cost_neg = 0;
	for (int i = sz - 1; i >= 0; --i){ 
		--pozostalo;
		debug(uje[i], freq);
		cost_neg += (ll)freq * uje[i];
		if (pozostalo == 0) {
			pozostalo = k;
			++freq;
		}
	}
	
	ll result = scoreDod(0) + cost_neg;
	debug(result);
	for (int taken = 1; taken <= sz; ++taken) {
		upd(taken);
		result = max(result, scoreDod(taken) + cost_neg);
		ll sd = scoreDod(taken);
		debug(taken, sd, cost_neg);
	}
	
	cout << result;
}

int main() {
	boost;
	int tests;
	tests = 1;
	//cin >> tests;
	FOR(_, 1, tests) solveone();
}