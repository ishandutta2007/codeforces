#include<bits/stdc++.h>

using namespace std;

#define x first
#define y second
#define pb push_back
#define eb emplace_back
#define rep(i,a,b) for(auto i=(a);i!=(b); ++i)
#define all(v) (v).begin(), (v).end()
#define rs resize

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;

const int INF = 2147483647; // (1 << 30) - 1 + (1 << 30)
const ll LLINF = (1LL << 62) - 1 + (1LL << 62); // = 9.223.372.036.854.775.807
const double PI = acos(-1.0);

// lambda-expression: [] (args) -> retType { body }

#define DBG(x) cerr << __LINE__ << ": " << #x << " = " << (x) << endl

const bool LOG = false;
void Log() {
	if(LOG) cerr << "\n\n";
}
template<class T, class... S>
void Log(T t, S... s) {
	if(LOG) cerr << t << "\t", Log(s...);
}

template<class T>
using min_queue = priority_queue<T, vector<T>, greater<T>>;

const int MAXN = 1e9;
const int MAXP = sqrt(MAXN) + 1;

int query(int X)
{
	if (X <= 3 || X == 5 || X == 7) return -1;

	if (X == 9) return 1;
	if (X == 11) return -1;

	int ans = 0;
	if (X % 2 == 1) {
		X -= 9;
		ans++;
	}

	if (X % 4 == 2) {
		X -= 6;
		ans++;
	}

	assert(X % 4 == 0);
	return (ans + X / 4);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cerr << boolalpha;
	(cout << fixed).precision(20);

	int Q;
	cin >> Q;
	while (Q--) {
		int X;
		cin >> X;
		int a = query(X);
		cout << a << endl;
	}
	return 0;
}