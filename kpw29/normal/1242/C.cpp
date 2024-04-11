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

unordered_map <int, int> numbers;
vector <int> vals[20];
ll sum_box[20];
ll in_each;

vector <int> good_set[(1 << 15) + 5]; //which values to put and where
bool dp[(1 << 15) + 5];

inline ll get_replacement(ll value, int box) {
	//sum_box[box] - value + replacement = in_each
	return in_each + value - sum_box[box];
}

int ans_number[20], where_put[20], k;

void apply(int mask) {
	int sz = good_set[mask].size();
	assert(sz > 0);
	for (int j=0; j<sz; ++j) {
		int this_box = numbers[good_set[mask][j]];
		int prev_box;
		if (j) prev_box = numbers[good_set[mask][j - 1]];
		else prev_box = numbers[good_set[mask].back()];
		
		ans_number[this_box] = good_set[mask][j];
		where_put[this_box] = prev_box;
	}
}

int main() {
	numbers.max_load_factor(0.25);
	numbers.reserve(1<<18);
	boost;
	cin >> k;
	ll sum = 0;
	for (int i=1; i<=k; ++i) {
		int val;
		cin >> val;
		vals[i].resize(val);
		FOR(j, 0, val-1) {
			cin >> vals[i][j];
			numbers[vals[i][j]] = i;
			sum += vals[i][j];
			sum_box[i] += vals[i][j];
		}
	}
	
	in_each = sum / k;
	if (in_each * k != sum) OUT("No");
	
	for (int i=1; i<=k; ++i) {
		int sz = vals[i].size();
		for (int j=0; j<sz; ++j) {
			int mask = (1 << (i - 1));
			vector <int> elems = {vals[i][j]};
			bool ok = true;
			int curr_box = i; ll curr_value = vals[i][j];
			for (int step = 1; step <= 20; ++step) {
				ll new_value = get_replacement(curr_value, curr_box);
				if (abs(new_value) > (ll)1e9) {ok = false; break; }
				ll new_box = numbers[new_value];
				if (new_box == 0) {ok = false; break; }
				else {
					if (mask & (1 << (new_box - 1))) { //this appeared before
						if (new_value == elems[0]) {ok = true; break;}
						else {ok = false; break; }
					}
					else {
						mask |= (1 << (new_box - 1));
						elems.push_back(new_value);
						curr_value = new_value;
						curr_box = new_box;
					}
				}
			}
			
			if (ok) {
				if (good_set[mask].empty()) {
					good_set[mask] = elems;
					dp[mask] = 1;
				}
			}
		}
	}
	
	int pot = (1 << k);
	dp[0] = 0;
	for (int i=1; i<pot; ++i) {
		for (int x = i; x; ) { 
			--x &= i;
			if (!good_set[x ^ i].empty()) dp[i] |= dp[x];
		}
	}
	
	if (!dp[pot - 1]) OUT("No");
	cout << "Yes\n";
	// we need to reconstruct the answer now
	
	int mask = pot - 1;
	while (mask > 0) {
		if (!good_set[mask].empty()) {
			apply(mask);
			break;
		}
		
		bool flag = true;
		for (int x = mask; x; ) { 
			--x &= mask;
			
			if (!good_set[x].empty() && dp[mask ^ x]) {
				apply(x);
				mask = (mask ^ x);
				flag = false;
				break;
			}
		}
		
		assert(!flag);
	}
	
	FOR(i, 1, k) cout << ans_number[i] << ' ' << where_put[i] << "\n";
}