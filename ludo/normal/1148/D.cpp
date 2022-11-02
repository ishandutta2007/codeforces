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
int n, A[maxn], B[maxn];

struct S {
	int idx, fr, to;

};
	bool operator<(S a, S b) { return a.fr > b.fr; }

void run() {
	cin >> n;
	REP(i, n) cin >> A[i] >> B[i];

	vii incs, decs;

	REP(i, n) {
		if (A[i] < B[i]) incs.eb(-A[i], i+1);
		else decs.eb(B[i], i+1);
	}
	sort(all(incs));
	sort(all(decs));

	if (incs.size() > decs.size()) {
		printf("%d\n", incs.size());
		for (auto pr : incs) printf("%d ", pr.y);
	} else {
		printf("%d\n", decs.size());
		for (auto pr : decs) printf("%d ", pr.y);
	}
	printf("\n");

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cerr << boolalpha;
	(cout << fixed).precision(20);

	run();
	return 0;
}