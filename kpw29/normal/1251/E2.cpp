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

ll req[maxn], cost[maxn];
PLL tmp[maxn];

ll bribe(ll k) {
	ll bribe_all = 0;
	FOR(i, 1, n) {
		bribe_all += cost[i];
		tmp[i].e1 = max(0LL, req[i] - k);
		tmp[i].e2 = i;
	}
	
	sort(tmp+1, tmp+n+1);
	int added = 0, j = 1;
	priority_queue <PLL> q;
	
	FOR(i, 1, n-k) {
		while (j <= n && tmp[j].e1 <= added) {
			int u = tmp[j].e2;
			q.push(mp(cost[u], u));
			++j;
		}
		++added;
		if (q.empty()) return -1;
		PLL tp = q.top();
		q.pop();
		bribe_all -= tp.e1;
		//debug(tp.e2);
	}
	
	return bribe_all;
}

int main()
{
	boost;
	cin >> t;
	while (t--) {
		cin >> n;
		FOR(i, 1, n) cin >> req[i] >> cost[i];
		int x = 0, y = n;
		while (x < y) {
			int sr = (x + y) / 2;
			if (bribe(sr) == -1) x = ++sr;
			else y = sr;
		}
		
		cout << bribe(x) << "\n";
	}
}