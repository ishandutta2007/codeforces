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


const int maxn = 1000100;
ll n, m, k, a, b, c;
ll tab[maxn];

string s;

void merge(int i, int j, vector <int> &odd, vector <int> &even) {
	//cout << i << ' ' << j << odd.size() << ' ' << even.size() << endl;
	
	if (i >= (int)odd.size() && j >= (int)even.size()) return;
	if (j < (int)even.size() && (i >= (int)odd.size() || odd[i] > even[j])) {
		cout << even[j];
		merge(i, j + 1, odd, even);
		return;
	}
	
	if (i < (int)odd.size()) {
		cout << odd[i];
		merge(i + 1, j, odd, even);
		return;
	}
	else if (j < (int)even.size()) {
		cout << even[j];
		merge(i, j + 1, odd, even);
		return;
	}
}

int main()
{
	boost;
	cin >> n;
	while (n--) {
		cin >> s;
		vector <int> odd = {}, even = {};
		m = s.length();
		for (int i=0; i<m; ++i) {
			int value = s[i] - '0';
			if (value % 2 == 0) even.push_back(value);
			else odd.push_back(value);
		}

		merge(0, 0, odd, even);
		cout << endl;
	}
}