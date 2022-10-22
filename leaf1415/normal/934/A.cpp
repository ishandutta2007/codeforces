#include <iostream>
#define llint long long
#define inf (llint)(1e18 + 5)

using namespace std;

llint n, m;
llint a[55], b[55];

int main(void)
{
	cin >> n >> m;
	for(int i = 0; i < n; i++) cin >> a[i];
	for(int i = 0; i < m; i++) cin >> b[i];
	
	llint max_val = -inf, max_i;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(max_val < a[i]*b[j]){
				max_val = a[i]*b[j];
				max_i = i;
			}
		}
	}
	
	llint ans = -inf;
	for(int i = 0; i < n; i++){
		if(max_i == i) continue;
		for(int j = 0; j < m; j++){
			ans = max(ans, a[i]*b[j]);
		}
	}
	cout << ans << endl;
	return 0;
}