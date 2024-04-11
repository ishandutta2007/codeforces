#include <iostream>
#include <vector>

using namespace std;

int n, m;
int s[105], d[105], c[105];
int test[105];
int pre[105];
vector<int> ans;

int main(void)
{
	cin >> n >> m;
	for(int i = 1; i <= m; i++){
		cin >> s[i] >> d[i] >> c[i];
		test[d[i]] = i;
	}
	
	for(int i = 1; i <= n; i++){
		if(test[i]){
			if(pre[test[i]] < c[test[i]]){
				cout << -1 << endl;
				return 0;
			}
			ans.push_back(m+1);
			continue;
		}
		int min_j = -1, min_val = n+1;
		for(int j = 1; j <= m; j++){
			if(i >= s[j] && i < d[j] && pre[j] < c[j]){
				if(min_val > d[j]){
					min_val = d[j];
					min_j = j;
				}
			}
		}
		if(min_j == -1) ans.push_back(0);
		else{
			ans.push_back(min_j);
			pre[min_j]++;
		}
	}
	
	for(int i = 0; i < ans.size(); i++) cout << ans[i] << " "; cout << endl;
	return 0;
}