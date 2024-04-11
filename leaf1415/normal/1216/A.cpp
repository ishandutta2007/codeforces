#include <iostream>
#include <string>

using namespace std;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	string s, ans;
	cin >> n >> s;
	
	int cnt = 0;
	for(int i = 0; i < n; i+=2){
		if(s[i] == s[i+1]){
			cnt++;
			ans += "ab";
		}
		else{
			ans.push_back(s[i]);
			ans.push_back(s[i+1]);
		}
	}
	cout << cnt << endl;
	cout << ans << endl;
	
	return 0;
}