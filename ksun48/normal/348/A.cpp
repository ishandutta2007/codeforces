#include <iostream>
using namespace std;
typedef long long LL;
int main() {
	int n;
	cin >> n;
	LL a[n];
	LL sum = 0;
	LL m = 0;
	for(int i = 0; i < n; i++){
		cin >> a[i];
		m = max(a[i], m);
		sum += a[i];
	}
	LL ans = m;
	sum += m;
	if(sum <= n*ans){
		cout << ans << endl;
		return 0;
	}
	ans += (n-2+sum-n*ans)/(n-1);
	cout << ans << endl;
	return 0;
}