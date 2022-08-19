#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	vector<vector<int> > ans(n, vector<int>(n, 0));
	int x = 0;
	for(int i = 0; i < n; i += 2){
		for(int j = 0; j < n; j += 2){
			ans[i][j] = x;
			ans[i][j+1] = x + 1;
			ans[i+1][j] = x + 2;
			ans[i+1][j+1] = x + 3;
			x += 4;
		}
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cout << ans[i][j] << ' ';
		}
		cout << '\n';
	}
}