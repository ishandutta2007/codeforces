#include <iostream>
#include <string>

using namespace std;

int n;
string s;

int main(void)
{
	cin >> n;
	cin >> s;
	s += "a";
	
	int ans = 0, cnt = 0;
	for(int i = 0; i <= n; i++){
		if(s[i] == 'x') cnt++;
		else{
			ans += max(0, cnt-2);
			cnt = 0;
		}
	}
	cout << ans << endl;
	return 0;
}