#include <iostream>
#define llint long long

using namespace std;

llint n, k;

int main(void)
{
	cin >> n >> k;
	
	if(k == 1){
		cout << n << endl;
		return 0;
	}
	
	llint cnt = 0, ans = 0;
	for(; n; n /= 2) cnt++;
	for(int i = 0; i < cnt; i++){
		ans <<= 1;
		ans |= 1;
	}
	cout << ans << endl;
	return 0;
}