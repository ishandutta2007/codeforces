#include <bits/stdc++.h>
using namespace std;
#define e1 first
#define e2 second
#define pb push_back
#define mp make_pair
#define boost {ios_base::sync_with_stdio(false); }
#define eb emplace_back
#define OUT(x) {cout << x; exit(0); }
#define REYNA(i,a,b) for(int i=(a);i<(b);++i)
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
const int mod = 1e9+7;
const int inf = 1e9+9;
const ll MOD = 1e9+696969;
const long long INF = 1e18+3;
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


const int maxn = 200100;
ll n, m, a, b, c;
PLL tab[maxn];

int t;
ll half;

ll check(ll k) {
	ll sm = 0, lrg = 0;
	ll B = b;
	vector <ll> options = {};
	ll wz = 0;
	FOR(i, 1, n) {
		if (k < tab[i].e1) ++lrg, B -= tab[i].e1, ++wz;
		else {
			if (k > tab[i].e2) ++sm, B -= tab[i].e1, ++wz;
			else  {
				//assert(tab[i].e1 <= k && k <= tab[i].e2);
				options.pb(tab[i].e1);
			}
		}
		
		if (B < 0) return -2;
	}
	
	if (lrg > (n / 2)) return -1;
	if (sm > (n / 2)) return -2;
	
	//debug(k);
	sort(options.begin(), options.end());
	assert(sm < half);
	
	int rest = half - sm - 1;//tyle jeszcze trzeba wziac
	//debug(rest);
	for (int i=0; i<rest; ++i) {
		B -= options[i];
		++wz;
		
		if (B < 0) return -2;
	}
	
	if ((n - wz) * k<= B) return 1;
	else return -2;
}

int main()
{
	boost;
	cin >> t;
	while (t--) {
		cin >> n >> b;
		FOR(i, 1, n) cin >> tab[i].e1 >> tab[i].e2;
		ll x = 0, y = inf;
		half = (n + 1) / 2;
		//FOR(step, 0, 20) debug(check(step));
		
		while (x < y) {
			ll sr = ((x + y) / 2) + 1;
			ll val = check(sr);
			//debug(x, y, sr, val);
			
			if (val == -1) x = ++sr; //trzeba wiecej dac pieniedzy
			else if (val == -2) y = --sr; //trzeba mniej dac pieniedzy
			else x = sr; //dalo sie tak przyporzadkowac, nie trzeba mniej
		} 
		
		ll val = check(x);
		assert(val != -2);
		cout << x << endl;
	}
}