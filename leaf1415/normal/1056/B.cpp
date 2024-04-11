#include <iostream>
#define llint long long

using namespace std;

llint n, m;

int main(void)
{
	cin >> n >> m;
	
	llint ans = 0;
	for(int i = 0; i < m; i++){
		for(int j = 0; j < m; j++){
			if((i*i+j*j)%m) continue;
			llint x = n/m;
			if(n%m >= i) x++;
			if(i == 0) x--;
			
			llint y = n/m;
			if(n%m >= j) y++;
			if(j == 0) y--;
			
			ans += x*y;
		}
	}
	cout << ans << endl;
	
	return 0;
}