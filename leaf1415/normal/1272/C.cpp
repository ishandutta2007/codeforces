#include <iostream>
#include <cstdlib>
#include <string>
#define llint long long

using namespace std;

llint n, k;
string s;
bool can[26];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> k;
	cin >> s;
	char c;
	for(int i = 0; i < k; i++){
		cin >> c;
		can[c-'a'] = true;
	}
	
	llint ans = 0, cnt = 0;
	for(int i = 0; i < s.size(); i++){
		if(can[s[i]-'a']) cnt++;
		else{
			ans +=cnt*(cnt+1)/2;
			cnt = 0;
		}
	}
	ans +=cnt*(cnt+1)/2;
	cout << ans << endl;
	
	return 0;
}