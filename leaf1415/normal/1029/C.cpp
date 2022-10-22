#include <iostream>
#include <utility>
#include <algorithm>
#define inf 1e9+7

using namespace std;
typedef pair<int, int> P;

int n;
int l[300005], r[300005];
P p[300005];


int main(void)
{
	cin >> n;
	for(int i = 0; i < n; i++) cin >> l[i] >> r[i];
	
	for(int i = 0; i < n; i++) p[i] = make_pair(l[i], -r[i]);
	sort(p, p+n), reverse(p, p+n);
	for(int i = 0; i < n; i++) p[i].second *= -1;
	
	int ans = 0, L = -1, R = inf;
	for(int i = 1; i < n; i++){
		L = max(L, p[i].first);
		R = min(R, p[i].second);
	}
	ans = max(ans, R-L);
	
	for(int i = 0; i < n; i++) p[i] = make_pair(r[i], -l[i]);
	sort(p, p+n);
	for(int i = 0; i < n; i++) p[i].second *= -1;
	
	L = -1, R = inf;
	for(int i = 1; i < n; i++){
		L = max(L, p[i].second);
		R = min(R, p[i].first);
	}
	ans = max(ans, R-L);
	
	cout << ans << endl;
	return 0;
}