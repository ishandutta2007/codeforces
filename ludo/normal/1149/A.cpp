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

void run() {
	int n, n1 = 0, n2 = 0;
	cin >> n;
	int x;
	REP(i, n) { cin >> x; if (x == 1) n1++; }
	n2 = n - n1;

	if (n1 == 0) {
		REP(i, n) printf("2 ");
		printf("\n");
		return;
	} else if (n2 == 0) {
		REP(i, n) printf("1 ");
		printf("\n");
		return;
	}

	assert(n1 > 0 && n2 > 0);
	printf("2 1 ");
	n1--; n2--;
	while (n2 > 0) printf("2 "), n2--;
	while (n1 > 0) printf("1 "), n1--;
	printf("\n");

	// try to make 2.
	// if we have zero ones, only two's
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cerr << boolalpha;
	(cout << fixed).precision(20);

	run();
	return 0;
}