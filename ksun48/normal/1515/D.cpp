#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n, l, r;
	cin >> n >> l >> r;
	vector<int> lf(n, 0), rf(n, 0);
	for(int i = 0; i < l; i++){
		int a;
		cin >> a;
		a--;
		lf[a]++;
	}
	for(int i = 0; i < r; i++){
		int a;
		cin >> a;
		a--;
		rf[a]++;
	}
	int cost = 0;
	int el = 0;
	int er = 0;
	for(int i = 0; i < n; i++){
		int x = min(lf[i], rf[i]);
		lf[i] -= x;
		rf[i] -= x;
		el += lf[i];
		er += rf[i];
	}
	for(int i = 0; i < n; i++){
		while(lf[i] >= 2 && el > er){
			el -= 2;
			cost++;
			lf[i] -= 2;
		}
		while(rf[i] >= 2 && er > el){
			er -= 2;
			cost++;
			rf[i] -= 2;
		}
	}
	assert((el + er) % 2 == 0);
	cost += (el + er) / 2 + abs(el - er) / 2;
	cout << cost << '\n';
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}