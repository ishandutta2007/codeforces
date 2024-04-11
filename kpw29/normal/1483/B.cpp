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


const int maxn = 100100;

int tab[maxn], n, m;
set <int> wrongs;
set <int> numbers;
vector <int> res;

set <int> :: iterator get_next(set <int> :: iterator iter) {
	++iter;
	if (iter == numbers.end()) return numbers.begin();
	return iter;
}

set <int> :: iterator get_prev(set <int> :: iterator iter) {
	if (iter == numbers.begin()) return --numbers.end();
	--iter;
	return iter;
}

void walk(int x) {
	//debug("walk", x);
	if (wrongs.empty()) return;
	set <int> :: iterator it = wrongs.lower_bound(x);
	if (it == wrongs.end()) {
		it = wrongs.lower_bound(0);
		if (it == wrongs.end()) return;
	}
	
	//I got new element
	int value = *it;
	res.push_back(value);
	set <int> :: iterator position = numbers.find(value);
	//assert(position != numbers.end());
	wrongs.erase(value);
	auto nast_pos = *get_next(position);
	position = numbers.find(value);
	auto prev_pos = *get_prev(position);
	//position = numbers.find(value);

	numbers.erase(value);
	if (numbers.empty()) return;
	wrongs.erase(nast_pos);

	if (__gcd(tab[nast_pos], tab[prev_pos]) == 1) {
		wrongs.insert(nast_pos);
	}
	
	walk(1 + nast_pos);
}

void solveone(int z) {
	wrongs.clear();
	numbers.clear();
	
	cin >> n;
	//n = 10;
	FOR(i, 0, n-1) {
		cin >> tab[i];
		//tab[i] = rand()%10 + 2;
		numbers.insert(i);
	}
	
	FOR(i, 0, n-1) {
		if (__gcd(tab[i], tab[(i+1)%n]) == 1) {
			wrongs.insert((i+1)%n);
		}
	}
	
	res.clear();
	walk(1);
	cout << res.size() << ' ';
	for (auto u : res) cout << u + 1 << ' ';
	cout << "\n";
}

int main() {
	//boost;
	int tests;
	//tests = 1;
	cin >> tests;
	FOR(_, 1, tests) {
		solveone(tests);
	}
}