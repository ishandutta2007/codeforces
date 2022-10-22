#include <iostream>
#include <vector>
#define llint long long

using namespace std;

llint T;
llint n;
llint p[1000005];
bool used[1000005];
vector<llint> ans;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	for(int t = 0; t < T; t++){
		cin >> n;
		for(int i = 1; i <= n; i++){
			cin >> p[i];
			p[i] = i - p[i];
		}
		llint v = 1;
		for(int i = 1; i <= n; i++) used[i] = false;
		do{
			used[v] = true;
			v = p[v];
		}while(!used[v]);
		
		ans.clear();
		for(int i = 1; i <= n; i++) used[i] = false;
		do{
			ans.push_back(v);
			used[v] = true;
			v = p[v];
		}while(!used[v]);
		
		cout << ans.size() << "\n";
		for(int i = 0; i < ans.size(); i++) cout << ans[i] << " ";
		cout << "\n";
	}
	flush(cout);
	
	return 0;
}