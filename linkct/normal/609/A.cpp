#include <iostream>
#include <algorithm>
using namespace std;

int n, m, a[105];

int main(){
	int i;
	cin >> n >> m;
	for(i = 1; i <= n; ++ i) cin >> a[i];
	sort(a + 1, a + 1 + n);
	for(i = n; i && m > 0; -- i) m -= a[i];
	cout << n - i << endl;
	return 0;
}