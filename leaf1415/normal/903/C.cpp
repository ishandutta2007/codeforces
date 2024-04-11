#include <iostream>
#include <algorithm>

using namespace std;

int n;
int a[5005];

int main(void)
{
	cin >> n;
	for(int i = 0; i < n; i++) cin >> a[i];
	sort(a, a+n);
	
	int ans = 1;
	int prev = -1, cnt = 0;
	for(int i = 0; i < n; i++){
		if(a[i] == prev){
			cnt++;
			ans = max(ans, cnt);
		}
		else{
			cnt = 1;
		}
		prev = a[i];
	}
	cout << ans << endl;
	return 0;
}