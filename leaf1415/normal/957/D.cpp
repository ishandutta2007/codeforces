#include <iostream>
#define llint long long

using namespace std;

llint n;
llint m[100005];
llint need[100005];

int main(void)
{
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> m[i];
	
	llint nd = 0;
	for(int i = n; i >= 1; i--){
		need[i] = nd = max(nd, m[i]);
		nd--;
	}
	nd = 0;
	for(int i = 1; i <= n; i++){
		need[i] = nd = max(nd, need[i]);
	}
	
	llint ans = 0;
	for(int i = 1; i <= n; i++){
		ans += need[i] - m[i];
	}
	cout << ans << endl;
	return 0;
}