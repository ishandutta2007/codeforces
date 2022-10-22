#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <utility>
#define llint long long
#define inf 1e18

using namespace std;
typedef pair<llint, llint> P;

llint n;
llint a[200005], d[200005];
P p[200005];

llint dp[200005];
llint pre[200005];
llint ans[200005];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		p[i] = make_pair(a[i], i);
	}
	sort(p+1, p+n+1);
	
	for(int i = 1; i <= n-1; i++) d[i] = p[i+1].first - p[i].first;
	d[n] = 0;
	
	for(int i = 0; i <= n; i++) dp[i] = -inf;
	dp[0] = 0;
	for(int i = 0; i <= n-1; i++){
		for(int j = 3; j < 6; j++){
			if(i+j <= n && dp[i+j] < dp[i] + d[i+j]){
				dp[i+j] = dp[i] + d[i+j];
				pre[i+j] = i;
			}
		}
	}
	
	//for(int i = 0; i <= n; i++) cout<< dp[i] << " "; cout << endl;;
	
	llint id = 1, cur = n;
	while(cur > 0){
		llint nx = pre[cur];
		for(int i = nx+1; i <= cur; i++) ans[p[i].second] = id;
		id++;
		cur = nx;
	}
	
	llint sum = p[n].first - p[1].first;
	sum -= dp[n];
	
	cout << sum << " " << id-1 << endl;
	for(int i = 1; i <= n; i++) cout << ans[i] << " "; cout << endl;
	
	return 0;
}