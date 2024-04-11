#include <iostream>
#define llint long long 

using namespace std;

llint A, B;
llint x, y, z;

int main(void)
{
	cin >> A >> B;
	cin >> x >> y >> z;
	
	llint needY = 0, needB = 0;
	needY += x * 2 + y;
	needB = y + 3 * z;
	
	llint ans = 0;
	ans += max(0LL, needY - A);
	ans += max(0LL, needB - B);
	
	cout << ans << endl;
	return 0;
}