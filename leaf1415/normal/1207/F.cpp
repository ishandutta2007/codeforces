#include <iostream>
#include <vector>
#include <utility>
#include <map>
#define llint long long
#define mod 998244353

using namespace std;
typedef pair<llint, llint> P;

llint Q;
llint sum[715][715];
llint a[500005];
const llint R = 600;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> Q;
	llint t, x, y, ans;
	for(int q = 0; q < Q; q++){
		cin >> t >> x >> y;
		if(t == 1){
			a[x] += y;
			for(int j = 1; j <= R; j++) sum[j][x%j] += y;
		}
		else{
			ans = 0;
			if(x <= R) cout << sum[x][y] << "\n";
			else{
				ans = 0;
				for(int j = y; j <= 500000; j += x) ans += a[j];
				cout << ans << "\n";
			}
		}
	}
	flush(cout);
	
	return 0;
}