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

llint n;
llint a[200005];
vector<llint> vec;
map<llint, llint> mp;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	rep(i, 1, n) cin >> a[i], mp[a[i]]++;
	for(auto x : mp) vec.push_back(x.second);
	sort(all(vec));
	
	llint ans = 0;
	rep(i, 1, n){
		llint sum = 0, p = -1, d = i;
		while(1){
			p = lower_bound(vec.begin()+p+1, vec.end(), d) - vec.begin();
			if(p >= vec.size()){
				chmax(ans, sum);
				break;
			}
			sum += d, d *= 2;
		}
	}
	cout << ans << endl;
	
	return 0;
}