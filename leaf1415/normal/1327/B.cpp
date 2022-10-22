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
vector<llint> G[100005];
bool match[100005];
bool used[100005];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	for(int t = 0; t < T; t++){
		cin >> n;
		
		llint k, x;
		for(int i = 1; i <= n; i++){
			cin >> k;
			G[i].clear();
			for(int j = 0; j < k; j++){
				cin >> x;
				G[i].push_back(x);
			}
			sort(G[i].begin(), G[i].end());
		}
		for(int i = 1; i <= n; i++) match[i] = used[i] = false;
		
		for(int i = 1; i <= n; i++){
			bool flag = false;
			for(int j = 0; j < G[i].size(); j++){
				if(used[G[i][j]]) continue;
				flag = true;
				used[G[i][j]] = true;
				break;
			}
			match[i] = flag;
		}
		for(int i = 1; i <= n; i++){
			if(match[i]) continue;
			for(int j = 1; j <= n; j++){
				if(used[j]) continue;
				cout << "IMPROVE" << "\n";
				cout << i << " " << j << "\n";
				goto end;
			}
		}
		cout << "OPTIMAL" << "\n";
		end:;
	}
	flush(cout);
	
	return 0;
}