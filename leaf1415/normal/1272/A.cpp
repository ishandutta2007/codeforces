#include <iostream>
#include <cstdlib>
#define llint long long

using namespace std;

llint Q;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> Q;
	llint a, b, c;
	for(int q = 0; q < Q; q++){
		cin >> a >> b >> c;
		llint ans = 1e18;
		for(int i = -1; i <= 1; i++){
			for(int j = -1; j <= 1; j++){
				for(int k = -1; k <= 1; k++){
					llint x = a+i, y = b+j, z = c+k;
					ans = min(ans, abs(x-y)+abs(y-z)+abs(z-x));
				}
			}
		}
		cout << ans << endl;
	}
	
	return 0;
}