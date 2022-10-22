#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <queue>
#define llint long long

using namespace std;

llint n, m;
llint t[200005];
llint cnt[105];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> t[i];
	
	llint sum = 0, need;
	for(int i = 1; i <= n; i++){
		sum += t[i];
		need = sum - m;
		if(need <= 0){
			cout << 0 << " ";
			cnt[t[i]]++;
			continue;
		}
		llint ans = 0;
		for(int j = 100; j >= 1; j--){
			if(cnt[j] * j <= need){
				need -= cnt[j] * j;
				ans += cnt[j];
			}
			else{
				ans += (need+j-1) / j;
				break;
			}
			if(need == 0) break;
		}
		cnt[t[i]]++;
		cout << ans << " ";
	}
	cout << endl;
	
	return 0;
}