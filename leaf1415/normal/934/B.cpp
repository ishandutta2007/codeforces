#include <iostream>
#include <string>

using namespace std;

int k;

int main(void)
{
	cin >> k;
	if(k > 36){
		cout << -1 << endl;
		return 0;
	}
	
	string ans;
	for(int i = 0; i < k/2; i++) ans += "8";
	if(k%2) ans += "4";
	
	cout << ans << endl;
	return 0;
}