#include <iostream>
#include <algorithm>
#include <vector>
#define llint long long

using namespace std;

llint n, I;
llint a[400005];
vector<llint> comp;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> I;
	for(int i = 0; i < n; i++) cin >> a[i];
	for(int i = 0; i < n; i++) comp.push_back(a[i]);
	sort(comp.begin(), comp.end());
	comp.erase(unique(comp.begin(), comp.end()), comp.end());
	for(int i = 0 ; i < n; i++) a[i] = lower_bound(comp.begin(), comp.end(), a[i]) - comp.begin();
	
	llint b = 8*I/n;
	if(b >= 32){
		cout << 0 << endl;
		return 0;
	}
	sort(a, a+n);
	
	llint ans = 0, len = 1LL << b;
	for(int i = 0; i < n; i++){
		ans = max(ans, (llint)(lower_bound(a, a+n, a[i]+len) - lower_bound(a, a+n, a[i])));
	}
	cout << n - ans << endl;
	
	return 0;
}