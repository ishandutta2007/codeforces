#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <cstdlib>
#define llint long long
#define inf 1e18

using namespace std;

llint h, w, k, q;
llint x[200005], y[200005];
vector<llint> qvec, compY;
vector<llint> vec[200005];
map<llint, llint> mp[200005];

void comp(llint x[], vector<llint> &vec)
{
	vec.push_back(0);
	for(int i = 1; i <= k; i++) vec.push_back(x[i]);
	sort(vec.begin(), vec.end());
	vec.erase(unique(vec.begin(), vec.end()), vec.end());
	for(int i = 1; i <= k; i++) x[i] = lower_bound(vec.begin(), vec.end(), x[i]) - vec.begin();
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> h >> w >> k >> q;
	for(int i = 1; i <= k; i++) cin >> y[i] >> x[i];
	llint b;
	for(int i = 0; i < q; i++){
		cin >> b;
		qvec.push_back(b);
	}
	qvec.push_back(0), qvec.push_back(w+1);
	sort(qvec.begin(), qvec.end());
	
	llint ans = 0;
	for(int i = 1; i <= k; i++) ans = max(ans, y[i]);
	ans--;
	
	comp(y, compY);
	llint H = compY.size()-1;
	
	for(int i = 1; i <= k; i++) vec[y[i]].push_back(x[i]);
	for(int i = 1; i <= H; i++) sort(vec[i].begin(), vec[i].end());
	
	
	if(compY[1] == 1) mp[1][1] = 0;
	else{
		llint r = *lower_bound(qvec.begin(), qvec.end(), 1);
		mp[1][r] = r-1;
	}
	
	for(int i = 1; i < H; i++){
		llint l = vec[i].front(), r = vec[i].back();
		auto lp = lower_bound(qvec.begin(), qvec.end(), l), rp = lower_bound(qvec.begin(), qvec.end(), r);
		llint ll = *(lp-1), lr = *lp, rl = *(rp-1), rr = *rp;
		mp[i+1][ll] = mp[i+1][lr] = mp[i+1][rl] = mp[i+1][rr] = inf;
		for(auto it = mp[i].begin(); it != mp[i].end(); it++){
			if(ll > 0) mp[i+1][ll] = min(mp[i+1][ll], abs(it->first-r)+abs(r-l)+abs(l-ll) + it->second);
			if(lr <= w) mp[i+1][lr] = min(mp[i+1][lr], abs(it->first-r)+abs(r-l)+abs(l-lr) + it->second);
			if(rl > 0) mp[i+1][rl] = min(mp[i+1][rl], abs(it->first-l)+abs(r-l)+abs(r-rl) + it->second);
			if(rr <= w) mp[i+1][rr] = min(mp[i+1][rr], abs(it->first-l)+abs(r-l)+abs(r-rr) + it->second);
		}
	}
	
	/*for(int i = 1; i <= H; i++){
		for(auto it = mp[i].begin(); it != mp[i].end(); it++) cout << it->first<< ":" << it->second << " ";
		cout << endl;
	}*/
	
	llint tmp = inf;
	llint l = vec[H].front(), r = vec[H].back();
	for(auto it = mp[H].begin(); it != mp[H].end(); it++){
		tmp = min(tmp, abs(it->first-r)+abs(r-l) + it->second);
		tmp = min(tmp, abs(it->first-l)+abs(r-l) + it->second);
	}
	ans += tmp;
	cout << ans << endl;
	
	return 0;
}