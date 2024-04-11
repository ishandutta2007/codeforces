#include <iostream>
#include <algorithm>
#define llint long long

using namespace std;

llint n;
llint a[300005];
llint m;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	sort(a+1, a+n+1);
	reverse(a+1, a+n+1);
	
	llint sum = 0;
	for(int i = 1; i <= n; i++) sum += a[i];
	
	cin >> m;
	for(int i = 1; i <= m; i++){
		llint q;
		cin >> q;
		cout << sum - a[q] << "\n";
	}
	flush(cout);
	
	return 0;
}