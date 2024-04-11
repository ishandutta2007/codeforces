#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#define llint long long

using namespace std;

llint Q, n;
map<llint, llint> mp;
vector<llint> vec;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> Q;
	for(int q = 0; q < Q; q++){
		mp.clear(), vec.clear();
		
		cin >> n;
		llint a;
		for(int i = 1; i <= 4*n; i++){
			cin >> a;
			mp[a]++;
		}
		bool flag = true;
		for(auto it = mp.begin(); it != mp.end(); it++){
			if(it->second % 2){
				flag = false;
				break;
			}
			for(int i = 0; i < it->second/2; i++) vec.push_back(it->first);
		}
		if(!flag){
			cout << "NO" << "\n";
			continue;
		}
		
		sort(vec.begin(), vec.end());
		
		flag = true;
		llint x = vec.front() * vec.back();
		for(int i = 0; i < n; i++){
			if(vec[i]*vec[2*n-1-i] != x) flag = false;
		}
		if(flag) cout << "YES" << "\n";
		else cout << "NO" << "\n";
	}
	
	return 0;
}