#include <iostream>

using namespace std;

int n, k;
int cnt[1005];

int main(void)
{
	cin >> n >> k;
	int a;
	for(int i = 1; i <= n; i++){
		cin >> a;
		cnt[a]++;
	}
	int ans = 0, rem = 0;
	for(int i = 1; i <= k; i++){
		ans += cnt[i]/2*2;
		rem += cnt[i] % 2;
	}
	ans += (rem+1)/2;
	cout << ans << endl;
	return 0;
}