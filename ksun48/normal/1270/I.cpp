#include <bits/stdc++.h>
using namespace std;

using ll = unsigned long long;

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int k;
	cin >> k;
	int n = (1 << k);
	vector<vector<ll> > a(n, vector<ll> (n, 0));
	for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) cin >> a[i][j];
	int t;
	cin >> t;
	vector<pair<int,int> > shape(t);
	for(int i = 0; i < t; i++) cin >> shape[i].first >> shape[i].second;
	for(int r = 0; r < k; r++){
		vector<vector<ll> > b(n, vector<ll>(n, 0));
		for(int c = 0; c < t; c++){
			for(int i = 0; i < (1 << k); i++){
				for(int j = 0; j < (1 << k); j++){
					b[(i + shape[c].first) & ((1 << k) - 1)][(j + shape[c].second) & ((1 << k) - 1)] ^= a[i][j];
				}
			}
		}
		a = b;
		for(int c = 0; c < t; c++){
			shape[c].first = (shape[c].first * 2) % n;
			shape[c].second = (shape[c].second * 2) % n;
		}
	}
	int ans = 0;
	for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) if(a[i][j]) ans++;
	cout << ans << '\n';
}