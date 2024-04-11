#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#define llint long long

using namespace std;

llint n;
llint cnt[150005];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	llint a;
	for(int i = 1; i <= n; i++){
		cin >> a;
		cnt[a]++;
	}
	llint ans = 0;
	for(int i = 1; i <= 150001; i++){
		if(cnt[i-1] > 0) ans++;
		else if(cnt[i] >= 1) cnt[i]--, ans++;
		else if(cnt[i+1] > 0) cnt[i+1]--, ans++;
	}
	cout << ans << endl;
	
	return 0;
}