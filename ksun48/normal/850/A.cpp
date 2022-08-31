#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main(){
	int n;
	cin >> n;
	int p[n][5];
	for(int i = 0; i < n; i++){
		for(int j = 0; j < 5; j++){
			cin >> p[i][j];
		}
	}
	if(n > 17){
		cout << 0 << endl << endl;
		return 0;
	}
	int good[n];
	for(int i = 0; i < n; i++){
		good[i] = 1;
		for(int j = 0; j < n; j++){
			for(int k = 0; k < n; k++){
				if(i == j || i == k || j == k) continue;
				int sum = 0;
				for(int z = 0; z < 5; z++){
					sum += (p[j][z] - p[i][z])*(p[k][z] - p[i][z]);
				}
				if(sum > 0){
					good[i] = 0;
				}
			}
		}
	}
	int ans = 0;
	for(int i = 0; i < n; i++){
		ans += good[i];
	}
	cout << ans << endl;
	for(int i = 0; i < n; i++){
		if(good[i]) cout << i + 1 << endl;
	}
}