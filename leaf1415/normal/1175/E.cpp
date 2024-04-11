#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
#include <utility>
#include <set>
#include <vector>
#define llint long long

using namespace std;
typedef pair<llint, llint> P;

llint n, m, x, y;
llint l[200005], r[200005];
vector<llint> vecin[500005], vecout[500005];
llint succ[20][500005];
multiset<P> S;
const llint INF = 500003;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> l[i] >> r[i];
		vecin[l[i]].push_back(r[i]-1);
		vecout[r[i]-1].push_back(l[i]);
	}
	for(int i = 0; i < 500005; i++) succ[0][i] = INF;
	for(int i = 0; i < 500005; i++){
		for(int j = 0; j < vecin[i].size(); j++){
			S.insert(make_pair(vecin[i][j], i));
		}
		if(S.size() == 0) continue;
		auto p = S.end(); p--;
		succ[0][i] = p->first+1;
		for(int j = 0; j < vecout[i].size(); j++){
			S.erase(S.lower_bound(make_pair(i, vecout[i][j])));
		}
	}
	for(int i = 1; i < 20; i++){
		for(int j = 0; j < 500005; j++){
			succ[i][j] = succ[i-1][succ[i-1][j]];
		}
	}
	
	/*for(int j = 0; j < 5; j++){
	for(int i = 0; i < 5; i++) cout << succ[j][i] << " "; cout << endl; }*/
	
	for(int q = 0; q < m; q++){
		cin >> x >> y;
		y--;
		llint p = x, ans = 0;
		for(int i = 19; i >= 0; i--){
			if(succ[i][p] <= y) p = succ[i][p], ans += 1<<i;
		}
		p = succ[0][p], ans++;
		if(p == INF) ans = -1;
		cout << ans << "\n";
	}
	flush(cout);
	
	return 0;
}