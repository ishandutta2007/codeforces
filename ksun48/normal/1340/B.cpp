#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	vector<string> digits = {
		"1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011"
	};
	int n, k;
	cin >> n >> k;
	vector<string> s(n);
	for(string& x : s) cin >> x;
	vector<vector<bool> > works(n+1, vector<bool>(7 * n+1, false));
	works[n][0] = true;
	vector<vector<int> > need(n, vector<int>(10));
	for(int i = n-1; i >= 0; i--){
		for(int dig = 0; dig <= 9; dig++){
			string a = s[i];
			string b = digits[dig];
			int diff = 0;
			for(int f = 0; f < 7; f++){
				if(a[f] != b[f]){
					diff++;
					if(a[f] > b[f]) diff = 1e8;
				}
			}
			need[i][dig] = diff;
			for(int r = 0; r + diff <= 7*n; r++){
				if(works[i+1][r]) works[i][r+diff] = true;
			}
		}
	}
	if(k > 7 * n || !works[0][k]){
		cout << -1 << '\n';
		return 0;
	}
	int cur = 0;
	while(cur < n){
		for(int dig = 9; dig >= 0; dig--){
			if(k >= need[cur][dig] && works[cur+1][k - need[cur][dig]]){
				cout << dig;
				k -= need[cur][dig];
				cur++;
				break;
			}
		}
	}
	cout << '\n';
}