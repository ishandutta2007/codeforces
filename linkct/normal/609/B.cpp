#include <iostream>
using namespace std;

int n, m, cnt[15];

int main(){
	int i, sum = 0, ans = 0, t;
	cin >> n >> m;
	for(i = 1; i <= n; ++ i){
		cin >> t;
		++ cnt[t];
	}
	for(i = 1; i <= m; ++ i) sum += cnt[i];
	for(i = 1; i <= m; ++ i)
		ans += cnt[i] * (sum -= cnt[i]);
	cout << ans << endl;
	return 0;
}