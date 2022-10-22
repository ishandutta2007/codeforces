#include <iostream>

using namespace std;

int n;
int a[200005];

int main(void)
{
	cin >> n;
	for(int i = 0; i < n; i++) cin >> a[i];
	
	int pre = -1, len = 0, ans = 0;
	for(int i = 0; i < n; i++){
		if(pre == -1 || a[i-1]*2 >= a[i]){
			len++;
		}
		else{
			ans = max(ans, len);
			len = 1;
		}
		pre = a[i];
	}
	ans = max(ans, len);
	cout << ans << endl;
	
	return 0;
}