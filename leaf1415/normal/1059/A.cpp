#include <iostream>
#define llint long long

using namespace std;

llint n, L, a;
llint t[100005], l[100005];

int main(void)
{
	cin >> n >> L >> a;
	for(int i = 1; i <= n; i++) cin >> t[i] >> l[i];
	t[n+1] = L, l[n+1] = 0;
	
	llint ans = 0;
	for(int i = 1; i <= n+1; i++){
		ans += (t[i] - (t[i-1]+l[i-1])) / a;
	}
	cout << ans << endl;
	
	return 0;
}