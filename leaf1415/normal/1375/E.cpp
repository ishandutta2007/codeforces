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

llint n;
llint a[1005], b[1005], pos[1005];
P p[1005];
vector<P> vec;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	
	for(int i = 1; i <= n; i++) p[i] = P(a[i], i);
	sort(p+1, p+n+1);
	
	for(int i = 1; i <= n; i++) b[p[i].second] = i;
	for(int i = 1; i <= n; i++) pos[b[i]] = i;
	
	vec.clear();
	for(int i = n; i >= 1; i--){
		for(int j = b[i]+1; j <= n; j++){
			if(pos[j] < i) vec.push_back(P(pos[j], i));
		}
	}
	
	cout << vec.size() << endl;
	for(int i = 0; i < vec.size(); i++){
		cout << vec[i].first << " " << vec[i].second << endl;
	}
	
	return 0;
}