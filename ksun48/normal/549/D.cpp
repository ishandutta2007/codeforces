#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

int main(){
	int n, m;
	cin >> n >> m;
	string stuff;
	int num[n][m];
	for(int i = 0; i < n; i++){
		cin >> stuff;
		for(int j = 0; j < m; j++){
			if(stuff[j] == 'B'){
				num[i][j] = 1;
			} else {
				num[i][j] = -1;
			}
		}
	}
	int ans = 0;
	for(int i = n-1; i >= 0; i--){
		for(int j = m-1; j >= 0; j--){
			if(num[i][j] != 0) ans++;
			for(int a = 0; a <= i; a++){
				for(int b = 0; b <= j; b++){
					num[a][b] -= num[i][j];
				}
			}

		}
	}
	cout << ans << endl;

}