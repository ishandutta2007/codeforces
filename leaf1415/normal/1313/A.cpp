#include <iostream>
#define llint long long

using namespace std;

llint T;
llint a[3];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	for(int t = 0; t < T; t++){
		for(int i = 0; i < 3; i++) cin >> a[i];
		llint ans = 0;
		for(int i = 0; i < (1<<8); i++){
			llint need[3] = {}, cnt = 0;
			for(int j = 0; j < 8; j++){
				if(j == 0) continue;
				if((i & (1<<j)) == 0) continue;
				cnt++;
				for(int k = 0; k < 3; k++){
					if((1<<k) & j) need[k]++;
				}
			}
			bool flag = true;
			for(int j = 0; j < 3; j++){
				if(need[j] > a[j]) flag = false;
			}
			if(flag) ans = max(ans, cnt);
		}
		cout << ans << endl;
	}
	
	return 0;
}