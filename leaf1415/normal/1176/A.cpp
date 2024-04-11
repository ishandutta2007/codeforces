#include <iostream>
#define llint long long

using namespace std;

llint Q;

int main(void)
{
	cin >> Q;
	llint n;
	for(int q = 0; q < Q; q++){
		cin >> n;
		llint cnt2 = 0, cnt3 = 0, cnt5 = 0;
		while(n%2==0) cnt2++, n/=2;
		while(n%3==0) cnt3++, n/=3;
		while(n%5==0) cnt5++, n/=5;
		if(n > 1){
			cout << -1 << endl;
			continue;
		}
		llint ans = cnt2 + cnt3*2 + cnt5*3;
		cout << ans << endl;
	}
	return 0;
}