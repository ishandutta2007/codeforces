#include <iostream>
#include <stdlib.h>
#define llint long long

using namespace std;

llint Q;

int main(void)
{
	cin >> Q;
	
	llint x, y, k;
	for(int q = 0; q < Q; q++){
		cin >> x >> y >> k;
		x = abs(x), y = abs(y);
		if(x > k || y > k){
			cout << -1 << endl;
			continue;
		}
		
		if((x+y)%2) cout << k-1 << endl;
		else cout << k - (x+k)%2*2 << endl;
	}
	
	return 0;
}