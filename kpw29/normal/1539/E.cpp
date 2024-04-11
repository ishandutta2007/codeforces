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
const int maxn = 100100;

int card[maxn], n, m;
PII reqs[maxn][2];

int previous[maxn][2];
set <PII> valid_cards[2];
bool possible[maxn][2];

bool in_range(int i, int which_hand) {
	return reqs[i][which_hand].e1 <= card[i] && card[i] <= reqs[i][which_hand].e2;
}

void trim(int which_set, int i) {
	int which_hand = (1 ^ which_set);
	while (!valid_cards[which_set].empty()) {
		auto it = valid_cards[which_set].begin();
		if (it -> first < reqs[i][which_hand].e1) valid_cards[which_set].erase(it);
		else break;
	}
	
	while (!valid_cards[which_set].empty()) {
		auto it = --valid_cards[which_set].end();
		if (it -> first > reqs[i][which_hand].e2) valid_cards[which_set].erase(it);
		else break;
	}	
}

int main() {
	boost;
	cin >> n >> m;
	FOR(i, 1, n) {
		cin >> card[i];
		cin >> reqs[i][0].e1 >> reqs[i][0].e2;
		cin >> reqs[i][1].e1 >> reqs[i][1].e2;
	}
	
	possible[0][0] = possible[0][1] = 1;
	valid_cards[0].insert({0, 0});
	valid_cards[1].insert({0, 0});
	// initialization done
	
	FOR(i, 1, n) {
		bool b0 = in_range(i, 0), b1 = in_range(i, 1);
		if (b1) { // calculating possible[i][1]
			// the previous valid set is still valid, but we may consider adding one more element
			if (possible[i-1][0]) valid_cards[1].insert({card[i-1], i-1});
			trim(1, i);
		}
		else valid_cards[1].clear();
		
		if (b0) {
			if (possible[i-1][1]) valid_cards[0].insert({card[i-1], i-1});
			trim(0, i);
		}
		else valid_cards[0].clear();
		
		rep(hand, 0, 2) {
			if (!valid_cards[hand].empty()) {
				possible[i][hand] = true;
				previous[i][hand] = valid_cards[hand].begin() -> e2;
			}
			else possible[i][hand] = false;
		}
		
		if (!possible[i][0] && !possible[i][1]) OUT("No\n");
	}
	
	vector <int> ans(n+1, 0);
	
	int where = 0;
	if (!possible[n][0]) where = 1;
	int i = n;
	while (i > 0) {
		assert(possible[i][where]);
		int j = previous[i][where];
		while (i > j) {
			ans[i] = where;
			--i;
		}
		
		where ^= 1;
	}
	
	cout << "Yes\n";
	FOR(j, 1, n) cout << ans[j] << ' ';
}