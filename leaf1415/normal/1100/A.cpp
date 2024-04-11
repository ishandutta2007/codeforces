#include <iostream>
#include <stdlib.h>

using namespace std;

int n, k;
int a[105];

int main(void)
{
	cin >> n >> k;
	for(int i = 1; i <= n; i++) cin >> a[i];
	
	int ans = 0;
	for(int b = 0; b < k; b++){
		int tmp = 0;
		for(int i = 1; i <= n; i++){
			if(i%k != b) tmp += a[i];
		}
		ans = max(ans, abs(tmp));
	}
	cout << ans << endl;
	return 0;
}