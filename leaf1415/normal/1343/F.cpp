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
vector<llint> vec[205], ivec[205], ans;
bool used[205], valid[205];
llint cnt[205], cnt2[205];
llint pinv[205];

void dfs(llint x, llint b)
{
	for(int i = 1; i <= n; i++) cnt2[i] = 0;
	for(int i = 1; i <= n-1; i++){
		if(used[i]) continue;
		if(x == n-1){
			for(int j = 0; j < vec[i].size(); j++) ans.push_back(vec[i][j]);
			return;
		}
		for(int j = 0; j < vec[i].size(); j++) cnt2[vec[i][j]]++;
	}
	
	//cout << x << endl;
	//for(int i = 1; i <= n; i++) cout << cnt2[i] << " "; cout << endl;
	
	for(int i = 1; i <= n; i++){
		if(!valid[i]) continue;
		
		if(cnt2[i] == 1 && i != b){
			ans.push_back(i);
			llint rid;
			for(int j = 0; j < ivec[i].size(); j++){
				if(!used[ivec[i][j]]){
					rid = ivec[i][j];
					break;
				}
			}
			used[rid] = true;
			for(int j = 1; j <= n; j++) valid[j] = false;
			for(int j = 0; j < vec[rid].size(); j++) valid[vec[rid][j]] = true;
			
			dfs(x+1, b);
		}
	}
}

bool check()
{
	//for(int i = 0; i < ans.size(); i++) cout << ans[i] << " ";  cout << "\n";
	
	if(ans.size() != n) return false;
	for(int i = 1; i <= n; i++) cnt2[i] = 0;
	for(int i = 0; i < ans.size(); i++) pinv[ans[i]] = i+1;
	
	for(int i = 1; i <= n-1; i++){
		llint mx = 0, mn = inf;
		for(int j = 0; j < vec[i].size(); j++){
			mx = max(mx, pinv[vec[i][j]]);
			mn = min(mn, pinv[vec[i][j]]);
		}
		cnt2[mx]++;
		//cout << mx << " " << mn << " " << (int)vec[i].size() << endl;
		if(mx-mn+1 != (int)vec[i].size()) return false;
	}
	for(int i = 2; i <= n; i++){
		if(cnt2[i] >= 2) return false;
	}
	return true;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	for(int t = 0; t < T; t++){
		cin >> n;
		
		llint k, x;
		for(int i = 1; i <= n; i++) ivec[i].clear();
		for(int i = 1; i <= n-1; i++){
			vec[i].clear();
			cin >> k;
			for(int j = 0; j < k; j++){
				cin >> x;
				vec[i].push_back(x);
				ivec[x].push_back(i);
			}
		}
		
		if(n == 2){
			cout << 1 << " " << 2 << endl;
			continue;
		}
		
		for(int i = 1; i <= n; i++) cnt[i] = 0;
		for(int i = 1; i <= n-1; i++){
			for(int j = 0; j < vec[i].size(); j++) cnt[vec[i][j]]++;
		}
		
		for(int i = 1; i <= n; i++){
			if(cnt[i] == 1){
				for(int b = 1; b <= n; b++){
					if(i == b) continue;
					ans.clear();
					ans.push_back(i);
					for(int j = 1; j <= n; j++) valid[j] = used[j] = false;
					llint rid = ivec[i][0];
					used[rid] = true;
					for(int j = 0; j < vec[rid].size(); j++) valid[vec[rid][j]] = true;
					dfs(2, b);
					if(ans.size() != n) continue;
					if(ans.back() != b) swap(ans[n-2], ans[n-1]);
					reverse(ans.begin(), ans.end());
					
					if(check()) goto end;
				}
			}
		}
		
		end:;
		for(int i = 0; i < ans.size(); i++) cout << ans[i] << " ";  cout << "\n";
	}
	flush(cout);
	return 0;
}