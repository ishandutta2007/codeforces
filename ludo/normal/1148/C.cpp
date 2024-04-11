#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

#define x first
#define y second
#define pb push_back
#define eb emplace_back
#define rep(i,a,b) for(auto i=(a);i!=(b); ++i)
#define REP(i,n) rep(i,0,n)
#define all(v) (v).begin(), (v).end()
#define rs resize
#define DBG(x) cerr << __LINE__ << ": " << #x << " = " << (x) << endl

const int INF = 2147483647; // (1 << 30) - 1 + (1 << 30)
const ll LLINF = (1LL << 62) - 1 + (1LL << 62); // = 9.223.372.036.854.775.807
const double PI = acos(-1.0);

template<class T>
using min_queue = priority_queue<T, vector<T>, greater<T>>;

const int maxn = 3e5;
int n, A[maxn], I[maxn];

vector<ii> moves;

// a, b are indices.
void move(int a, int b) {
	if (a == b) return;

	// cerr << "Move " << a << ", " << b << endl;

	moves.eb(a, b);
	swap(A[a], A[b]);
	I[A[a]] = a;
	I[A[b]] = b;

	// REP(i, n) cerr << A[i] << " "; cerr << endl;
}

void run() {
	cin >> n;
	REP(i, n) cin >> A[i];


	/* n = 1000;
	REP(i, n) A[i] = i+1;
	random_shuffle(A, A+n); */

	// REP(i, n) cerr << A[i] << " "; cerr << endl;


	REP(i, n) { A[i]--; I[A[i]] = i; }
	int h = n/2;

	// fase 1: aaaa|bbbb
	deque<int> as;
	rep(i, h, n) {
		if (A[i] < h) as.push_back(i);
	}

	rep(i, 0, h) {
		if (A[i] < h) continue; // goed.

		if (as.back() >= i + h) {
			// afstand groot genoeg.
			// cerr << "makkie " << i << " " << as.back() << endl;
			move(i, as.back());
			as.pop_back();
		} else {
			// drie-trap:
			// a?b? | ?a?b
			// B?b? | ?a?A
			// A?b? | ?B?a
			// a?A? | ?b?B
			int fst = as.front();
			// cerr << "lastig " << i << " " << fst << endl;
			move(0, n-1);
			move(0, fst);
			move(i, n-1);
			as.pop_front();
		}
	}

	// REP(i, n) cerr << A[i] << " "; cerr << endl;

	REP(i, n) {
		assert((i<h) == (A[i]<h));
	}

	REP(i, h) {
		if (A[i] != i) {
			// drie-trap
			int j = I[i];
			move(i, n-1);
			move(j, n-1);
			move(i, n-1);
		}
	}

	rep(i, h, n) {
		if (A[i] != i) {
			int j = I[i];
			move(i, 0);
			move(j, 0);
			move(i, 0);
		}
	}

	printf("%d\n", (int) moves.size());
	for (auto pr : moves) printf("%d %d\n", pr.x+1, pr.y+1);

	REP(i, n) assert(A[i] == i);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cerr << boolalpha;
	(cout << fixed).precision(20);

	run();
	return 0;
}