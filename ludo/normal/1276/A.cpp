#include<bits/stdc++.h>
using namespace std;

// Order statistics tree (if supported by judge!):
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template<class TK, class TM> using order_tree =
	tree<TK, TM, less<TK>, rb_tree_tag, tree_order_statistics_node_update>;
// iterator	find_by_order(int r) (zero based)
// int		order_of_key(TK v)
template<class TV> using order_set = order_tree<TV, null_type>;

#define x first
#define y second
#define rs resize
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define rep(i,a,b) for(auto i=(a);i!=(b); ++i)
#define REP(i,n) rep(i,0,n)
#define all(v) (v).begin(), (v).end()

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
template<class T> using min_queue = priority_queue<T, vector<T>, greater<T>>;

template<class T1, class T2>
ostream& operator<<(ostream &out, const pair<T1,T2> &a) { return out << '(' << a.x << ", " << a.y << ')'; }
template<class T1, class T2>
istream& operator>>(istream &in, pair<T1,T2> &a) { return in >> a.x >> a.y; }

const int INF = 2147483647;
const ll LLINF = 9223372036854775807LL;

// lambda-expression: [] (args) -> retType { body }

vi run(const string &S) {
	vi ans;
	int n = S.size();

	for (int i = 0; i < n; ) {
		if (i + 4 < n &&
			S[i] == 't' && S[i+1] == 'w' && S[i+2] == 'o' && S[i+3] == 'n' && S[i+4] == 'e') {
			ans.pb(i+2);
			i += 5;
		} else if (i + 2 < n && 
			S[i] == 't' && S[i+1] == 'w' && S[i+2] == 'o') {
			ans.pb(i+1);
			i += 3;
		} else if (i + 2 < n && S[i] == 'o' && S[i+1] == 'n' && S[i+2] == 'e') {
			ans.pb(i+1);
			i += 3;
		} else i++;
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cerr << boolalpha;
	(cout << fixed).precision(10);

	int n;
	cin >> n;
	while (n--) {
		string S;
		cin >> S;
		vi ans = run(S);
		cout << ans.size() << endl;
		for (int x : ans) cout << (x+1) << " ";
		cout << endl;
	}

	return 0;
}