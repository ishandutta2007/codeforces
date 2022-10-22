#include <iostream>
#include <algorithm>

using namespace std;

int n;
int a[100005];

int main(void)
{
	cin >> n;
	for(int i = 0; i < n; i++) cin >> a[i];
	sort(a, a+n);
	
	int ans = 0, pos = 0;
	for(int i = 0; i < n; i++){
		while(a[i] >= a[pos] && pos < n) pos++;
		if(pos == n) break;
		ans++;
		pos++;
	}
	cout << ans << endl;
	
	return 0;
}