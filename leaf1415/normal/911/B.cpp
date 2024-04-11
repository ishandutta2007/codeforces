#include <iostream>

using namespace std;

int n, a, b;

int main(void)
{
	cin >> n >> a >> b;
	
	int ans = 0;
	for(int x = 1; x <= a+b; x++){
		if(a < x || b < x) continue;
		if(a/x + b/x >= n) ans = x;
	}
	cout << ans << endl;
	return 0;
}