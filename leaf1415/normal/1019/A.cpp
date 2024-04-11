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
#define rep(x, s, t) for(llint (x) = (s); (x) <= (t); (x)++)
#define chmin(x, y) (x) = min((x), (y))
#define chmax(x, y) (x) = max((x), (y))
#define all(x) (x).begin(),(x).end()
#define inf 1e18

using namespace std;

typedef long long llint;
typedef pair<llint, llint> P;

llint n, m;
vector<llint> vec[3005];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	llint p, c;
	rep(i, 1, n){
		cin >> p >> c;
		vec[p].push_back(c);
	}
	rep(i, 1, m) sort(all(vec[i])), reverse(all(vec[i]));
	
	llint ans = inf;
	rep(i, 1, n){
		llint cnt = vec[1].size(), sum = 0;
		vector<llint> tmp;
		rep(j, 2, m){
			rep(k, 0, (int)vec[j].size()-1){
				if(k >= i-1) sum += vec[j][k], cnt++;
				else tmp.push_back(vec[j][k]);
			}
		}
		if(cnt > i) continue;
		sort(all(tmp)), reverse(all(tmp));
		while(cnt < i) sum += tmp.back(), tmp.pop_back(), cnt++;
		chmin(ans, sum);
	}
	cout << ans << endl;
	
	return 0;
}