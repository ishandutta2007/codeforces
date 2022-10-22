#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;
typedef pair<int, int> P;

int n;
int a[200005];
P A[200005];
vector<int> G[200005];
vector<int> topo;
bool used[200005];
int dp[200005];
int Prev[200005];

void tpsort(int v)
{
	used[v] = true;
	for(int i = 0; i < G[v].size(); i++){
		if(!used[G[v][i]]) tpsort(G[v][i]);
	}
	topo.push_back(v);
}

int main(void)
{
	cin >> n;
	for(int i = 0; i < n; i++) cin >> a[i];
	for(int i = 0; i < n; i++){
		A[i] = make_pair(a[i], i);
	}
	sort(A, A+n);
	
	for(int i = 0; i < n; i++){
		P *p = upper_bound(A, A+n, make_pair(A[i].first+1, A[i].second));
		if(p >= A+n) continue;
		if(p->first != A[i].first+1) continue;
		G[A[i].second].push_back(p->second);
	}
	
	for(int i = 0; i < n; i++){
		if(!used[i]) tpsort(i);
	}
	reverse(topo.begin(), topo.end());
	for(int i = 0; i < n; i++) Prev[i] = -1;
	
	for(int i = 0; i < topo.size(); i++){
		int v = topo[i];
		for(int j = 0; j < G[v].size(); j++){
			if(dp[G[v][j]] < dp[v] + 1){
				dp[G[v][j]] = dp[v] + 1;
				Prev[G[v][j]] = v;
			}
		}
	}
	
	int max_val = -1, max_i;
	for(int i = 0; i < n; i++){
		if(dp[i] > max_val){
			max_val = dp[i];
			max_i = i;
		}
	}
	
	int cur = max_i;
	vector<int> ans;
	ans.push_back(cur);
	
	while(Prev[cur] != -1){
		cur = Prev[cur];
		ans.push_back(cur);
	}
	reverse(ans.begin(), ans.end());
	
	cout << ans.size() << endl;
	for(int i = 0; i < ans.size(); i++){
		 cout << ans[i] + 1 << " ";
	}
	cout << endl;
	
	return 0;
}