#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve(){
	int n, k;
	cin >> n >> k;
	vector<int> used(100);
	vector<ll> stuff(n);
	for(int i = 0; i < n; i++){
		cin >> stuff[i];
	}
	for(int i = 0; i < n; i++){
		ll a = stuff[i];
		int c = 0;
		while(a){
			if(a % k == 0){
				a /= k;
				c++;
			} else {
				a--;
				if(used[c]){
					cout << "NO" << '\n';
					return;
				}
				used[c] = true;
			}
		}
	}
	cout << "YES" << '\n';
}

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int T;
	cin >> T;
	while(T--) solve();
}