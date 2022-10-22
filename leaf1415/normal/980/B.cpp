#include <iostream>

using namespace std;

int n, k;
int ans[4][105];

int main(void)
{
	cin >> n >> k;
	
	int r = 1;
	if(k >= n-2){
		r = 2;
		for(int i = 1; i <= n-2; i++) ans[1][i] = 1;
		k -= n-2;
	}
	for(int i = 1; i <= k/2; i++){
		ans[r][i] = ans[r][n-1-i] = 1;
	}
	if(k % 2) ans[r][n/2] = 1;
	
	cout << "YES" << endl;
	for(int i = 0; i < 4; i++){
		for(int j = 0; j < n; j++){
			if(ans[i][j]) cout << "#";
			else cout << ".";
		}
		cout << endl;
	}
	return 0;
}