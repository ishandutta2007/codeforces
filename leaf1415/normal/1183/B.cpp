#include <iostream>
#define llint long long

using namespace std;

llint Q;
llint n, k;
llint a[105];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> Q;
	for(int q = 0; q < Q; q++){
		cin >> n >> k;
		for(int i = 0; i < n; i++) cin >> a[i];
		
		llint l = 0, r = 1e18;
		for(int i = 0; i < n; i++){
			l = max(l, a[i]-k);
			r = min(r, a[i]+k);
		}
		if(l > r) cout << -1 << endl;
		else cout << r << endl;
	}
	return 0;
}