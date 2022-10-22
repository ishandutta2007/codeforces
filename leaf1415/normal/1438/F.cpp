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

llint h;
map<llint, llint> mp;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	srand(time(NULL));
	
	cin >> h;
	
	llint H = 1<<h, res;
	rep(i, 1, 420){
		llint u = rand() % (H-1) + 1;
		llint v = rand() % (H-1) + 1;
		llint w = rand() % (H-1) + 1;
		if(u == v || v == w || w == u){
			i--;
			continue;
		}
		cout << "? " << u << " " << v << " " << w << endl;
		cin >> res;
		mp[res]++;
	}
	
	vector<P> vec;
	for(auto p:mp) vec.push_back(P(p.second, p.first));
	sort(all(vec));
	reverse(all(vec));
	
	llint u = vec[0].second, v = vec[1].second;
	
	rep(i, 1, H-1){
		if(i == u || i == v) continue;
		cout << "? " << u << " " << v << " " << i << endl;
		cin >> res;
		if(res == i){
			cout << "! " << res << endl;
			return 0;
		}
	}
	
	return 0;
}