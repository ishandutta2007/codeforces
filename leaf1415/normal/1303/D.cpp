#include <iostream>
#include <string>
#include <set>
#include <algorithm>
#include <vector>
#define llint long long
#define inf 1e18

using namespace std;

llint T;
llint n, m;
llint a[65];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	for(int t = 0; t < T; t++){
		cin >> n >> m;
		for(int i = 0; i < 65; i++) a[i] = 0;
		llint x;
		for(int i = 1; i <= m; i++){
			cin >> x;
			llint cnt = 0;
			for(;x;x/=2) cnt++;
			a[cnt-1]++;
		}
		
		llint ans = 0;
		for(int i = 0; i < 61; i++){
			if(n & (1LL<<i)){
				if(a[i] == 0){
					llint p = -1;
					for(int j = i+1; j < 61; j++){
						if(a[j]){
							p = j;
							break;
						}
					}
					if(p == -1){
						cout << -1 << "\n";
						goto end;
					}
					for(int j = p; j >= i+1; j--){
						a[j]--;
						a[j-1] += 2;
						ans++;
					}
				}
				a[i]--;
			}
			a[i+1] += a[i]/2;
		}
		cout << ans << "\n";
		end:;
	}
	flush(cout);
	
	return 0;
}