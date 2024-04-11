#include<bits/stdc++.h>

using namespace std;

#define x first
#define y second
#define pb push_back
#define eb emplace_back

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

const int maxn = 1e5;

int N, a[maxn];
map<int, int> vals;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cerr << boolalpha;
	(cout << fixed).precision(10);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> a[i];
		vals[a[i]] = i;
	}
	int idx = 0;
	for (auto it : vals) { a[it.y] = idx++; }
/*
	cerr << "PERM: ";
	for (int i = 0; i < N; i++) cerr << a[i] << " ";
	cerr << endl;
*/

	vector<bool> vis(N, false);
	vector< vi > cycles;
	for (int i = 0; i < N; i++) {
		if (vis[i]) continue;

		vi cycle;
		int j = i;
		do {
			cycle.pb(j);
			vis[j] = true;
			j = a[j];
		} while (j != i);
		cycles.pb(cycle);
	}
	cout << cycles.size() << endl;
	for (vi c : cycles) {
		cout << c.size();
		for (int i : c) {
			cout << " " << (i + 1);
		}
		cout << endl;
	}

	return 0;
}