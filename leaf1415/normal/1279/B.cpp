#include <iostream>
#define llint long long

using namespace std;

llint T;
llint n, s;
llint a[100005];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	for(int t = 1; t <= T; t++){
		cin >> n >> s;
		for(int i = 1; i <= n; i++) cin >> a[i];
		
		llint sum = 0, mx = 0, mx_i, ans = 0;
		for(int i = 1; i <= n; i++){
			sum += a[i];
			if(mx < a[i]){
				mx = a[i];
				mx_i = i;
			}
			if(sum <= s) continue;
			if(sum-mx <= s) ans = mx_i;
			else break;
		}
		cout << ans << endl;
	}
	
	return 0;
}