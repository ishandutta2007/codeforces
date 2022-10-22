#include <iostream>
#include <algorithm>
#include <vector>
#define llint long long

using namespace std;

llint Q;
llint n;
vector<llint> vec;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> Q;
	for(int q = 0; q < Q; q++){
		cin >> n;
		llint a;
		vec.clear();
		for(int i = 0; i < n; i++){
			cin >> a;
			vec.push_back(a);
		}
		sort(vec.rbegin(), vec.rend());
		vec.erase(unique(vec.begin(), vec.end()), vec.end());
		
		llint x = vec[0], y = 0, z = 0, i = 1;
		for(i = 1; i < vec.size(); i++){
			if(x % vec[i]){
				y = vec[i];
				i++;
				break;
			}
		}
		for(; i < vec.size(); i++){
			if(x % vec[i] && y % vec[i]){
				z = vec[i];
				i++;
				break;
			}
		}
		llint ans = x + y + z;
		
		if(vec.size() >= 4){
			if(vec[0] % 30 == 0 && vec[1] == vec[0]/2 && vec[2] == vec[0]/3 && vec[3] == vec[0]/5){
				ans = max(ans, vec[1] + vec[2] + vec[3]);
			}
		}
		cout << ans << "\n";
	}
	flush(cout);
	
	return 0;
}