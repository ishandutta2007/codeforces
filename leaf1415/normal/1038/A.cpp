#include <iostream>
#include <string>

using namespace std;

int n, k;
string s;
int cnt[26];

int main(void)
{
	cin >> n >> k;
	cin >> s;
	
	for(int i = 0; i < s.size(); i++) cnt[s[i]-'A']++;
	
	int ans = n;
	for(int i = 0; i < k; i++) ans = min(ans, cnt[i]);
	ans *= k;
	
	cout << ans << endl;
	return 0;
}