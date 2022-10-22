#include <iostream>
#include <string>
#include <algorithm>

#define llint long long
#define inf 1000000000000000000

using namespace std;

llint T;
llint n;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	for(int t = 0; t < T; t++){
		cin >> n;
		
		string ans;
		for(llint i = 45000; i >= 1; i--){
			if(i == 1 && n == 2){
				ans += "11";
				n = 0;
			}
			else if(n >= i*(i+1)/2){
				n -= i*(i+1)/2;
				ans += "1";
			}
			ans += "3";
		}
		ans += "37";
		cout << ans << endl;
	}
	
	return 0;
}