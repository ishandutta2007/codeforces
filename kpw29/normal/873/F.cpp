#include <bits/stdc++.h>
using namespace std;
#define e1 first
#define e2 second
#define pb push_back
#define mp make_pair
#define boost ios_base::sync_with_stdio(false)
#define eb emplace_back
#define OUT(x) {cout << x; exit(0); }
#define FOR(i, a, b) for (int i=(a); i<=(b); ++i)
typedef long long ll;
typedef unsigned long long ull;
typedef pair <int, int> PII;
typedef pair <ll, ll> PLL;
typedef pair <PLL, PLL> PP;
typedef unsigned int ui;
const int mod = 1e9+7;
const int inf = 1e9+9;
const ll MOD = 1e9+696969;
const ll INF = 1e18;
int n, a, wyn = 0;
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

struct state {
    int len, link;
    map<char,int>next;
};
int DL, LAST;
const int maxn = 1000100;
state st[2 * maxn];
bool finish[2 * maxn];
int goodends[2 * maxn];

void initAutomaton()
{
	DL = 0; LAST = 0;
	st[0].len = 0;
	st[0].link = -1;
	++DL;
}

void addLetter(char c, int dodaj)
{
	int cur = DL++;
	st[cur].len = st[LAST].len + 1;
	goodends[cur] = dodaj;
	
	int p;
	for (p = LAST; p != -1 && !st[p].next.count(c); p = st[p].link) st[p].next[c] = cur;
	if (p == -1) st[cur].link = 0;
	else
	{
		int q = st[p].next[c];
		if (st[p].len + 1 == st[q].len) st[cur].link = q;
		else
		{
			int clone = DL++;
			st[clone].len = st[p].len + 1;
			st[clone].next = st[q].next;
			st[clone].link = st[q].link;
			//goodends[clone] = dodaj;
			for (; p != -1 && st[p].next[c] == q; p = st[p].link) st[p].next[c] = clone;
			st[q].link = clone;
			st[cur].link = clone;
		}
	}
	LAST = cur;
}

string s;
ll res;


string forb;
vector <int> v[2 * maxn];
bool odw[2 * maxn];

void dfs(int x) {
	odw[x] = 1;
	for (auto u : v[x]) {
		if (!odw[u]) dfs(u);
		goodends[x] += goodends[u];
	}
	
	res = max(res, (ll)goodends[x] * st[x].len);
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> s >> forb;
	initAutomaton();
	FOR(i, 0, n-1) addLetter(s[i], 1-(forb[i]-'0'));
	
	for (int i=1; i<DL; ++i) v[st[i].link].push_back(i);
	dfs(0);
	for (int i = DL - 1; i > 0; --i) {
		res = max(res, (ll)goodends[i] * st[i].len);
	}
	
	/*FOR(i, 0, DL - 1) {
		debug(i);
		debug(st[i].link, st[i].len, goodends[i]);
		for (auto u : st[i].next) debug(u);
		cout << endl;
	}*/
	
	cout << res;
}