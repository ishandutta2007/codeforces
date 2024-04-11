#include <iostream>
#include <utility>
#include <stack>
#include <vector>
#include <map>
#include <algorithm>
#define llint long long
#define inf 1e18

using namespace std;
typedef pair<llint, llint> P;

llint n, m, s;
llint l[100005], r[100005];
vector<llint> comp;
llint dp[1<<8], dp2[100005][1<<8];
vector<int> llvec[200005], rrvec[200005];
vector<int> lvec[200005], rvec[200005];
bool used[8];
map<int, int> mp;
llint pop[1<<8];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m >> s;
	for(int i = 1; i <= n; i++){
		cin >> l[i] >> r[i];
		r[i]++;
		comp.push_back(l[i]);
		comp.push_back(r[i]);
	}
	sort(comp.begin(), comp.end());
	comp.erase(unique(comp.begin(), comp.end()), comp.end());
	for(int i = 1; i <= n; i++){
		l[i] = lower_bound(comp.begin(), comp.end(), l[i]) - comp.begin();
		r[i] = lower_bound(comp.begin(), comp.end(), r[i]) - comp.begin();
	}
	llint N = comp.size();
	
	for(int i = 1; i <= n; i++){
		llvec[l[i]].push_back(i);
		rrvec[r[i]].push_back(i);
	}
	
	for(int i = 0; i < N; i++){
		for(int j = 0; j < rrvec[i].size(); j++){
			llint id = rrvec[i][j], occ = mp[id];
			rvec[i].push_back(occ);
			mp.erase(id);
			used[occ] = false;
		}
		for(int j = 0; j < llvec[i].size(); j++){
			llint id = llvec[i][j], free;
			for(int k = 0; k < 8; k++){
				if(!used[k]){
					free = k;
					break;
				}
			}
			lvec[i].push_back(free);
			used[free] = true;
			mp[id] = free;
		}
	}
	
	/*for(int i = 0; i < N; i++) cout << comp[i] << " "; cout << endl;
	for(int i = 0; i < N; i++){
		cout << i << "L : ";
		for(int j = 0; j < lvec[i].size(); j++) cout << lvec[i][j] << " "; cout << endl;
		cout << i << "R : ";
		for(int j = 0; j < rvec[i].size(); j++) cout << rvec[i][j] << " "; cout << endl;
	}*/
	
	llint S = 1<<s, pre = 1;
	for(int i = 1; i < S; i++) pop[i] = (pop[i&(i-1)] + 1) % 2;
	
	for(int j = 0; j < S; j++) dp[j] = -inf;
	dp[0] = 0;
	
	for(int i = 0; i < N; i++){
		for(int j = 0; j < S; j++){
			if(pop[j]) dp[j] += comp[i] - pre;
		}
		pre = comp[i];
		
		/*for(int j = 0; j < S; j++){
			if(dp[j] < 0) cout << "x" << " ";
			else cout << dp[j] << " ";
		}cout << endl;*/
		
		llint L = lvec[i].size(), R = rvec[i].size();
		for(int j = 0; j <= R; j++){
			for(int k = 0; k < S; k++){
				dp2[j][k] = -inf;
			}
		}
		for(int j = 0; j < S; j++) dp2[0][j] = dp[j];
		for(int j = 0; j < R; j++){
			llint id = rvec[i][j];
			for(int k = 0; k < S; k++){
				if(k & (1<<id)) dp2[j+1][k&~(1<<id)] = max(dp2[j+1][k&~(1<<id)], dp2[j][k]);
				else dp2[j+1][k] = max(dp2[j+1][k], dp2[j][k]);
			}
		}
		/*for(int j = 0; j < S; j++){
			if(dp2[R][j] < 0) cout << "x" << " ";
			else cout << dp2[R][j] << " ";
		}cout << endl;*/
		
	
		for(int j = 0; j < S; j++) dp2[0][j] = dp2[R][j];
		for(int j = 1; j <= L; j++){
			for(int k = 0; k < S; k++){
				dp2[j][k] = -inf;
			}
		}
		
		for(int j = 0; j < L; j++){
			llint id = lvec[i][j];
			for(int k = 0; k < S; k++){
				dp2[j+1][k|(1<<id)] = max(dp2[j+1][k|(1<<id)], dp2[j][k]);
				dp2[j+1][k] = max(dp2[j+1][k], dp2[j][k]);
			}
		}
		/*for(int j = 0; j < S; j++){
			if(dp2[L][j] < 0) cout << "x" << " ";
			else cout << dp2[L][j] << " ";
		}cout << endl;*/
		
		for(int j = 0; j < S; j++) dp[j] = dp2[L][j];
	}
	
	/*for(int j = 0; j < S; j++){
		if(dp[j] < 0) cout << "x" << " ";
		else cout << dp[j] << " ";
	}cout << endl;*/
	
	llint ans = 0;
	for(int j = 0; j < S; j++){
		if(pop[j]) dp[j] += m+1-pre;
		ans = max(ans, dp[j]);
	}
	cout << ans << endl;
	
	return 0;
}