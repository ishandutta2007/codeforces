#include <iostream>
#include <string>
#define llint long long
#define inf 1e18

using namespace std;

llint T;
llint n;
llint a[100005], s[100005], m[100005];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	for(int t = 0; t < T; t++){
		cin >> n;
		for(int i = 1; i <= n; i++) cin >> a[i];
		for(int i = 1; i <= n; i++) s[i] = s[i-1] + a[i];
		m[0] = 0;
		for(int i = 1; i <= n; i++) m[i] = min(m[i-1], s[i]);
		
		llint ans = -inf;
		for(int i = 1; i <= n-1; i++){
			ans = max(ans, s[i]-m[i-1]);
			ans = max(ans, s[n]-s[i]);
		}
		if(ans < s[n]) cout << "YES" << "\n";
		else cout << "NO" << "\n";
	}
	flush(cout);
	
	return 0;
}