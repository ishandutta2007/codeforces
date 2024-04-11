#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int n;
int d[305];
vector<pair<int, int> > ans;

int main(void)
{
	cin >> n;
	for(int i = 0; i < n; i++) cin >> d[i];
	
	int r = n-1, v = d[n-1] + 1;
	while(1){
		for(int i = 1; i <= d[r]; i++){
			ans.push_back(make_pair(i, v));
		}
		for(int i = 0; i <= r; i++) d[i]--;
		for(int i = 0; i <= r; i++){
			if(d[i] == 0) r--;
			v = d[r]+1;
		}
		if(d[r] <= 0) break;
	}
	
	cout << ans.size() << endl;
	for(int i = 0; i < ans.size(); i++){
		cout << ans[i].first << " " << ans[i].second << endl;
	}
	
	return 0;
}