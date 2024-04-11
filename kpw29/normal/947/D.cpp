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

pii calc(vi &v, vi &pref, int a, int b) { //{B, A}
	int suff = min(v[b], b - a + 1);
	return {pref[b] - pref[a-1], suff};
}

bool answer(pii start, pii finish) {
	if (start.e1 > finish.e1) return false; //Bs cannot disappear: start <= finish must hold
	if (start.e1 % 2 != finish.e1 % 2) return false; //only even change
	int delta = (finish.e1 - start.e1) / 2;
	int A = start.e2;
	
	if (delta == 0) {
		return A >= finish.e2 && (A % 3 == finish.e2 % 3);
	}
	else if (start.e1 == 0) {
		return (A > finish.e2);
	} else {
		return (A >= finish.e2);
	}
}

int main() {	
	string s, t;
	cin >> s >> t;
	
	int n = sz(s);
	vi pie(n + 1, 0);
	vi prefS(n + 1, 0);
	
	FOR(i, 1, n) {
		prefS[i] = prefS[i-1];
		char zn = s[i - 1];
		if (zn == 'A') pie[i] = 1 + pie[i-1];
		else pie[i] = 0, ++prefS[i];
	}
	
	n = sz(t);
	vi dru(n + 1, 0);
	vi prefT(n + 1, 0);
	FOR(i, 1, n) {
		prefT[i] = prefT[i-1];
		char zn = t[i - 1];
		if (zn == 'A') dru[i] = 1 + dru[i-1];
		else dru[i] = 0, ++prefT[i];
	}
	
	int q;
	cin >> q;
	while (q--) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		pii start = calc(pie, prefS, a, b);
		pii finish = calc(dru, prefT, c, d);
		bool bi = answer(start, finish);
		cout << bi;
	}
}