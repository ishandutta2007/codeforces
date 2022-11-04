#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

#define fi first
#define se second
#define endl '\n'
#define MOD(n,k) ( (n % k) + k ) % k
#define isOn(S, j) (S & (1 << j) )
#define setBit(S, j) (S | (1 << j ) )
#define LSB(S) (S & (-S))

vvi col, fil;
vii enc;
vi vis(10005, -1);
int n, m, k, a, b, prim, ult = -1;
deque<int> dq;

void obtRes () {
	int t, x, y, i, j;

	while (dq.size()) {
		t = vis[dq.front()];
		tie (x, y) = enc[dq.front()];
		dq.pop_front();

		//Transiciones
		for (int u : fil[x]) {
			tie (i, j) = enc[u];
			if ( abs(x - i) + abs(y - j) == 1 && (vis[u] == -1 || vis[u] > t) ) {
				vis[u] = t;
				dq.push_front(u);
			} else if (vis[u] == -1 || vis[u] > t + 1) {
				vis[u] = t + 1;
				dq.push_back(u);
			}
		}

		for (int u : col[y]) {
			tie (i, j) = enc[u];
			if ( abs(x - i) + abs(y - j) == 1 && (vis[u] == -1 || vis[u] > t) ) {
				vis[u] = t;
				dq.push_front(u);
			} else if (vis[u] == -1 || vis[u] > t + 1){
				vis[u] = t + 1;
				dq.push_back(u);
			}
		}

	}
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n >> m >> k;
	fil = vvi(n+5), col = vvi(m+5);

	for (int i = 0; i < k; i++) {
		cin >> a >> b;
		enc.emplace_back(a, b);
		
		for (int j = max(1, a-2), lim = min(n, a+2); j <= lim; j++)
			fil[j].push_back(i);
		for (int j = max(1, b-2), lim = min(m, b+2); j <= lim; j++)
			col[j].push_back(i);
		
		if (a == 1 && b == 1)
			prim = i;
		if (a == n && b == m)
			ult = i;
	}

	if (ult == -1) {
		ult = k;
		enc.emplace_back(n + 1, m + 1);
		
		for (int i = n - 1; i <= n; i++)
			fil[i].push_back(k);
		for (int i = m - 1; i <= m; i++)
			col[i].push_back(k);
	}

	dq.push_front(prim);
	vis[prim] = 0;
	obtRes();

	cout << vis[ult] << endl;

	return 0;
}