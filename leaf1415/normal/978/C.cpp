#include <iostream>
#include <algorithm>
#define llint long long

using namespace std;

llint n, m;
llint a[200005];
llint sum[200005];

int main(void)
{
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 1; i <= n; i++){
		sum[i] = sum[i-1] + a[i];
	}
	
	llint b;
	for(int i = 0; i < m; i++){
		cin >> b;
		llint *p = lower_bound(sum, sum+n+1, b);
		llint f = p - sum, k = b - *(p-1);
		cout << f << " " << k << endl;
	}
	return 0;
}