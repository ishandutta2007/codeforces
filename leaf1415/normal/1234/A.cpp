#include <iostream>
#define llint long long

using namespace std;

llint Q;
llint n;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> Q;
	for(int q = 0; q < Q; q++){
		cin >> n;
		llint a, sum = 0;
		for(int i = 1; i <= n; i++) cin >> a, sum += a;
		cout << (sum+n-1) / n << "\n";
	}
	flush(cout);
	
	return 0;
}