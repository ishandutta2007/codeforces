#include <iostream>
#include <string>
#define llint long long

using namespace std;

llint n;
llint a[100005];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	
	llint sum = 0;
	for(int i = 1; i <= n; i++) sum += a[i];
	if(sum % 2){
		cout << "NO" << endl;
		return 0;
	}
	
	llint mx = 0;
	for(int i = 1; i<= n; i++) mx = max(mx, a[i]);
	if(mx > sum/2) cout << "NO" << endl;
	else cout << "YES" << endl;
	
	return 0;
}