#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> ii;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

#define x first
#define y second
#define pb push_back
#define eb emplace_back
#define rep(i,a,b) for(auto i=(a); i<(b); ++i)
#define REP(i,n) rep(i,0,n)
#define all(v) (v).begin(), (v).end()
#define rs resize
#define DBG(x) cerr << __LINE__ << ": " << #x << " = " << (x) << endl

const ld PI = acos(-1.0);
template<class T> using min_queue =
		priority_queue<T, vector<T>, greater<T>>;
template<class T> int sz(const T &x) {
	return (int) x.size(); // copy the ampersand(&)!
}

template<class T> ostream& operator<<(ostream &os, vector<T> v) {
	os << "\n[";
	for(T &x : v) os << x << ',';
	return os << "]\n";
}

struct pairhash {
public:
	template<typename T1, typename T2>
	size_t operator()(const pair<T1, T2> &p) const {
		size_t lhs = hash<T1>()(p.x);
		size_t rhs = hash<T2>()(p.y);
		return lhs ^ (rhs+0x9e3779b9+(lhs<<6)+(lhs>>2));
	}
};

void run() {
	int n, l, k;
	string s;
	cin >> n >> l >> k >> s;
	k--;
	sort(all(s));
	vector<vector<char> > ans(n,vector<char>(l,' '));
	int b = 0, t = 0;
	rep(i,0,l){
		rep(j,b,k+1){
			ans[j][i] = s[t++];
		}
		rep(j,b,k+1)
			if(ans[j][i] != ans[k][i])
				b++;
	}
	rep(i,0,n){
		rep(j,0,l)
			if(ans[i][j] == ' ')
				ans[i][j] = s[t++];
	}
	rep(i,0,n){
		rep(j,0,l)
			cout << ans[i][j];
		cout << endl;
	}

}

signed main() {
	// DON'T MIX "scanf" and "cin"!
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout << fixed << setprecision(20);
	run();
	return 0;
}