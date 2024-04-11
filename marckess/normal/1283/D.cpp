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

const int MX = 200005;
int n, m, x[MX], y[MX];
ll s;
map<int, int> dis;
set<int> res;
queue<int> q;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		cin >> x[i];
		q.push(x[i]);
		dis[x[i]] = 0;
	}

	while (res.size() < m) {
		int u = q.front();
		q.pop();

		if (!dis.count(u-1)) {
			q.push(u-1);
			dis[u-1] = dis[u] + 1;
			s += dis[u-1];
			res.insert(u-1);
		}

		if (res.size() < m && !dis.count(u+1)) {
			q.push(u+1);
			dis[u+1] = dis[u] + 1;
			s += dis[u+1];
			res.insert(u+1);
		}
	}

	cout << s << endl;
	for (int x : res)
		cout << x << " ";
	cout << endl;

	return 0;
}