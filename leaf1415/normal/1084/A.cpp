#include <iostream>

using namespace std;

int n;
int a[105];

int main(void)
{
	cin >> n;
	for(int i = 0; i < n; i++) cin >> a[i];
	
	int ans = 0;
	for(int i = 0; i < n; i++) ans += a[i] * i;
	cout << ans * 4 << endl;
	return 0;
}