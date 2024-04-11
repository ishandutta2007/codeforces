#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n, m;
	cin >> n >> m;
	vector<vector<int> > a(n, vector<int>(n));
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin >> a[i][j];
			a[i][j]--;
		}
	}
	vector<int> which = {0, 1, 2};
	vector<int> add = {0, 0, 0};
	string s;
	cin >> s;
	for(char c : s){
		if(c == 'R'){
			add[1] += 1;
			add[1] %= n;
		} else if(c == 'L'){
			add[1] += n-1;
			add[1] %= n;
		} else if(c == 'D'){
			add[0] += 1;
			add[0] %= n;
		} else if(c == 'U'){
			add[0] += n-1;
			add[0] %= n;			
		} else if(c == 'I'){
			swap(which[1], which[2]);
			swap(add[1], add[2]);
		} else {
			swap(which[0], which[2]);
			swap(add[0], add[2]);
		}
	}
	vector<vector<int> > res(n, vector<int>(n, -1));
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			int z = a[i][j];
			vector<int> st = {i, j, z};
			vector<int> en(3);
			for(int v = 0; v < 3; v++){
				en[v] = (st[which[v]] + add[v]) % n;
			}
			res[en[0]][en[1]] = en[2];
		}
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cout << res[i][j] + 1 << ' ';
		}
		cout << '\n';
	}
	cout << '\n';
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}