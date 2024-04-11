#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n;
	cin >> n;
	vector<string> a(3);
	for(int i = 0; i < 3; i++){
		cin >> a[i];
	}
	vector<int> loc(3, 0);
	string c;
	while(loc[0] < 2*n && loc[1] < 2*n && loc[2] < 2*n){
		vector<char> z = {a[0][loc[0]], a[1][loc[1]], a[2][loc[2]]};
		sort(z.begin(), z.end());
		char v = z[1];
		for(int i = 0; i < 3; i++){
			if(a[i][loc[i]] == v){
				loc[i]++;
			}
		}
		c += v;
	}
	int worst = 0;
	for(int i = 0; i < 3; i++){
		if(loc[i] < loc[worst]) worst = i;
	}
	for(int i = 0; i < 3; i++){
		if(i == worst) continue;
		for(int z = loc[i]; z < 2*n; z++){
			c += a[i][z];
		}
	}
	assert((int)c.size() <= 3*n);
	c.resize(3*n, '0');
	cout << c << '\n';
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}