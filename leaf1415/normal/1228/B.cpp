#include <iostream>
#include <set>
#define llint long long
#define mod 1000000007

using namespace std;

llint h, w;
llint r[1005], c[1005];
llint a[1005][1005];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> h >> w;
	for(int i = 1; i <= h; i++) cin >> r[i];
	for(int i = 1; i <= w; i++) cin >> c[i];
	
	for(int i = 1; i <= h; i++){
		for(int j = 1; j <= r[i]; j++){
			if(a[i][j] == -1){
				cout << 0 << endl;
				return 0;
			}
			a[i][j] = 1;
		}
		if(a[i][r[i]+1] == 1){
			cout << 0 << endl;
			return 0;
		}
		a[i][r[i]+1] = -1;
	}
	
	for(int i = 1; i <= w; i++){
		for(int j = 1; j <= c[i]; j++){
			if(a[j][i] == -1){
				cout << 0 << endl;
				return 0;
			}
			a[j][i] = 1;
		}
		if(a[c[i]+1][i] == 1){
			cout << 0 << endl;
			return 0;
		}
		a[c[i]+1][i] = -1;
	}
	
	llint ans = 1;
	for(int i = 1; i <= h; i++){
		for(int j = 1; j <= w; j++){
			if(a[i][j] == 0) ans *= 2, ans %= mod;
		}
	}
	cout << ans << endl;
	
	return 0;
}