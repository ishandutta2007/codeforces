#include <iostream>
#include <string>
#define llint long long

using namespace std;

int n;
string s;

int main(void)
{
	cin >> n;
	cin >> s;
	
	llint ans = 0;
	for(int i = 0; i < n; i++){
		if((s[i] -'0') % 2 == 0){
			ans += i+1;
		}
	}
	cout << ans << endl;
	
	return 0;
}