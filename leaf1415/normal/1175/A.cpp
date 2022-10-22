#include <iostream>
#define llint long long

using namespace std;

llint T;
llint n, k;

int main(void)
{
	cin >> T;
	for(int t = 0; t < T; t++){
		cin >> n >> k;
		llint ans = 0;
		while(n){
			if(n % k == 0) n /= k, ans++;
			else{
				ans += n % k;
				n -= n % k;
			}
		}
		cout << ans << endl;
	}
	return 0;
}