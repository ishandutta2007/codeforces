#include <iostream>
#include <algorithm>
#include <vector>
#define llint long long

using namespace std;

llint Q;
llint h, n;
vector<llint> vec;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> Q;
	for(int q = 0; q < Q; q++){
		cin >> h >> n;
		vec.clear();
		llint x;
		for(int i = 0; i < n; i++){
			cin >> x;
			if(i > 0) vec.push_back(x);
		}
		vec.push_back(0);
		llint ans = 0;
		for(int i = 0; i < (int)vec.size()-1; i++){
			if(vec[i+1] == vec[i]-1) i++;
			else ans++;
		}
		cout << ans << "\n";
	}
	flush(cout);
	
	return 0;
}