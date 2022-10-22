#include <iostream>
#include <algorithm>

using namespace std;

int n, k;
int a[105];

int main(void)
{
	cin >> n;
	int l, r;
	for(int i = 0; i < n; i++){
		cin >> l >> r;
		a[i] = r;
	}
	cin >> k;
	
	int p = lower_bound(a, a+n, k) - a;
	cout << n - p << endl;
	
	return 0;
}