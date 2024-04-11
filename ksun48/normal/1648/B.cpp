#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n, c;
	cin >> n >> c;
	c++;
	vector<int> a(c, 0);
	for(int i = 0; i < n; i++){
		int x;
		cin >> x;
		a[x] = 1;
	}
	vector<int> apsum(c+1, 0);
	for(int i = 1; i <= c; i++){
		apsum[i] = apsum[i-1] + a[i-1];
	}
	for(int i = 1; i < c; i++){
		if(!a[i]) continue;
		for(int j = 1; j * i < c; j++){
			if(a[j]) continue;
			int x = i * j;
			int y = min(i * (j+1), c);
			int d = apsum[y] - apsum[x];
			if(d){
				cout << "No" << '\n';
				return;
			}
		}
	}
	cout << "Yes" << '\n';
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}