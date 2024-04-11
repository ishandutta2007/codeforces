#include <iostream>
#include <string>
#define llint long long

using namespace std;

llint n, m;
string s[1005];
llint a[1005];
llint cnt[5];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> s[i], s[i] = "#" + s[i];
	for(int i = 1; i <= m; i++) cin >> a[i];
	
	llint ans = 0;
	for(int i = 1; i <= m; i++){
		for(int j = 0; j < 5; j++) cnt[j] = 0;
		for(int j = 1; j <= n; j++) cnt[s[j][i]-'A']++;
		llint mx = 0;
		for(int j = 0; j < 5; j++) mx = max(mx, cnt[j]);
		ans += mx * a[i];
	}
	cout << ans << endl;
	
	return 0;
}