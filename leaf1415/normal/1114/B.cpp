#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#define llint long long

using namespace std;
typedef pair<llint, llint> P;

llint n, m, k;
llint a[200005];
vector<P> vec;
bool use[200005];
vector<llint> pos;

int main(void)
{
	cin >> n >> m >> k;
	for(int i = 1; i <= n; i++) cin >> a[i];
	
	for(int i = 1; i <= n; i++) vec.push_back(make_pair(a[i], i));
	sort(vec.rbegin(), vec.rend());
	llint ans = 0;
	for(int i = 0; i < m*k; i++){
		use[vec[i].second] = true;
		ans += vec[i].first;
	}
	
	cout << ans << endl;
	llint cnt = 0, d = 0;
	for(int i = 1; i <= n; i++){
		if(use[i]) cnt++;
		if(cnt == m) cnt = 0, d++, cout << i << " ";
		if(d == k-1){
			cout << endl;
			break;
		}
	}
	return 0;
}