#include <bits/stdc++.h>
using namespace std;

using ll = long long;
int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	ll h;
	cin >> h;
	vector<ll> a(n);
	for(int i = 0; i < n; i++) cin >> a[i];
	int s = 0; // can
	int e = n + 1;
	while(s + 1 < e){
		int m = (s + e) / 2;
		vector<ll> b;
		for(int i = 0; i < m; i++) b.push_back(a[i]);
		sort(b.begin(), b.end());
		reverse(b.begin(), b.end());
		ll tot = 0;
		for(int i = 0; i < b.size(); i += 2){
			tot += b[i];
		}
		if(tot <= h){
			s = m;
		} else {
			e = m;
		}
	}
	cout << s << '\n';
}