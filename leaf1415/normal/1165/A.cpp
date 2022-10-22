#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int n, x, y;
string s;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> x >> y;
	cin >> s;
	reverse(s.begin(), s.end());
	
	int ans = 0;
	for(int i = 0; i < x; i++){
		if(i != y && s[i] == '1') ans++;
		if(i == y && s[i] == '0') ans++;
	}
	cout << ans << endl;
	
	return 0;
}