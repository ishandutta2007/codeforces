#include <iostream>
#define llint long long

using namespace std;

llint n;
llint a[200005];

int main(void)
{
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	
	llint sum = 0;
	for(int i = 1; i <= n; i++) sum += a[i];
	
	llint cnt = 0, ans;
	for(int i = 1; i <= n; i++){
		cnt += a[i];
		if(cnt >= (sum+1)/2){
			ans = i;
			break;
		}
	}
	cout << ans << endl;
	return 0;
}