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
#define int ll 
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

const int maxm = 1e5;

int N, M, A, D, T[maxm];

int tc = 0, ans = 0;

void update(int t)
{
	// cerr << "The door closes at " << tc << endl;
	// cerr << "Determining for t = " << t << endl;

	// ceil((tc+1)/a)
	int cj = max(1LL, (int) ((tc + A) / A));
	int ck = min((int) (t / A), N);

	int len = ck - cj + 1;
	if (len <= 0) return; // empty

	int x = 1 + (int) (D / A);


	ans += (int) (len + x - 1) / x;

	int cl = ck - ((ck - cj) % x);
	tc = A * (cl) + D;

	// cerr << "Going from a*" << cj << " to a*" << ck << endl;
	// cerr << "Now the door closes at " << tc << endl;
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cerr << boolalpha;
	(cout << fixed).precision(20);

	cin >> N >> M >> A >> D;
	for (int i = 0; i < M; i++) cin >> T[i];

	for (int i = 0; i < M; i++) {
		update(T[i]);
		if (T[i] <= tc) {
			// we can go under
		} else {
			// cerr << "Client will open the door at " << T[i] << endl;
			// open the door!
			ans++;
			tc = T[i] + D;
		}
	}
	update(N * A);
	cout << ans << endl;
	return 0;
}