#include <iostream>
#include <string>

using namespace std;


int n;
string s, ans;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	cin >> s;
	
	for(int i = 0; i < s.size(); i++){
		if(ans.size() % 2 && ans[ans.size()-1] == s[i]) continue;
		ans += s[i];
	}
	if(ans.size()%2) ans.erase(ans.end()-1);
	
	cout << n - ans.size() << endl;
	cout << ans << endl;
	
	return 0;
}