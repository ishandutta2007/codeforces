#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#define llint long long

using namespace std;
typedef pair<llint, llint> P;

llint n;
llint p[200005];

llint ans;
void calc(llint l, llint r)
{
	//cout << l << " " << r << " " << ans << endl;
	
	if(r-l <= 1) return;
	llint m = (l+r)/2;
	
	vector<P> lvec, rvec;
	
	llint mx = 0;
	for(int i = m-1; i >= l; i--){
		mx = max(mx, p[i]);
		lvec.push_back(make_pair(p[i], mx));
	}
	sort(lvec.begin(), lvec.end());
	
	mx = 0;
	for(int i = m; i <= r; i++){
		mx = max(mx, p[i]);
		rvec.push_back(make_pair(p[i], mx));
	}
	sort(rvec.begin(), rvec.end());
	
	for(int i = 0; i < lvec.size(); i++){
		llint x = lvec[i].second - lvec[i].first;
		auto p = lower_bound(rvec.begin(), rvec.end(), make_pair(x, 0LL));
		if(p == rvec.end()) continue;
		if(p->first != x) continue;
		if(p->second > lvec[i].second) continue;
		ans++;
	}
	swap(lvec, rvec);
	for(int i = 0; i < lvec.size(); i++){
		llint x = lvec[i].second - lvec[i].first;
		auto p = lower_bound(rvec.begin(), rvec.end(), make_pair(x, 0LL));
		if(p == rvec.end()) continue;
		if(p->first != x) continue;
		if(p->second > lvec[i].second) continue;
		ans++;
	}
	
	calc(l, m-1), calc(m, r);
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> p[i];
	
	calc(1, n);
	cout << ans << endl;
	return 0;
}