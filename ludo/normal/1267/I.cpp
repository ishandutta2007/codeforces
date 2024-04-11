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

vvi mat; // 1 represents a <= b

bool comp(int a, int b){
	if(mat[a][b] != -1)
		return mat[a][b]; 
	cout << "? " << a+1 << " " << b+1 << endl;
	char c;
	cin >> c;
	mat[a][b] = (c == '<');
	mat[b][a] = 1-mat[a][b];
	return mat[a][b];
}

void run() {
	int n;
	cin >> n;
	int m = 2*n;
	mat = vvi(m,vi(m,-1));
	vi zw;
	rep(i,0,n){
		zw.pb(2*i + 1-comp(2*i,2*i+1));
	}
	sort(all(zw),comp);
	int tw = zw[n-1];
	
	int en = (tw/2)*4+1 - tw;
	vi rest;
	rep(i,0,n){
		if(tw/2 == i)
			continue;
		rest.pb(2*i);
		rest.pb(2*i+1);
	}
	sort(all(rest), comp);
	comp(tw,rest[n-1]);
	cout << "!" << endl;
}

signed main() {
	// DON'T MIX "scanf" and "cin"!
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout << fixed << setprecision(20);
	int t; cin >> t;
	rep(i,0,t)
		run();
	return 0;
}