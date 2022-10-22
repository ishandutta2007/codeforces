#include <iostream>

using namespace std;

int n;

int main(void)
{
	cin >> n;
	int ans = 0, mul = 1;
	while(n >= mul){
		ans++;
		n -= mul;
		mul *= 2;
	}
	if(n > 0) ans++;
	cout << ans << endl;
	return 0;
}