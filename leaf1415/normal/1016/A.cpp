#include <iostream>
#define llint long long

using namespace std;

llint n, m;
llint a[200005];

int main(void)
{
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i];
	
	llint sum = 0;
	for(int i = 1; i <= n; i++){
		cout << (sum+a[i])/m - sum/m << " ";
		sum += a[i];
	}
	cout << endl;
	return 0;
}