#include <iostream>
#include <algorithm>
#include <vector>
#define llint long long

using namespace std;

llint n, k;
llint a[300005];
vector<llint> vec;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> k;
	for(int i = 0; i < n; i++) cin >> a[i];
	
	llint ans = a[n-1] - a[0];
	for(int i = 1; i < n; i++) vec.push_back(a[i]-a[i-1]);
	sort(vec.rbegin(), vec.rend());
	for(int i = 0; i < k-1; i++) ans -= vec[i];
	
	cout << ans << endl;
	
	return 0;
}