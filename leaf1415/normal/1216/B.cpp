#include <iostream>
#include <string>
#include <algorithm>
#include <utility>
#define llint long long

using namespace std;
typedef pair<llint, llint> P;

llint n;
P p[1005];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for(int i = 0; i < n; i++) cin >> p[i].first, p[i].second = i;
	sort(p, p+n);
	reverse(p, p+n);
	
	llint ans = 0;
	for(int i = 0; i < n; i++) ans += i*p[i].first+1;
	cout << ans << endl;
	for(int i = 0; i < n; i++) cout << p[i].second+1 << " "; cout << endl;
	
	return 0;
}