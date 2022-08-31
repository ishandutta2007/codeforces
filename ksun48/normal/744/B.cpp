#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main(){
	int n;
	cin >> n;
	int a[2][10][n];
	for(int c = 0; c < 2; c++){
		for(int v = 0; v < 10; v++){
			vector<int> d;
			for(int i = 0; i < n; i++){
				if(((i >> v) & 1) == c){
					d.push_back(i+1);
				}
			}
			if(d.size()){
				cout << d.size() << endl;
				for(int i = 0; i < d.size(); i++){
					cout << d[i] << " ";
				}
				cout << endl;
				fflush(stdout);
				for(int i = 0; i < n; i++){
					cin >> a[c][v][i];
				}
			} else {
				for(int i = 0; i < n; i++){
					a[c][v][i] = 2e9;
				}
			}
		}
	}
	cout << -1 << endl;
	for(int i = 0; i < n; i++){
		int ans = 2e9;
		for(int j = 0; j < 10; j++){
			ans = min(ans,a[((i >> j) & 1)^1][j][i]);
		}
		cout << ans << endl;
	}
}