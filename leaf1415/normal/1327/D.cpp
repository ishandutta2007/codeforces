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
#define llint long long
#define inf 1e18
#define rep(x, s, t) for(llint (x) = (s); (x) < (t); (x)++)
#define Rep(x, s, t) for(llint (x) = (s); (x) <= (t); (x)++)

using namespace std;

llint T;
llint n;
llint p[200005], c[200005];
vector<int> vec[200005];
bool used[200005];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	for(int i = 1; i < 200005; i++){
		for(int j = i; j < 200005; j+=i){
			vec[j].push_back(i);
		}
	}
	
	cin >> T;
	for(int t = 0; t < T; t++){
		cin >> n;
		for(int i = 1; i <= n; i++) cin >> p[i];
		for(int i = 1; i <= n; i++) cin >> c[i];
		for(int i = 1; i <= n; i++) used[i] = false;
		
		llint ans = inf;
		vector<int> tmp;
		for(int i = 1; i <= n; i++){
			if(used[i]) continue;
			
			tmp.clear();
			int v = i;
			do{
				used[v] = true;
				tmp.push_back(v);
				v = p[v];
			}while(!used[v]);
			
			llint m = tmp.size();
			for(int j = 0; j < vec[m].size(); j++){
				llint d = vec[m][j];
				for(int k = 0; k < d; k++){
					bool flag = true;
					for(int l = k; l < m; l+=d){
						if(c[tmp[k]] != c[tmp[l]]){
							flag = false;
							break;
						}
					}
					if(flag){
						ans = min(ans, d);
						goto end;
					}
				}
			}
			end:;
		}
		cout << ans << "\n";
	}
	flush(cout);
	
	return 0;
}