#include <iostream>

using namespace std;

int a, b, c, n;

int main(void)
{
	cin >> a >> b >> c >> n;
	if(c > a || c > b){
		cout << -1 << endl;
		return 0;
	}
	int ans = n - (a+b-c);
	if(ans <= 0) ans = -1;
	cout << ans << endl;
	return 0;
}