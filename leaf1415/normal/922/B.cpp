#include <iostream>

using namespace std;

int n;

int main(void)
{
	cin >> n;
	
	int ans = 0;
	for(int a = 1; a <= n; a++){
		for(int b = 1; b <= n; b++){
			if(a > b) continue;
			int c = a ^ b;
			if(c <= n && c >= b && a + b > c) ans++;
		}
	}
	
	cout << ans << endl;
	return 0;
}