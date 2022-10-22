#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

#define llint long long

using namespace std;

llint T;
llint n;
llint a[400005];
map<llint, llint> mp;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	for(int t = 0; t < T; t++){
		cin >> n;
		for(int i = 1; i <= n; i++) cin >> a[i];
		
		if(n <= 2){
			cout << 0 << " " << 0 << " " << 0 << "\n";
			continue;
		}
		mp.clear();
		for(int i = 1; i <= n/2; i++){
			if(a[n/2+1] < a[i]) mp[a[i]]++;
		}
		if(mp.size() < 3){
			cout << 0 << " " << 0 << " " << 0 << "\n";
			continue;
		}
		llint sum = 0;
		vector<llint> vec;
		for(auto it = mp.begin(); it != mp.end(); it++){
			sum += it->second;
			vec.push_back(it->second);
		}
		llint g = vec.back();
		sum -= g;
		vec.pop_back();
		
		reverse(vec.begin(), vec.end());
		llint tmp = 0;
		for(int i = 0; i < vec.size(); i++){
			tmp += vec[i];
			if(g < tmp && g < sum-tmp){
				cout << g << " " << tmp << " " << sum-tmp << "\n";
				goto end;
			}
		}
		cout << 0 << " " << 0 << " " << 0 << "\n";
		end:;
	}
	flush(cout);
	
	return 0;
}