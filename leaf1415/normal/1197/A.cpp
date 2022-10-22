#include <iostream>
#include <algorithm>

using namespace std;

int T;
int n;
int a[100005];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	for(int t = 0; t < T; t++){
		cin >> n;
		for(int i = 0; i < n; i++) cin >> a[i];
		sort(a, a+n);
		
		int ans = n-2;
		ans = min(ans, a[n-2]-1);
		cout << ans << "\n";
	}
	flush(cout);
	
	return 0;
}