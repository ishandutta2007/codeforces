#include <iostream>
#define inf 1000000005

using namespace std;

int n;
int a[100005];

int main(void)
{
	cin >> n;
	for(int i = 0; i < n; i++) cin >> a[i];
	
	int m = inf;
	for(int i = 0; i < n; i++) m = min(m, a[i]);
	
	int prev = -inf, ans = inf;
	for(int i = 0; i < n; i++){
		if(a[i] == m){
			ans = min(ans, i - prev);
			prev = i;
		}
	}
	cout << ans << endl;
	return 0;
}