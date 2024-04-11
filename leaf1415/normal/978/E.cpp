#include <iostream>
#define llint long long 

using namespace std;

llint n, w;
llint a[1005];

int main(void)
{
	cin >> n >> w;
	for(int i = 1; i <= n; i++) cin >> a[i];
	
	llint pmax = 0, pmin = 0, sum = 0;
	for(int i = 1; i <= n; i++){
		sum += a[i];
		pmax = max(pmax, sum);
		pmin = min(pmin, sum);
	}
	
	cout << max(0LL, w - (pmax-pmin) + 1) << endl;
	return 0;
}