#include <iostream>
#include <vector>
#include <utility>
#define llint long long

using namespace std;
typedef pair<llint, llint> P;

llint h, w;
llint a[55][55], b[55][55];
vector<P> ans;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> h >> w;
	for(int i = 1; i <= h; i++){
		for(int j = 1; j <= w; j++){
			cin >> a[i][j];
		}
	}
	for(int i = 1; i <= h-1; i++){
		for(int j = 1; j <= w-1; j++){
			if(a[i][j] && a[i+1][j] && a[i][j+1] && a[i+1][j+1]){
				b[i][j] = b[i+1][j] = b[i][j+1] = b[i+1][j+1] = 1;
				ans.push_back(make_pair(i, j));
			}
		}
	}
	for(int i = 1; i <= h; i++){
		for(int j = 1; j <= w; j++){
			if(a[i][j] != b[i][j]){
				cout << -1 << endl;
				return 0;
			}
		}
	}
	
	cout << ans.size() << endl;
	for(int i = 0; i < ans.size(); i++) cout << ans[i].first << " " << ans[i].second << "\n";
	flush(cout);
	
	return 0;
}