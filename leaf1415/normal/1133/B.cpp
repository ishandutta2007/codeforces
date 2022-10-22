#include <iostream>

using namespace std;

int n, k;
int a[200005];
int cnt[105];

int main(void)
{
	cin >> n >> k;
	for(int i = 0; i < n; i++) cin >> a[i];
	for(int i = 0; i < n; i++) a[i] %= k;
	
	for(int i = 0; i < n; i++) cnt[a[i]]++;
	
	int ans = cnt[0]/2;
	if(k%2) for(int i = 1; i <= k/2; i++) ans += min(cnt[i], cnt[k-i]);
	else{
		for(int i = 1; i < k/2; i++) ans += min(cnt[i], cnt[k-i]);
		ans += cnt[k/2]/2;
	}
	cout << ans*2 << endl;
	
	return 0;
}