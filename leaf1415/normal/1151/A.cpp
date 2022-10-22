#include <iostream>
#include <string>

using namespace std;

int n;
string s, t = "ACTG";

int dist(char x, char y)
{
	int a = x - 'A', b = y - 'A';
	int d = (x-y+26)%26;
	return min(d, 26-d);
}

int main(void)
{
	cin >> n;
	cin >> s;
	
	int ans = 1e9;
	for(int i = 0; i+3 < n; i++){
		int tmp = 0;
		for(int j = 0; j < 4; j++){
			tmp += dist(s[i+j], t[j]);
		}
		ans = min(ans, tmp);
	}
	cout << ans << endl;
	
	return 0;
}