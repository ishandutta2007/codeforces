#include <iostream>
#include <stdlib.h>
#define llint long long

using namespace std;

llint T;
llint n, x, y, d;

int main(void)
{
	cin >> T;
	for(int t = 0; t < T; t++){
		cin >> n >> x >> y >> d;
		
		if(abs(x-y)%d == 0){
			cout << abs(x-y)/d << endl;
			continue;
		}
		
		llint ans = 1e10;
		if(abs(y-1)%d == 0) ans = min(ans, (x+d-2)/d + (y-1)/d);
		if(abs(n-y)%d == 0) ans = min(ans, (n-x+d-1)/d + (n-y)/d);
		if(ans == 1e10) ans = -1;
		cout << ans << endl;
	}
	return 0;
}