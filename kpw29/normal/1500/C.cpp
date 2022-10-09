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

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long LL;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int maxn = 1505;
const int R = 2048;

vector <int> v[maxn];

vector <int> nums;
vector <int> init[maxn];
vector <int> goal[maxn];

int bad_blocks[maxn];
int first_smaller[maxn][maxn];
int tree[maxn][2 * R + 5];

PII stos[maxn];
int DL = 0;
int n, m;
bool rem[maxn];

void build(int col) {
	for (int i=0; i<n; ++i) {
		tree[col][i + R] = first_smaller[i][col];
	}
	for (int i=R-1; i>0; --i) {
		tree[col][i] = min(tree[col][2*i], tree[col][2*i+1]);
	}
}

inline int query(int col, int i, int j) {
	i += R; j += R;
	int result = min(tree[col][i], tree[col][j]);
	if (i == j) return result;
	while (i + 1 < j) {
		if (!(i & 1)) result = min(result, tree[col][i + 1]);
		if (j & 1) result = min(result, tree[col][j - 1]);
		i >>= 1; j >>= 1;
	}
	return result;
}

vector <int> res;

set <int> blocks;
int COLUMN;
int curr_pos[maxn];

bool cmp(const int &a, const int &b) {
	if (init[a][COLUMN] == init[b][COLUMN]) return (curr_pos[a] < curr_pos[b]);
	return init[a][COLUMN] < init[b][COLUMN];
}

void solveone() {
	cin >> n >> m;
	for (int i=0; i<n; ++i) nums.pb(i);
	
	for (int i=0; i<n; ++i) {
		init[i].resize(m);
		for (int j=0; j<m; ++j) {
			cin >> init[i][j];
		}
	}
	
	for (int i=0; i<n; ++i) {
		goal[i].resize(m);
		for (int j=0; j<m; ++j) {
			cin >> goal[i][j];
		}
	}
	
	for (int j=0; j<m; ++j) {
		DL = 0;
		stos[DL] = {0, n};
		for (int i=n-1; i>=0; --i) {
			while (stos[DL].e1 >= goal[i][j]) DL--;
			first_smaller[i][j] = stos[DL].e2;
			stos[++DL] = mp(goal[i][j], i);
		}
	}
	
	for (int j=0; j<m; ++j) build(j);
	queue <int> good_perms;
	blocks.insert(0);
	blocks.insert(n);
	
	for (int j=0; j<m; ++j) {
		int que = query(j, 0, n-1);
		if (que == n) {
			bad_blocks[j] = 0;
			rem[j] = 1;
			good_perms.push(j);
		}
		else {
			bad_blocks[j] = 1;
		}
	}
	
	while (!good_perms.empty()) {
		int col = good_perms.front();
		good_perms.pop();
		res.push_back(col);
		for (int i = 0; i < n - 1; ++i) {
			///assert(goal[i][col] <= goal[i+1][col]);
			if (goal[i][col] != goal[i+1][col]) {
				int co = i + 1;
				// wstawiamy ten element
				set <int> :: iterator it = blocks.lower_bound(co);
				if (*it != co) { // nie bylo go wczesniej, czas wstawic teraz
					set <int> :: iterator bg = it;
					--bg;
					int X = *bg, Y = (*it) - 1;
					for (int cl = 0; cl < m; ++cl) {
						if (rem[cl]) continue;
						bool co_bylo = query(cl, X, Y) <= Y;
						bad_blocks[cl] -= co_bylo;
						
						bool co_jest = query(cl, X, i) <= i;
						bad_blocks[cl] += co_jest;
						
						bool co_dwa = query(cl, i+1, Y) <= Y;
						bad_blocks[cl] += co_dwa;
						
						if (bad_blocks[cl] == 0 && !rem[cl]) {
							good_perms.push(cl);
							rem[cl] = 1;
						}
					}
					
					blocks.insert(co);
				}
			}
		}
		
	}
	
	reverse(res.begin(), res.end());
	for (auto &u : res) {
		for (int i=0; i<n; ++i) curr_pos[nums[i]] = i;	
		COLUMN = u;
		sort(nums.begin(), nums.end(), cmp);
	}
	
	bool flag = 1;
	for (int i=0; i<n; ++i) {
		for (int j=0; j<m; ++j) {
			//cout << init[nums[i]][j] << ' ';
			if (init[nums[i]][j] != goal[i][j]) {
				flag = 0;
			}
		}

	}
	
	if (!flag) OUT(-1);
	cout << (int)res.size() << "\n";
	for (auto u : res) cout << (u + 1) << ' ';
}

int main() {
	boost;
	int tests;
	tests = 1;
	//cin >> tests;
	FOR(_, 1, tests) solveone();
}