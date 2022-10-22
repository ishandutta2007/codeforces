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

llint T;
llint n;
llint a[300005];
vector<llint> vec[300005];
llint b[300005];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	for(int t = 0; t < T; t++){
		cin >> n;
		for(int i = 1; i <= n; i++){
			cin >> a[i];
			vec[i].clear();
			vec[i].push_back(0);
			vec[i].push_back(n+1);
		}
		for(int i = 1; i <= n; i++) vec[a[i]].push_back(i);
		
		for(int i = 1; i <= n; i++) b[i] = inf;
		for(llint i = 1; i <= n; i++){
			sort(vec[i].begin(), vec[i].end());
			llint mx = 0;
			for(int j = 1; j < vec[i].size(); j++){
				mx = max(mx, vec[i][j]-vec[i][j-1]);
			}
			chmin(b[mx], i);
		}
		for(int i = 2; i <= n; i++) chmin(b[i], b[i-1]);
		for(int i = 1; i <= n; i++){
			if(b[i] > inf/2) b[i] = -1;
			cout << b[i] << " ";
		}
		cout << endl;
	}
	
	return 0;
}