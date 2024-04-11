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

llint n, h;
llint l[200005], r[200005];
vector<P> vec;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> h;
	rep(i, 1, n) cin >> l[i] >> r[i];
	vec.push_back(P(-inf, l[1]));
	rep(i, 2, n) vec.push_back(P(r[i-1], l[i]));
	vec.push_back(P(r[n], inf));
	
	llint ans = 0, id = 0, pos = vec[0].second, rem = h;
	rep(i, 0, (int)vec.size()-2)
	{
		while(rem > 0){
			if(pos == vec[id].second) id++, pos = vec[id].first;
			else{
				llint x = min(vec[id].second - pos, rem);
				pos += x, rem -= x;
			}
		}
		ans = max(ans, pos - vec[i].second);
		rem += vec[i+1].second - vec[i+1].first;
	}
	cout << ans << endl;
	
	return 0;
}