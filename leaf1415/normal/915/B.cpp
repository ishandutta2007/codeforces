#include <iostream>
#include <stdlib.h>
#include <math.h>

using namespace std;

int n, pos, l, r;

int main(void)
{
	cin >> n >> pos >> l >> r;
	int dl = abs(pos - l), dr = abs(pos - r);
	
	int ans = 0;
	if(1 < l) ans += dl + 1;
	if(r < n) ans += dr + 1;
	if(1 < l && r < n){
		ans -= max(dl, dr);
		ans += r - l;
	}
	
	cout << ans << endl;
	return 0;
}