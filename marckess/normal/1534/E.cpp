#include <bits/stdc++.h>

//#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < int(n); i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 505;
int n, k, dis[MX], p[MX], ex[MX], res;

int main() {
	//ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	cin >> n >> k;
	
	queue<int> q;
	q.push(0);
	
	memset(dis, -1, sizeof(dis));
	dis[0] = 0;
	
	while (q.size()) {
		int a = q.front();
		int b = n - a;
		q.pop();
		
		for (int i = 0; i <= k; i++)
			if (i <= a && k - i <= b) {
				int v = (a - i) + (k - i);
				
				if (dis[v] == -1) {
					p[v] = a;
					dis[v] = dis[a] + 1;
					q.push(v);
				}
			}
	}
	
	if (dis[n] == -1) {
		cout << -1 << endl;
		return 0;
	}
	
	vi path;
	int u = n;
	while (u) {
		path.pb(u);
		u = p[u];
	}
	path.pb(0);
	
	reverse(all(path));
	forn (i, (int)path.size() - 1) {
		int a = path[i];
		int b = n - a;
		int nex = path[i + 1];
		
		for (int i = 0; i <= k; i++)
			if (i <= a && k - i <= b) {
				int v = (a - i) + (k - i);
				
				if (v == nex) {
					vi x, y;
					
					for (int j = 1; j <= n; j++) {
						if (ex[j]) {
							if (y.size() < i) {
								y.pb(j);
								ex[j] = 0;
							}
						} else {
							if (x.size() < (k - i)) {
								x.pb(j);
								ex[j] = 1;
							}
						}
					}
					
					cout << "?";
					for (int k : x) cout << " " << k;
					for (int k : y) cout << " " << k;
					cout << endl;
					
					int r;
					cin >> r;
					if (r == -1) exit(0);
					res ^= r;
					
					break;
				}
			}
	}
	
	cout << "! " << res << endl;
	
	return 0;
}