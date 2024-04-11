#include <iostream>

using namespace std;

int n, m;
int a[105];

bool check(int x)
{
	int sum = 0;
	for(int i = 1; i <= n; i++){
		if(a[i] > x) return false;
		sum += x - a[i];
	}
	return sum >= m;
}

int main(void)
{
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i];
	
	int ans;
	for(int i = 1; i <= 20000; i++){
		if(check(i)){
			ans = i;
			break;
		}
	}
	cout << ans << " ";
	
	ans = 0;
	for(int i = 1; i <= n; i++) ans = max(ans, a[i]);
	ans += m;
	cout << ans << endl;
	
	return 0;
}