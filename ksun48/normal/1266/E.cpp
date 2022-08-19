#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	ll f = 0;
	vector<ll> need(n);
	for(int i = 0; i < n; i++){
		ll a;
		cin >> a;
		need[i] = a;
		f += a;
	}
	int q;
	cin >> q;
	map<pair<int, int>, int> z;
	vector<ll> freq(n, 0);
	for(int i = 0; i < q; i++){
		int s, t, u;
		cin >> s >> t >> u;
		s--;
		u--;
		if(z.count({s, t})){
			ll ou = z[{s, t}];
			f += min(freq[ou], need[ou]);
			freq[ou]--;
			f -= min(freq[ou], need[ou]);
			z.erase({s, t});
		}
		if(u != -1){
			z[{s, t}] = u;
			f += min(freq[u], need[u]);
			freq[u]++;
			f -= min(freq[u], need[u]);
		}
		cout << max(1ll, f) << '\n';
	}
}