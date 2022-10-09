#include <bits/stdc++.h>
using namespace std;
#define e1 first
#define e2 second
#define pb push_back
#define mp make_pair
#define boost ios_base::sync_with_stdio(false)
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
typedef pair <PLL, pair <int, ll> > PP;
typedef pair <PII, int> PPI;
typedef pair <int, PII> PIP;
typedef pair <ll, int> PLI;
typedef unsigned int ui;
const int inf = 1e9+9;
const ll mod = 1e9+696969;
const ll MOD = 1e9+696969;
const long long INF = 1e18+3;
map <int, vector <int> > M;
int n;
map <int, int> skal;
vector <int> tp;


inline ll f(ll x) {return x * (x - 1) / 2 + x; }
const int maxn = 200100;
int A[maxn], B[maxn];
ll dr[maxn];
int jest[maxn];
inline void add(int p, ll v) {
	for (; p < maxn; p += p & (-p)) dr[p]+=v;
}

inline ll get(int p) {
	ll res = 0;
	for (; p > 0; p -= p & (-p)) res += dr[p];
	return res;
}

inline ll query(int a, int b) {
	if (a > b) return 0;
	return get(b) - get(a - 1);
}

int main()
{
	boost;
	cin >> n;
	FOR(i, 1, n) {
		int x, y;
		cin >> x >> y;
		A[i] = x; B[i] = y;
		tp.pb(x);
	}
	
	sort(tp.begin(), tp.end());
	int SKAL = 0;
	skal[tp[0]] = ++SKAL;
	for (int i=1; i<(int)tp.size(); ++i)
		if (tp[i] != tp[i - 1]) skal[tp[i]] = ++SKAL;
	FOR(i, 1, n) {
		A[i] = skal[A[i]];
		M[-B[i]].push_back(A[i]);
	}
		
	ll result = 0;
	for (auto &u : M) {
		vector <int> v = u.e2;
		sort(v.begin(), v.end());
		for (auto elem : v) {
			if (!jest[elem]) jest[elem] = 1, add(elem, 1);
		}
		int sz = (int)v.size();
		result += f(query(1, n));
		result -= f(query(1, v[0] - 1));
		result -= f(query(v[sz - 1] + 1, n));
		
		for (int i=1; i<sz; ++i) result -= f(query(v[i - 1] + 1, v[i] - 1));
	}
	
	cout << result;
}