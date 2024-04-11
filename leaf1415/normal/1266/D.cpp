#include <iostream>
#include <string>
#include <vector>
#include <utility>

#define llint long long

using namespace std;
typedef pair<llint, llint> P;

llint n, m;
llint a[100005];
vector<P> pvec, nvec;
vector<pair<llint, P> > ans;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	llint u, v, d;
	for(int i = 1; i <= m; i++){
		cin >> u >> v >> d;
		a[u] -= d, a[v] += d;
	}
	for(int i = 1; i <= n; i++){
		if(a[i] > 0) pvec.push_back(P(a[i], i));
		if(a[i] < 0) nvec.push_back(P(a[i], i));
	}
	
	llint rem, p = 0;
	for(int i = 0; i < nvec.size(); i++){
		rem = -nvec[i].first;
		while(rem > 0){
			llint x = min(pvec[p].first, rem);
			rem -= x;
			pvec[p].first -= x;
			ans.push_back(make_pair(nvec[i].second, P(pvec[p].second, x)));
			if(pvec[p].first == 0) p++;
		}
	}
	cout << ans.size() << endl;
	for(int i = 0 ; i < ans.size(); i++) cout << ans[i].first << " " << ans[i].second.first << " " << ans[i].second.second << "\n";
	flush(cout);
	
	return 0;
}