#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve(){
	int n;
	cin >> n;
	vector<ll> p(n);
	for(int i = 0; i < n; i++){
		cin >> p[i];
		p[i] /= 100;
	}
	sort(p.begin(), p.end());
	reverse(p.begin(), p.end());
	ll x, a, y, b;
	cin >> x >> a >> y >> b;
	if(y > x){
		swap(x, y);
		swap(a, b);
	}
	ll k;
	cin >> k;
	int s = 0; // no
	int e = n + 1; // yes
	while(s + 1 < e){
		int m = (s + e) / 2;

		int both, ta, tb, t;
		both = ta = tb = t = 0;

		for(int i = 1; i <= m; i++){
			if(i % a == 0 && i % b == 0) both++;
			else if(i % a == 0) ta++;
			else if(i % b == 0) tb++;
			else t++;
		}
		int cur = 0;
		ll tot = 0;
		for(int i = 0; i < both; i++){
			tot += p[cur] * (x + y);
			cur++;
		}
		for(int i = 0; i < ta; i++){
			tot += p[cur] * (x);
			cur++;
		}
		for(int i = 0; i < tb; i++){
			tot += p[cur] * (y);
			cur++;
		}
		if(tot >= k){
			e = m;
		} else {
			s = m;
		}
	}
	if(e == n + 1){
		e = -1;
	}
	cout << e << '\n';
}

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int Q;
	cin >> Q;
	for(int _ = 0; _ < Q; _++) solve();
}