#include <iostream>
#include <algorithm>
#include <map>
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
	for(int z = 0; z < Q; z++){
		cin >> n;
		vec.clear();
		for(llint t = n; t; t/=3) vec.push_back(t%3);
		vec.push_back(0);
		
		llint p = -1;
		for(int i = 0; i < vec.size(); i++){
			if(vec[i] == 2) p = i;
		}
		if(p == -1){
			cout << n << "\n";
			continue;
		}
		llint q;
		for(int i = p; i < vec.size(); i++){
			if(vec[i] == 0){
				q = i;
				break;
			}
		}
		vec[q] = 1;
		for(int i = q-1; i >= 0; i--) vec[i] = 0;
		
		llint ans = 0, mul = 1;
		for(int i = 0; i < vec.size(); i++){
			ans += vec[i] * mul;
			mul *= 3;
		}
		cout << ans << "\n";
	}
	flush(cout);
	
	return 0;
}