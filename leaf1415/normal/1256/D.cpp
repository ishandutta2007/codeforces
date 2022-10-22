#include <iostream>
#include <vector>
#define llint long long
#define inf 1e18

using namespace std;

llint Q;
llint n, k;
string s;
vector<llint> vec;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> Q;
	for(int q = 0; q < Q; q++){
		cin >> n >> k;
		cin >> s;
		
		vec.clear();
		llint cnt = 0;
		for(int i = 0; i < s.size(); i++){
			if(s[i] == '0') vec.push_back(cnt);
			else cnt++;
		}
		llint sum = 0;
		for(int i = 0; i < vec.size(); i++) sum += vec[i];
		if(sum <= k){
			for(int i = 0; i < n-cnt; i++) cout << 0;
			for(int i = 0; i < cnt; i++) cout << 1;
			cout << endl;
			continue;
		}
		
		sum = 0;
		for(int i = 0; i < vec.size(); i++){
			sum += vec[i];
			if(sum <= k) cout << 0;
			else{
				//cout << i << " " << sum << endl;
				for(int j = 0; j < sum-k; j++) cout << 1;
				cout << 0;
				for(int j = 0; j < vec[i]-(sum-k); j++) cout << 1;
				for(int j = vec[i]+i+1; j < n; j++) cout << s[j];
				cout << endl;
				break;
			}
		}
	}
	flush(cout);
	
	return 0;
}