#include <iostream>
#define llint long long

using namespace std;

llint Q;

llint sum(llint x)
{
	return x*(x+1)/2;
}

int main(void)
{
	cin >> Q;
	for(int q = 0; q < Q; q++){
		llint l, r;
		cin >> l >> r;
		llint ans = sum(r/2) - sum((l-1)/2);
		ans -= sum((r+1)/2) - sum(l/2);
		ans *= 2;
		ans += (r+1)/2 - l/2;
		cout << ans << endl;
	}
	return 0;
}