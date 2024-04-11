#include <iostream>
#define llint long long

using namespace std;

llint Q;
llint a[105];
int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> Q;
	llint n;
	for(int q = 0; q < Q; q++){
		cin >> n;
		for(int i = 1; i <= n; i++) cin >> a[i];
		
		llint cnt[3] = {0, 0, 0};
		for(int i = 1; i <= n; i++){
			cnt[a[i]%3]++;
		}
		llint ans = cnt[0];
		ans += min(cnt[1], cnt[2]);
		llint mn = min(cnt[1], cnt[2]);
		cnt[1] -= mn, cnt[2] -= mn;
		ans += cnt[1]/3, ans += cnt[2]/3;
		cout << ans << endl;
	}
	
	return 0;
}