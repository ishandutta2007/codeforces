#include <bits/stdc++.h>
using namespace std;

using ll = long long;
void solve(){
	int n;
	ll k;
	cin >> n >> k;
	k--;
	if(k >= (1ll << min((n-1), 62))){
		cout << -1 << '\n';
		return;
	}
	vector<int> perm(n);
	for(int i = 0; i < n; i++) perm[i] = i;
	int r = 0;
	while(r < min(n-1, 62)){
		if(k & (1ll << r)){
			int st = r;
			while(true){
				r++;
				if(k & (1ll << r)){
					continue;
				} else {
					break;
				}
			}
			reverse(perm.begin() + (n-1-r), perm.begin() + (n-st));
		} else {
			r++;
			continue;
		}
	}
	for(int a : perm){
		cout << (a+1) << ' ';
	}
	cout << '\n';
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}