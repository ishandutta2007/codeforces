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

vi per_feat[8], per_test[8][8];

bool run() {
	int n;
	cin >> n;
	vi feat(n), test(n);
	REP(i, n) {
		int x,y,z;
		cin >> x >> y >> z;
		feat[i] = 4*x + 2*y + z;
	}
	REP(i, n) {
		int x,y,z;
		cin >> x >> y >> z;
		test[i] = 4*x + 2*y + z;
		test[i] &= feat[i];
	}

	REP(i, n) {
		per_feat[feat[i]].pb(i);
		per_test[feat[i]][test[i]].pb(i);
	}

	vector<bool> vis(8, false);
	vii arcs;
	vi server(8,-1);

	vi comps;
	comps.pb(7);

	server[7] = 0;
	vis[0] = true;
	vis[7] = true;

	//rep(i,0,8)
	//	vis[i] |= per_feat[i].empty();
	vi ct(n,0);
	for(int node : per_feat[7])
		if(node != 0)
			arcs.eb(0, node);
	while (!comps.empty()) {
		int cur = comps.back(); comps.pop_back();


		REP(tst, 8) {
			if(vis[tst])
				continue;
			if (!per_test[cur][tst].empty()) {
				// stuur naar alle dingen met features.
				vis[tst] = true;
				comps.pb(tst);
				server[tst] = per_test[cur][tst].back();
				ct[server[tst]] = 1;
				for(int node : per_feat[tst])
					arcs.eb(server[tst],node);
			}
		}

	}
	vi h1 = {1,2,4}, h2 = {3,5,6};
	for(int com : h2){
		if(vis[com] || per_feat[com].empty())
			continue;
		int c1 = com & (-com);
		int c2 = com - c1;
		if(!vis[c1] or !vis[c2])
			return false;
		server[com] = per_feat[com].back();
		arcs.eb(server[c1],server[com]);
		arcs.eb(server[c2],server[com]);
		for(int node : per_feat[com])
			if(node != server[com])
				arcs.eb(server[com],node);
		vis[com] = true;
	}
	rep(i,0,8){
		if(!vis[i] and !per_feat[i].empty())
			return false;
	}
	cout << "Possible" << endl;
	rep(i,0,n)
		cout << (i == 0 ? "" : " " ) << ct[i];
	cout << endl;
	cout << arcs.size() << endl;
	for(ii e : arcs)
		cout << e.x+1 << " " << 1+e.y << endl;
	return true;
}

signed main() {
	// DON'T MIX "scanf" and "cin"!
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout << fixed << setprecision(20);
	if(!run())
		cout << "Impossible" << endl;
	return 0;
}