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
     
    const int maxn = 1000100;
    ll pref[maxn];
     
    void solveone() {
    	int n, m, k, a, b, c, d;
    	string s;
    	cin >> n >> d >> m;
    	vector <int> tab(n);
    	vector <int> small, large;
    	
    	FOR(i, 1, n) {
    		cin >> tab[i-1];
    		if (tab[i-1] > m) large.pb(tab[i-1]);
    		else small.pb(tab[i-1]);
    	}
    	
    	sort(small.begin(), small.end(), greater<int>());
    	sort(large.begin(), large.end(), greater<int>());
    	pref[0] = 0;
    	FOR(i, 1, n + 1) {
    		if (i > large.size()) pref[i] = pref[i-1];
    		else pref[i] = pref[i-1] + large[i-1];
    	}
    	
    	int sz = small.size();
    	
    	ll BEST = 0;
    	
    	ll sum_small = 0, sum_large = 0;
    	for (int i=0; i<=sz; ++i) {
    		int rest_days = n - i;
    		int taken = rest_days / (d + 1);
    		if (rest_days % (d + 1) != 0) taken++;
    		//debug(i, taken, sum_small, pref[taken]);
    		BEST = max(BEST, sum_small + pref[taken]);
    		if (i < sz) sum_small += small[i];
    	}
    	
    	cout << BEST;
    }
     
    int main() {
    	boost;
    	int tests = 1;
    	FOR(_, 1, tests) solveone();
    	int xd = 5;
    }