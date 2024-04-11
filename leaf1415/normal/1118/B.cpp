#include <iostream>
#define llint long long

using namespace std;

llint n;
llint a[200005];
llint odd[200005], even[200005];

int main(void)
{
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 1; i <= n; i++){
		odd[i] = odd[i-1], even[i] = even[i-1];
		if(i%2) odd[i] += a[i];
		else even[i] += a[i];
	}
	
	llint ans = 0;
	for(int i = 1; i <= n; i++){
		if(even[i-1] + odd[n]-odd[i] == odd[i-1] + even[n]-even[i]) ans++;
	}
	cout << ans << endl;
	
	return 0;
}