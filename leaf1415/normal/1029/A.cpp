#include <iostream>
#include <string>

using namespace std;

int n, k;
string t;

int main(void)
{
	cin >> n >> k;
	cin >> t;
	
	string ans;
	for(int i = 0; ; i++){
		if(k == 0) break;
		if(i >= ans.size()) ans += t, k--;
		else{
			if(ans.substr(i) == t.substr(0, ans.size()-i)){
				ans.erase(ans.begin() + i, ans.end());
				ans += t;
				k--;
			}
		}
	}
	cout << ans << endl;
	return 0;
}