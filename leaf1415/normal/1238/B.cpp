#include <iostream>
#include <algorithm>
#include <vector>
#define llint long long

using namespace std;

llint Q;
llint n, r;
vector<llint> vec;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> Q;
	for(int q = 0; q < Q; q++){
		cin >> n >> r;
		llint x;
		vec.clear();
		for(int i = 1; i <= n; i++){
			cin >> x;
			vec.push_back(x);
		}
		sort(vec.begin(), vec.end());
		vec.erase(unique(vec.begin(), vec.end()), vec.end());
		
		int ans = vec.size();
		for(int i = 0; i < vec.size(); i++){
			if(vec[(int)vec.size()-1-i] <= r*i){
				ans = i;
				break;
			}
		}
		cout << ans << "\n";
	}
	flush(cout);
	
	return 0;
}