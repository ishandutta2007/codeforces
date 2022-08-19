#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n, m;
	cin >> n >> m;
	vector<int> a(m);
	for(int& x : a){
		cin >> x;
		x = -x;
	}
	vector<int> ord(m);
	for(int i = 0; i < m; i++){
		ord[i] = i;
	}
	sort(ord.begin(), ord.end(), [&](int x, int y){
		return tie(a[x], x) < tie(a[y], y);
	});
	int inv = 0;
	for(int i = 0; i < m; i++){
		for(int j = i+1; j < m; j++){
			if(ord[i] > ord[j]) inv++;
		}
	}
	cout << inv << '\n';
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}