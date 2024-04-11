#include <iostream>

using namespace std;

int n, m;
int c[1005], a[1005];

int main(void)
{
	cin >> n >> m;
	for(int i = 0; i < n; i++) cin >> c[i];
	for(int i = 0; i < m; i++) cin >> a[i];
	
	int p = 0;
	int ans = 0;
	for(int i = 0; i < n; i++){
		if(p >= m) break;
		if(a[p] >= c[i]){
			p++;
			ans++;
		}
	}
	cout << ans << endl;
	return 0;
}