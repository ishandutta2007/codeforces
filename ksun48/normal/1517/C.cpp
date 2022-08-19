#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int n;
	cin >> n;
	vector<int> p(n);
	for(int& x : p) cin >> x;
	vector<vector<int> > a(n, vector<int>(n, -1));
	for(int i = 0; i < n; i++){
		int ci = i;
		int cj = i;
		for(int r = 0; r < p[i]; r++){
			a[ci][cj] = p[i];
			if(cj > 0 && a[ci][cj-1] == -1){
				cj--;
			} else {
				ci++;
			}
		}
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j <= i; j++){
			cout << a[i][j] << ' ';
		}
		cout << '\n';
	}
}