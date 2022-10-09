    #include <bits/stdc++.h>
    //#include <atcoder/modint>
    //using namespace atcoder;
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
    const int mod = 1e9+7;
     
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
     
     
    int edge[105][105];
     
    bool LOCAL = 0;
    bool ask(int x, int y) {
    	cout << 1 << ' ' << x-1 << ' ' << y-1 << endl;
    	int res;
    	if (!LOCAL) {
    		cin >> res;
    		if (res == -1) exit(9);
    	}
    	else {
    		res = edge[x][y];
    	}
    	return res;	
    }
     
    bool ask_range(int x, vector <int> s) {
    	if (s.empty()) return false;
    	sort(s.begin(), s.end());
    	cout << 2 << ' ' << x - 1 << ' ' << (int)s.size() << ' ';
    	for (int i=0; i+1<(int)s.size(); ++i) cout << s[i] - 1 << ' ';
    	cout << s[s.size() - 1] - 1 << endl;
    	
    	int res;
    	if (!LOCAL) {
    		cin >> res;
    		if (res == -1) exit(9);
    	}
    	else {
    		res = false;
    		for (auto u : s) {
    			if (edge[x][u]) res = true;
    		}
    	}
    	
    	return res;
    }
     
     
    vector <int> merge(vector <int> a, vector <int> b) {
    	int ait = 0, bit = 0;
    	vector <int> res = {};
    	
    	while (ait < a.size() && bit < b.size()) {
    		if (ask(a[ait], b[bit])) {
    			res.pb(a[ait++]);
    		}
    		else {
    			res.pb(b[bit++]);
    		}
    	}
    	
    	while (ait < a.size()) res.push_back(a[ait++]);
    	while (bit < b.size()) res.push_back(b[bit++]);
    	
    	return res;
    }
     
    vector <int> path(vector <int> v) {
    	int h = (int)v.size();
    	if (h <= 1) return v;
    	
    	vector <int> v1 = {};
    	vector <int> v2 = {};
    	
    	for (int i=0; i<h; ++i) {
    		if (i % 2 == 0) v1.push_back(v[i]);
    		else v2.push_back(v[i]);
    	}
    	
    	return merge(path(v1), path(v2));
    }
     
    int result[105][105];
    int start_new[105];
     
    void solveone() {
    	int n;
    	cin >> n;
    	
    	if (LOCAL) {
    		FOR(i, 1, n) FOR(j, 1, n) cin >> edge[i][j];
    	}
    	
    	vector <int> nodes = {};
    	for (int i=1; i<=n; ++i) nodes.pb(i);
    	
    	vector <int> top_order = path(nodes);
    	//debug(top_order);
    	
    	FOR(i, 1, n) {
    		FOR(j, 1, n) result[i][j] = 0;
    	}
    	
    	reverse(top_order.begin(), top_order.end());
    	
    	for (int a=0; a<n; ++a) {
    		for (int b=a; b<n; ++b) {
    			result[top_order[b]][top_order[a]] = 1;
    		}
    	}
    	
    	int prev_comp = -1;
    	int max_comp = 0;
    	
    	for (int i=0; i<n; ++i) {
    		int node = top_order[i];
    		
    		while (true) {
    			vector <int> pytaj = {};
    			for (int j = max_comp + 1; j < n; ++j) pytaj.push_back(top_order[j]);
    			if (ask_range(node, pytaj)) {
    				++max_comp;
    			}
    			else break;
    		}
    		
    		if (max_comp == i) { // found a boundary
    			for (int a = prev_comp + 1; a <= max_comp; ++a) {
    				for (int b = prev_comp + 1; b <= max_comp; ++b) result[top_order[a]][top_order[b]] = 1;
    			}
    			
    			prev_comp = max_comp;
    			max_comp = i + 1;
    		}
    	}
    	
    	cout << 3 << endl;
    	FOR(i, 1, n) {
    		FOR(j, 1, n) cout << result[i][j];
    		cout << endl;
    	}

int ffs; cin >> ffs;
    }
     
    int main() {
    	int tests;
    	//tests = 1;
    	cin >> tests;
    	FOR(_, 1, tests) {
    		solveone();
    	}
    }