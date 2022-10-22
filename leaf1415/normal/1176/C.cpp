#include <iostream>
#define llint long long

using namespace std;

llint n;
llint a[500005];
llint cnt[10];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	
	for(int i = 1; i <= n; i++){
		if(a[i] == 4) a[i] = 1;
		if(a[i] == 8) a[i] = 2;
		if(a[i] == 15) a[i] = 3;
		if(a[i] == 16) a[i] = 4;
		if(a[i] == 23) a[i] = 5;
		if(a[i] == 42) a[i] = 6;
	}
	
	llint ans = 0;
	for(int i = 1; i <= n; i++){
		if(a[i] == 1){
			cnt[1]++;
			continue;
		}
		if(cnt[a[i]-1] > 0){
			cnt[a[i]-1]--;
			cnt[a[i]]++;
		}
		else ans++;
	}
	for(int i = 1; i <= 5; i++) ans += i * cnt[i];
	cout << ans << endl;
	
	return 0;
}