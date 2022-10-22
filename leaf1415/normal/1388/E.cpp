#include <iostream>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <cassert>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <bitset>
#include <string>
#include <algorithm>
#include <utility>
#define llint long long
#define inf 1e18
#define rep(x, s, t) for(llint (x) = (s); (x) < (t); (x)++)
#define Rep(x, s, t) for(llint (x) = (s); (x) <= (t); (x)++)
#define chmin(x, y) (x) = min((x), (y))
#define chmax(x, y) (x) = max((x), (y))

using namespace std;
typedef pair<llint, llint> P;
typedef pair<double,  P> E;

llint n;
llint l[2005], r[2005], y[2005];
vector<P> vec;
vector<E> evec;

double get(double x1, double y1, double x2, double y2)
{
	return (x2-x1)/(y1-y2);
}

int main(void)
{
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> l[i] >> r[i] >> y[i];
	
	for(int i = 1; i <= n; i++) vec.push_back(P(y[i], i));
	sort(vec.rbegin(), vec.rend());
	
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			if(i == j || y[j] >= y[i]) continue;
			double L = get(r[i], y[i], l[j], y[j]), R = get(l[i], y[i], r[j], y[j]);
			evec.push_back(E(L, P(3, i)));
			evec.push_back(E(R, P(2, i)));
		}
	}
	
	double pre = -inf/2;
	for(int i = 0; i < vec.size(); i++){
		llint id = vec[i].second;
		
		double tmp = inf;
		for(int j = 1; j <= n; j++){
			if(j == id || y[j] > y[id]) continue;
			if(y[j] == y[id] && l[j] < l[id]){
				tmp = -inf;
				continue;
			}
			double res = get(l[id], y[id], l[j], y[j]);
			tmp = min(tmp, res);
		}
		if(pre >= tmp) continue;
		
		evec.push_back(E(pre, P(0, id)));
		pre = tmp;
	}
	
	pre = inf/2;
	for(int i = 0; i < vec.size(); i++){
		llint id = vec[i].second;
		
		double tmp = -inf;
		for(int j = 1; j <= n; j++){
   			if(j == id || y[j] > y[id]) continue;
			if(y[j] == y[id] && r[j] > r[id]){
				tmp = inf;
				continue;
			}
			double res = get(r[id], y[id], r[j], y[j]);
			tmp = max(tmp, res);
		}
		if(pre <= tmp) continue;
		
		pre = tmp;
		evec.push_back(E(pre, P(1, id)));
	}
	
	sort(evec.begin(), evec.end());
	//for(int i = 0; i < evec.size(); i++) cout << evec[i].first << " " << evec[i].second.first << " " << evec[i].second.second << endl;
	
	double ans = inf;
	llint lid = -1, rid = -1, cnt = 0;
	for(int i = 0; i < evec.size(); i++){
		llint id = evec[i].second.second, type = evec[i].second.first;
		if(type == 0) lid = id;
		if(type == 1) rid = id;
		if(type == 3) cnt++;
		if(type == 2) cnt--;
		
		if(lid == -1 || rid == -1 || cnt > 0) continue;
		ans = min(ans, (r[rid]-l[lid]) + (y[rid]-y[lid]) * evec[i].first);
		if(i+1 < evec.size()) ans = min(ans, (r[rid]-l[lid]) + (y[rid]-y[lid]) * evec[i+1].first);
		
		//cout << evec[i].first << " " << lid << " " << rid << " " << cnt << " " << ans << endl;
	}
	
	printf("%.11f\n", ans);
	
	return 0;
}