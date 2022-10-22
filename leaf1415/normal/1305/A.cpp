#include <iostream>
#include <algorithm>
#define llint long long

using namespace std;

llint T;
llint n;
llint a[1005], b[1005];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	for(int t = 0; t < T; t++){
		cin >> n;
		for(int i = 1; i <= n; i++) cin >> a[i];
		for(int i = 1; i <= n; i++) cin >> b[i];
		sort(a+1, a+n+1), sort(b+1, b+n+1);
		
		for(int i = 1; i <= n; i++) cout << a[i] << " "; cout << endl;
		for(int i = 1; i <= n; i++) cout << b[i] << " "; cout << endl;
	}
	
	return 0;
}