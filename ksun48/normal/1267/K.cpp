#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll calc(vector<ll> a){
	sort(a.begin(), a.end());
	int n = (int)a.size();
	int c = 0;
	ll tot = 1;

	int choice = 0;
	for(int v = 1; v <= n; v++){
		while(c < n && a[c] <= v){
			c++;
			choice++;
		}
		tot *= choice;
		choice--;
	}
	int cur = 0;
	for(int i = 0; i < n; i++){
		if(i > 0 && a[i] != a[i-1]) cur = 0;
		cur++;
		tot /= cur;
	}
	return tot;
}

void solve(){
	ll n;
	cin >> n;
	vector<ll> stuff;
	int cur = 2;
	while(n){
		stuff.push_back(n % cur);
		n /= cur;
		cur++;
	}
	ll g = calc(stuff);
	for(int i = 0; i < (int)stuff.size(); i++){
		if(stuff[i] == 0){
			stuff.erase(stuff.begin() + i);
			g -= calc(stuff);
			break;
		}
	}
	cout << g - 1 << '\n';
}

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int T;
	cin >> T;
	while(T--) solve();
}