#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#define llint long long

using namespace std;

llint n, k;
llint a[200005];
string s;

int main(void)
{
	cin >> n >> k;
	for(int i = 0; i < n; i++) cin >> a[i];
	cin >> s;
	
	llint ans = 0;
	vector<llint> vec;
	char pre = '#';
	
	for(int i = 0; i < n; i++){
		if(pre != s[i]){
			sort(vec.rbegin(), vec.rend());
			for(int j = 0; j < min((llint)vec.size(), k); j++){
				ans += vec[j];
			}
			vec.clear();
			vec.push_back(a[i]);
		}
		else vec.push_back(a[i]);
		pre = s[i];
	}
	sort(vec.rbegin(), vec.rend());
	for(int j = 0; j < min((llint)vec.size(), k); j++){
		ans += vec[j];
	}
	
	cout << ans << endl;
	
	return 0;
}