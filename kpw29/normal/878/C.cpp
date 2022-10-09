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

multiset <vector <PII> > s;

bool przecinaja(multiset <vector <PII> > :: iterator wiekszy, multiset <vector <PII> > :: iterator mniejszy) {
	debug(*wiekszy);
	debug(*mniejszy);
	
	rep(i, 0, k) {
		if ((*wiekszy)[i].e1 < (*mniejszy)[i].e2) return true;
	}
	
	return false;
}

multiset <vector <PII> > :: iterator merge(multiset <vector <PII> > :: iterator iter, multiset <vector <PII> > :: iterator other) {
	debug("Merging");
	auto vec = s.extract(iter).value();
	auto oth = s.extract(other).value();
	debug(vec);
	debug(oth);
	rep(i, 0, k) {
		vec[i].e1 = min(vec[i].e1, oth[i].e1);
		vec[i].e2 = max(vec[i].e2, oth[i].e2);
	}
	
	vec[k].e1 += oth[k].e1;
	s.insert(vec);
	return s.find(vec);
}

void place(vector <PII> current) {
	s.insert(current);
	auto iter = s.find(current);
	
	
	while (true) {
		auto second = iter; ++second;
		if (second == s.end()) break;
		if (!przecinaja(second, iter)) break;
		iter = merge(iter, second);
	}
	
	while (true) {
		auto second = iter;
		if (second == s.begin()) break;
		--second;
		if (!przecinaja(iter, second)) break;
		iter = merge(iter, second);
	}
	
	/*trav(elem, s) {
		cout << "Elem : " << elem[k].e1 << endl;
		rep(i, 0, k) cout << "(" << elem[i].e1 << " -> " << elem[i].e2 << ")" << endl;
	}*/
}

int main() {
	cin >> n >> k;
	rep(i, 0, n) {
		vector<PII> zawodnik(k + 1);
		rep(j, 0, k) {
			int val;
			cin >> val;
			zawodnik[j].e1 = zawodnik[j].e2 = val;
		}
		zawodnik[k].e1 = 1;
		place(zawodnik);
		auto it = --s.end();
		cout << (*it)[k].e1 << "\n";
	}
	
	
}