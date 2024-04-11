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
llint a[505], b[505];
vector<llint> vec[2];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	for(int t = 0; t < T; t++){
		cin >> n;
		for(int i = 1; i <= n; i++) cin >> a[i];
		for(int i = 1; i <= n; i++) cin >> b[i];
		
		vec[0].clear(), vec[1].clear();
		for(int i = 1; i <= n; i++){
			vec[b[i]].push_back(a[i]);
		}
		if(vec[0].size() && vec[1].size()){
			cout << "Yes" << endl;
			continue;
		}
		for(int i = 0; i < 2; i++){
			for(int j = 1; j < vec[i].size(); j++){
				if(vec[i][j-1] > vec[i][j]){
					cout << "No" << endl;
					goto end;
				}
			}
		}
		cout << "Yes" << endl;
		end:;
	}
	
	return 0;
}