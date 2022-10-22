#include <iostream>
#include <stdlib.h>
#define llint long long
#define inf 1e18

using namespace std;

llint n;
llint a[100005];

int main(void)
{
	cin >> n;
	for(int i = 0; i < n; i++) cin >> a[i];
	if(n == 1){
		cout << 0 << endl;
		return 0;
	}
	
	llint ans = inf;
	for(llint df = -1; df <= 1; df++){
		for(llint ds = -1; ds <= 1; ds++){
			llint f = a[0] + df, s = a[1] + ds;
			llint d = s - f;
			llint tmp = 0;
			for(int i = 0; i < n; i++){
				if(abs(a[i] - (f+d*i)) > 1) goto ng;
				tmp += abs(a[i] - (f+d*i));
			}
			ans = min(ans, tmp);
			ng:;
		}
	}
	
	if(ans >= inf) ans = -1;
	cout << ans << endl;
	return 0;
}