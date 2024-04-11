#include <iostream>
#include <algorithm>

using namespace std;

int n;
int a[105];
bool used[105];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	sort(a+1, a+n+1);
	
	int ans = 0;
	for(int i = 1; i <= n; i++){
		if(used[i]) continue;
		ans++;
		for(int j = i; j <= n; j++){
			if(a[j] % a[i] == 0) used[j] = true;
		}
	}
	cout << ans << endl;
	
	return 0;
}