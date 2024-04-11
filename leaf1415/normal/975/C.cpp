#include <iostream>
#include <algorithm>
#define llint long long

using namespace std;

llint n, q;
llint a[200005], asum[200005];
llint k[200005];

int main(void)
{
	cin >> n >> q;
	for(int i = 0; i < n; i++) cin >> a[i];
	for(int i = 0; i < q; i++) cin >> k[i];
	
	llint sum = 0;
	for(int i = 0; i < n; i++){
		sum += a[i];
		asum[i] = sum;
	}
	
	sum = 0;
	for(int i = 0; i < q; i++){
		sum += k[i];
		llint p = upper_bound(asum, asum+n, sum) - asum;
		if(p == n){
			p = 0;
			sum = 0;
		}
		cout << n - p << endl;
	}
	
	return 0;
}