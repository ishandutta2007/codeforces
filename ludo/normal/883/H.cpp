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
typedef vector<pii> vii;
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

int N, cnt[256] = {};
vi unmatched, matched;

bool cansplit(int ngroups)
{
	int len = N / ngroups;
	if (len % 2 == 0) {
		return unmatched.empty();
	} else {
		// odd matching
		return unmatched.size() <= ngroups;
	}
}

void findway(int ngroups)
{
	int len = N / ngroups;
	int npairs = len / 2; // floor
	cout << ngroups << endl;

	if (len % 2 == 0) {
		bool first = true;
		for (int i = 0; i < ngroups; i++) {
			if (first) first = false;
			else cout << " ";

			vi cur;
			for (int j = 0; j < npairs; j++) {
				cur.pb(matched.back());
				matched.pop_back();
				cout << ((char) (cur.back()));
			}
			while (!cur.empty()) {
				cout << ((char) (cur.back()));
				cur.pop_back();
			}
		}
		cout << endl;
	} else {
		// odd matching
		while (unmatched.size() < ngroups) {
			int b = matched.back();
			matched.pop_back();
			unmatched.pb(b);
			unmatched.pb(b);
		}
		
		bool first = true;
		for (int i = 0; i < ngroups; i++) {
			if (first) first = false;
			else cout << " ";

			vi cur;
			for (int j = 0; j < npairs; j++) {
				cur.pb(matched.back());
				matched.pop_back();
				cout << ((char) (cur.back()));
			}
			cout << ((char) (unmatched.back()));
			unmatched.pop_back();
			while (!cur.empty()) {
				cout << ((char) (cur.back()));
				cur.pop_back();
			}
		}
		cout << endl;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cerr << boolalpha;
	(cout << fixed).precision(20);

	cin >> N;
	for (int i = 0; i < N; i++) {
		char ch;
		cin >> ch;
		cnt[(int) ch]++;
	}

	for (int i = 0; i < 256; i++) {
		while(cnt[i] >= 2) { matched.pb(i); cnt[i] -= 2; }
		if (cnt[i] == 1) unmatched.pb(i);
	}

	vi divs;
	for (int i = 1; i * i <= N; i++) {
		if (N % i == 0) {
			divs.pb(i);
			if (i * i != N) divs.pb(N / i);
		}
	}
	sort(all(divs));
	for (int cur : divs) {
		if (cansplit(cur)) {
			findway(cur);
			return 0;
		}
	}
	assert(false);
	return 0;
}