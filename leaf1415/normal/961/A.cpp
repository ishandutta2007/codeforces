#include <iostream>

using namespace std;

int n, m;
int cnt[1005];

int main(void)
{
	cin >> n >> m;
	int c;
	for(int i = 0; i < m; i++){
		cin >> c;
		cnt[c]++;
	}
	int ans = 100000000;
	for(int i = 1; i <= n; i++) ans = min(ans, cnt[i]);
	cout << ans << endl;
	
	return 0;
}