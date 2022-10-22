#include <iostream>
#define llint long long

using namespace std;

llint T;
llint x, y, a, b;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	for(int t = 0; t < T; t++){
		cin >> x >> y >> a >> b;
		if((y-x)%(a+b)) cout << -1 << endl;
		else cout << (y-x)/(a+b) << endl;
	}
	
	return 0;
}