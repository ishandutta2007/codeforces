#include <bits/stdc++.h>
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb push_back
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ll> vl;
typedef vector<ii> vii;

const int MX = 100005;
int n, p;
ll act, fin, res[MX];
queue<int> q;
set<int> sq, dis;
multiset<ii> mst;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n >> p;
	for (int i = 0; i < n; i++) {
		int t;
		cin >> t;
		mst.emplace(t, i);
	}

	while (mst.size() || q.size()) {
		while (mst.size() && mst.begin()->fi == act) {
			dis.insert(mst.begin()->se);
			mst.erase(mst.begin());
		}

		if (q.size() && fin == act) {
			sq.erase(q.front());
			res[q.front()] = act;
			q.pop();
		}

		if (dis.size() && (sq.empty() || *sq.begin() > *dis.begin())) {
			q.push(*dis.begin());
			sq.insert(*dis.begin());
			dis.erase(dis.begin());
		}

		if (q.size() && fin <= act)
			fin = act + p;

		if (q.size() && mst.size()) {
			act = min(fin, 1ll * mst.begin()->fi);
		} else if (q.size()) {
			act = fin;
		} else if (mst.size()) {
			act = mst.begin()->fi;
		}
	}

	for (int i = 0; i < n; i++)
		cout << res[i] << " ";
	cout << endl;

	return 0;
}