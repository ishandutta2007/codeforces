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

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cerr << boolalpha;
	(cout << fixed).precision(20);

	int N;
	cin >> N;
	set<string> res;
	rep(_x,0,N) {
		string S, T;
		cin >> S;
		for (int i = 0; i < S.size(); ) {
			if (S[i] == 'u') {
				T += "oo";
				i++;
			} else if (S[i] == 'k') {
				int j = i;
				while (j < S.size() && S[j] == 'k') j++;
				if (j == S.size() || S[j] != 'h') {
					// not kkkkh
					while (i < j) T += S[i++];
				} else {
					i = j;
				}
			} else {
				T += S[i++];
			}
		}
		// cout << S << " -> " << T << endl;
		res.insert(T);
	}
	cout << res.size() << endl;
	return 0;
}