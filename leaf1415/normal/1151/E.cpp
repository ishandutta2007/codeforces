#include <iostream>
#define llint long long

using namespace std;

llint n;
llint a[100005];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	
	llint sum = 0, sum2 = 0;
	for(int i = 1; i <= n; i++) sum += a[i] * (n-a[i]+1);
	for(int i = 1; i < n; i++){
		llint m = min(a[i], a[i+1]), M = max(a[i], a[i+1]);
		sum2 += m * (n-M+1);
	}
	cout << sum - sum2<< endl;
	return 0;
}