#include <bits/stdc++.h>
using namespace std;

using ll = long long;
int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	vector<ll> tune(n);
	for(int i = 0; i < n; i++) cin >> tune[i];
	sort(tune.begin(), tune.end());
	vector<ll> diffs;
	for(int i = 0; i + 1 < n; i++) diffs.push_back(tune[i+1] - tune[i]);
	sort(diffs.begin(), diffs.end());

	int x = (int)diffs.size();
	vector<ll> psums(x + 1);
	psums[0] = 0;
	for(int i = 0; i < x; i++){
		psums[i+1] = psums[i] + diffs[i];
	}
	int q;
	cin >> q;
	for(int i = 0; i < q; i++){
		ll l, r;
		cin >> l >> r;

		ll v = r - l + 1;
		int s = -1;
		int e = x;
		while(s + 1 < e){
			int m = (s + e) / 2;
			if(v < diffs[m]){
				e = m;
			} else {
				s = m;
			}
		}
		ll ans = v + psums[e] + (x - e) * v;
		cout << ans << " \n"[i == q-1];
	}
}