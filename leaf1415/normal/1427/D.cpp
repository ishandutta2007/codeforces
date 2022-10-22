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
llint c[55];
vector<vector<llint> > ans;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> c[i];
	
	while(1){
		bool flag = false;
		vector<llint> vec;
		for(int i = 1; i <= n; i++){
			llint l = i, r = i;
			for(int j = i+1; j <= n; j++){
				if(c[j] != c[j-1] + 1) break;
				r = j;
			}
			
			llint r2 = -1;
			for(int j = r+1; j <= n; j++){
				if(c[j] == c[l]-1){
					r2 = j;
					break;
				}
			}
			if(r2 == -1) continue;
			
			llint l2 = r2;
			for(int j = r2-1; j > r; j--){
				if(c[j] != c[j+1] - 1) break;
				l2 = j;
			}
			
			flag = true;
			if(l >= 2) vec.push_back(l-1);
			vec.push_back(r-l+1);
			vec.push_back(r2-r);
			if(r2 < n) vec.push_back(n-r2);
			break;
		}
		if(!flag) break;
		
		ans.push_back(vec);
		
		vector<llint> tmp;
		llint l = n+1;
		for(int i = (int)vec.size()-1; i >= 0; i--){
			l -= vec[i];
			for(int j = 0; j < vec[i]; j++) tmp.push_back(c[l+j]);
		}
		for(int i = 0; i < tmp.size(); i++) c[i+1] = tmp[i];
	}
	
	cout << ans.size() << endl;
	for(int i = 0; i < ans.size(); i++){
		cout << ans[i].size() << " ";
		for(int j = 0; j < ans[i].size(); j++) cout << ans[i][j] << " ";
		cout << endl;
	}
	
	return 0;
}