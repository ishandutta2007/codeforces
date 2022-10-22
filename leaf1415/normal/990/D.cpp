#include <iostream>

using namespace std;

int n, a, b;
int ans[1005][1005];

int main(void)
{
	cin >> n >> a >> b;
	if(a > 1 && b > 1){
		cout << "NO" << endl;
		return 0;
	}
	if(a == 1 && b == 1){
		if(n == 1){
			cout << "YES" << endl;
			cout << 0 << endl;
			return 0;
		}
		if(n <= 3){
			cout << "NO" << endl;
			return 0;
		}
	}
	
	bool flip = false;
	if(a < b){
		int t = a;
		a = b, b = t;
		flip = true;
	}
	
	for(int i = 1; i <= n-a; i++){
		ans[i][i+1] = 1;
		ans[i+1][i] = 1;
	}
	
	if(flip){
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){
				if(i == j) continue;
				ans[i][j] = !ans[i][j];
			}
		}
	}
	
	cout << "YES" << endl;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			cout << ans[i][j];
		}
		cout << endl;
	}
	
	return 0;
}