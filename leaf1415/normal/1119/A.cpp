#include <iostream>

using namespace std;

int n;
int c[300005];

int main(void)
{
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> c[i];
	if(c[1] != c[n]){
		cout << n-1<< endl;
		return 0;
	}
	int ans = 0;
	for(int i = 1; i <= n; i++){
		if(c[i] != c[n]){
			ans = max(ans, n-i);
			break;
		}
	}
	for(int i = n; i >= 1; i--){
		if(c[i] != c[1]){
			ans = max(ans, i-1);
			break;
		}
	}
	cout << ans << endl;
	
	return 0;
}