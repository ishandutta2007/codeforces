#include <bits/stdc++.h>

#define endl '\n'
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

const int MX = 100005, SQ = 316;
int n, q, blo[MX];
ll lz[MX], act[MX], a[MX], to[MX];

void update (int i, int u, int v, int x) {
	a[i] -= lz[blo[i]] - act[i];
	act[i] = lz[blo[i]];
	
	if (u <= i && i <= v)
		a[i] -= x;
	
	if (a[i] < 1)
		a[i] = 1;
	
	if (blo[a[i]] == blo[i])
		to[i] = to[a[i]];
	else
		to[i] = a[i];
}

void update (int i) {
	a[i] -= lz[blo[i]] - act[i];
	act[i] = lz[blo[i]];
	
	if (a[i] < 1)
		a[i] = 1;
	
	if (blo[a[i]] == blo[i])
		to[i] = to[a[i]];
	else
		to[i] = a[i];
}

void refresh (int b) {
	for (int i = b * SQ; i <= n && blo[i] == b; i++)
		update(i);
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> q;
	
	a[1] = to[1] = 1;
	for (int i = 2; i <= n; i++) {
		cin >> a[i];
		blo[i] = i / SQ;
	}
	
	for (int i = 1; i <= n; i++)
		update(i);
		
	while (q--) {
		int t, u, v;
		cin >> t >> u >> v;
		
		if (t == 1) {
			int x;
			cin >> x;
			
			for (int i = SQ * blo[u]; i <= n && blo[i] == blo[u]; i++)
				update(i, u, v, x);
			
			for (int j = blo[u] + 1; j < blo[v]; j++)
				lz[j] += x;
			
			if (blo[u] != blo[v])
				for (int i = SQ * blo[v]; i <= n && blo[i] == blo[v]; i++)
					update(i, u, v, x);
		} else {
			while (u != v) {
				if (act[u] < lz[blo[u]]) refresh(blo[u]);
				if (act[v] < lz[blo[v]]) refresh(blo[v]);
				
				if (to[u] == to[v]) break;
				
				if (u == 1 || v == 1) {
					u = v = 1;
					break;
				}
				
				if (to[u] < to[v]) swap(u, v);
				u = to[u];
			}
			
			while (u != v) {
				if (act[u] < lz[blo[u]]) refresh(blo[u]);
				if (act[v] < lz[blo[v]]) refresh(blo[v]);
				
				if (u == 1 || v == 1) {
					u = v = 1;
					break;
				}
				
				if (a[u] < a[v]) swap(u, v);
				u = a[u];
			}
			
			cout << u << endl;
		}
	}
	
	return 0;
}