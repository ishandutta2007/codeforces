#include <iostream>
#include <stdio.h>
#include <algorithm>
#define llint long long

using namespace std;

llint n, k, m;
llint a[100005];

int main(void)
{
	cin >> n >> k >> m;
	for(int i = 0; i < n; i++) cin >> a[i];
	sort(a, a+n);
	reverse(a, a+n);
	
	llint sum = 0;
	double ans = 0;
	for(int i = 1; i <= n; i++){
		sum += a[i-1];
		if(n-i > m) continue;
		double tmp = sum + min(m-(n-i), i*k);
		ans = max(ans, tmp / i);
	}
	printf("%.11f\n", ans);
	
	return 0;
}