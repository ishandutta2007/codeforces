#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <stdlib.h>
#include <utility>
#include <cassert>
#define llint long long
#define inf 1e18

using namespace std;
typedef pair<llint, llint> P;

llint k;
llint n[20], s[20];
vector<llint> vec[20];
map<llint, P> mp;
P succ[20][5005];
llint used[20][5005];
P path[1<<15];
llint dp[1<<15];
P ans[20];

void calc(llint x)
{
	llint p = path[x].first, q = path[x].second;
	llint sp = p, sq = q;
	do{
		llint np = succ[p][q].first, nq = succ[p][q].second;
		ans[p].first = vec[p][q];
		ans[np].second = p+1;
		p = np, q = nq;
	}while(P(p, q) != P(sp, sq));
}

void dfs(int x)
{
	if(path[x].first != -1){
		calc(x);
		return;
	}
	dfs(dp[x]);
	dfs(x-dp[x]);
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> k;
	llint sum = 0, x;
	for(int i = 0; i < k; i++){
		cin >> n[i];
		for(int j = 0; j < n[i]; j++){
			cin >> x;
			sum += x, s[i] += x;
			vec[i].push_back(x);
			mp[x] = P(i, j);
		}
	}
	
	if(abs(sum) % k){
		cout << "No" << endl;
		return 0;
	}
	sum /= k;
	
	//cout << sum << endl;
	
	for(int i = 0; i < k; i++){
		for(int j = 0; j < n[i]; j++){
			llint x = vec[i][j];
			x += sum - s[i];
			if(mp.count(x) == 0) succ[i][j] = P(-1, -1);
			else succ[i][j] = mp[x];
		}
	}
	
	/*for(int i = 0; i < k; i++){
		for(int j = 0; j < n[i]; j++){
			cout << succ[i][j].first << " " << succ[i][j].second << " , ";
		}
		cout << endl;
	}*/
	
	int K = 1<<k;
	for(int i = 0; i < K; i++){
		path[i] = P(-1, -1);
	}
	
	llint id = 0;
	for(int i = 0; i < k; i++){
		for(int j = 0; j < n[i]; j++){
			if(used[i][j]) continue;
			
			id++;
			llint p = i, q = j; bool flag = true;
			do{
				if(used[p][q] && used[p][q] < id){
					flag = false;
					break;
				}
				used[p][q] = id;
				if(succ[p][q].first == -1 || (succ[p][q].first == p && succ[p][q].second != q)){
					flag = false;
					break;
				}
				llint np = succ[p][q].first, nq = succ[p][q].second;
				p = np, q = nq;
				assert(p != -1 && q != -1);
			}while(used[p][q] != id);
			
			if(!flag) continue;
			//cout << p << " " << q << endl;
			
			llint visit = 0, sp = p, sq = q;
			flag = true;
			do{
				if(visit & (1<<p)){
					flag = false;
					break;
				}
				visit |= 1<<p;
				llint np = succ[p][q].first, nq = succ[p][q].second;
				p = np, q = nq;
			}while(P(p, q) != P(sp, sq));
			
			if(flag) path[visit] = P(sp, sq);
		}
	}
	
	for(int i = 0; i < K; i++) dp[i] = -1;
	for(int i = 0; i < K; i++){
		if(path[i].first != -1){
			dp[i] = i;
			continue;
		}
		for(int j = i; j > 0; j = (j-1)&i){
			if(dp[j] != -1 && dp[i-j] != -1){
				dp[i] = j;
				break;
			}
		}
	}
	if(dp[K-1] == -1){
		cout << "No" << endl;
		return 0;
	}
	dfs(K-1);
	
	cout << "Yes" << endl;
	for(int i = 0; i < k; i++){
		cout << ans[i].first << " " << ans[i].second << endl;
	}
	
	return 0;
}