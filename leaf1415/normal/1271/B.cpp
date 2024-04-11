#include <iostream>
#include <string>
#include <vector>
#define llint long long

using namespace std;

llint n;
string s;
vector<llint> ans;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> s;
	
	llint sum = 0;
	for(int i = 0; i < n; i++){
		if(s[i] == 'B') sum++;
	}
	if(n % 2 == 0 && sum % 2){
		cout << -1 << endl;
		return 0;
	}
	
	char c = 'W';
	if(n % 2 && sum % 2) c = 'B';
	for(int i = 0; i < n-1; i++){
		if(s[i] != c){
			s[i] = c;
			if(s[i+1] == 'B') s[i+1] = 'W';
			else s[i+1] = 'B';
			ans.push_back(i+1);
		}
	}
	cout << ans.size() << endl;
	for(int i = 0; i < ans.size(); i++) cout << ans[i] << " "; cout << endl;
	
	return 0;
}