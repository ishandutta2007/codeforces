#include <iostream>
#define llint long long

using namespace std;

llint T;
llint n, d;
llint a[105];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	for(int t = 0; t < T; t++){
		
		cin >> n >> d;
		for(int i = 1; i <= n; i++) cin >> a[i];
		
		llint ans = a[1];
		for(int i = 2; i <= n; i++){
			llint x = min(a[i], d/(i-1));
			ans += x;
			d -= x*(i-1);
		}
		cout << ans << endl;
	}
	
	return 0;
}