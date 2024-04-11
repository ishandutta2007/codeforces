#include <iostream>
#define llint long long

using namespace std;

llint n, m, l;
llint a[100005];

int main(void)
{
	cin >> n >> m >> l;
	for(int i = 1; i <= n; i++) cin >> a[i];
	
	llint ans = 0;
	for(int i = 1; i <= n; i++){
		if(a[i] > l && a[i-1] <= l) ans++;
	}
	
	llint t, p, d;
	for(int i = 0; i < m; i++){
		cin >> t;
		if(t == 0) cout << ans << endl;
		else{
			cin >> p >> d;
			if(a[p] <= l && a[p]+d > l){
				if(a[p-1] > l && a[p+1] > l) ans--;
				else if(a[p-1] <= l && a[p+1] <= l) ans++;
			}
			a[p] += d;
		}
	}
	return 0;
}