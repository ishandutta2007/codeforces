#include <iostream>
#include <algorithm>
#include <utility>
#include <set>
#include <vector>
#define llint long long

using namespace std;
typedef pair<llint, llint> P;


llint T;
llint n, m;
vector<llint> ans;
bool used[300005];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	for(int t = 0; t < T; t++){
		cin >> n >> m;
		for(int i = 1; i <= 3*n; i++) used[i] = false;
		ans.clear();
		
		llint u, v;
		for(int i = 1; i <= m; i++){
			cin >> u >> v;
			if(!used[u] && !used[v] && ans.size() < n){
				ans.push_back(i);
				used[u] = used[v] = true;
			}
		}
		if(ans.size() >= n){
			cout << "Matching" << endl;
			for(int i = 0; i < ans.size(); i++) cout << ans[i] << " "; cout << endl;
		}
		else{
			cout << "IndSet" << endl;
			int cnt = 0;
			for(int i = 1; i <= 3*n; i++){
				if(!used[i] && cnt < n) cnt++, cout << i << " ";
			}
			cout << endl;
		}
	}
	
	return 0;
}