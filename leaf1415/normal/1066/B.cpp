#include <iostream>

using namespace std;

int n, r;
int a[1005];
int nx[1005];

int main(void)
{
	cin >> n >> r;
	r--;
	for(int i = 1; i <= n; i++) cin >> a[i];
	
	int y = 1e9;
	for(int i = n; i >= 1; i--){
		nx[i] = y;
		if(a[i]) y = i;
	}
	
	int ok = 0, ans = 0;
	for(int i = 1; i <= n; i++){
		if(a[i]){
			if(nx[i] - (ok+1) > r){
				ans++;
				ok = i + r;
				if(ok >= n) break;
			}
		}
		else{
			if(nx[i] - (ok+1) > r){
				cout << -1 << endl;
				return 0;
			}
		}
	}
	cout << ans << endl;
	return 0;
}