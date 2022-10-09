#include <bits/stdc++.h>
using namespace std;
#define e1 first
#define e2 second
#define pb push_back
#define mp make_pair
#define boost {ios_base::sync_with_stdio(false); cin.tie(0); }
#define eb emplace_back
#define OUT(x) {cout << x; exit(0); }
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
const int mod = 998244353;

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

const int maxn = 1001000;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int n, HALF;
string s[15];
bool knows[15][15];

int spos[1 << 14][14][64];
vector <int> zbior[1 << 14];

int odwroc[15][1 << 14];
vector <int> goodsubsets;

ll wynik[1 << 14];

int main() {
	for (int BIT_SIZE = 1; BIT_SIZE <= 14; ++BIT_SIZE) {
		int sz = (1 << BIT_SIZE);
		for (int liczba = 0; liczba < sz; ++liczba) {
			for (int i = 0; i < BIT_SIZE; ++i) {
				if (liczba & (1 << (BIT_SIZE - i - 1))) odwroc[BIT_SIZE][liczba] += (1 << i);
			}
		}
	}

	boost;
	cin >> n;
	HALF = n / 2;
	FOR(i, 0, n-1) cin >> s[i];
	FOR(i, 0, n-1)
		FOR(j, 0, n-1)
			knows[i][j] = (s[i][j] == '1')?1 : 0;
	
	int SIZE = (1 << n);
	FOR(subset, 1, SIZE - 1) {
		if (__builtin_popcount(subset) > 7) continue;
		vector <int> positions;
		
		for (int i=0; i<n; ++i)
			if (subset & (1 << i)) positions.push_back(i);
		
		zbior[subset] = positions;
		goodsubsets.push_back(subset);
		int sz = positions.size();
		do {
			int ss = 0;
			for (int j = 0; j + 1 < sz; ++j) {
				ss += knows[positions[j]][positions[j + 1]] * (1 << j);
			}
			
			spos[subset][positions[sz - 1]][ss] += 1;
		}while(next_permutation(positions.begin(), positions.end()));
	}
	
	for (auto subset: goodsubsets) {
		int second = (SIZE - 1) ^ subset;
		//to jest wybrane jako pierwsze, a to jako drugie
		if ((int)zbior[subset].size() != HALF) continue;
		if ((int)zbior[second].size() != (n - HALF)) continue;
		
		//przechodzimy tutaj tylko w zbiory, ktore chcemy miec
		int pt1 = (1 << (HALF - 1)), pt2 = (1 << (n - HALF - 1));
		for (int mask = 0; mask < pt1; ++mask)
			for (auto last_element : zbior[subset]) {
				if (!spos[subset][last_element][mask]) continue;
				for (int secmask = 0; secmask < pt2; ++secmask) {
				//maski mamy wybrane, teraz pierwsze elementy
					for (auto second_last : zbior[second]) {
						//debug(mask, knows[last_element][second_last], secmask);
						//debug(last_element, second_last);
						
						int subset_score = mask + (1 << (HALF - 1)) * knows[last_element][second_last] + odwroc[n - 1 - HALF][secmask] * (1 << HALF);
						//debug(subset_score, odwroc[n - HALF][secmask]);
						//assert(subset_score < (SIZE / 2));
						wynik[subset_score] += spos[subset][last_element][mask] * spos[second][second_last][secmask];
					}
				}
			}
	}
	
	SIZE >>= 1;
	FOR(i, 0, (SIZE - 1)) cout << wynik[i] << ' ';
}