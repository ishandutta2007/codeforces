#include <iostream>
#include <string>
#define llint long long
#define inf 1e18

using namespace std;

llint T;
string s;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	for(int t = 0; t < T; t++){
		cin >> s;
		
		llint l = inf, r = -inf;
		for(llint i = 0; i < s.size(); i++){
			if(s[i] == '1') l = min(l, i), r = max(r, i);
		}
		if(l > inf/2){
			cout << 0 << endl;
			continue;
		}
		llint ans = 0;
		for(int i = l; i <= r; i++){
			if(s[i] == '0') ans++;
		}
		cout << ans << endl;
	}
	
	return 0;
}