#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;
const ll M = ll(1e18);

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int n;
	cin >> n;
	vector<vector<ll> > a(n, vector<ll>(n, M));
	ll mv = M;
	for(int i = 0; i < n; i++){
		for(int j = i+1; j < n; j++){
			ll x;
			cin >> x;
			a[i][j] = a[j][i] = x;
			mv = min(mv, x);
		}
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			a[i][j] -= mv;
		}
	}
	vector<ll> z(n, M);
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(i == j) continue;
			z[i] = min(z[i], 2 * a[i][j]);
		}
	}
	vector<int> vis(n, 0);
	for(int it = 0; it < n; it++){
		int best = -1;
		for(int i = 0; i < n; i++){
			if(vis[i]) continue;
			if(best == -1 || z[i] < z[best]) best = i;
		}
		int v = best;
		vis[v] = 1;
		for(int w = 0; w < n; w++){
			if(v == w) continue;
			z[w] = min(z[w], z[v] + a[v][w]);
		}
	}
	for(int i = 0; i < n; i++){
		cout << (z[i] + (n-1) * mv) << '\n';
	}
}