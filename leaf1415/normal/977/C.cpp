#include <iostream>
#include <algorithm>

using namespace std;

int n, k;
int a[200005];

int main(void)
{
	cin >> n >> k;
	for(int i = 0; i < n; i++) cin >> a[i];
	sort(a, a+n);
	
	if(k == 0){
		if(a[0] == 1) cout << -1 << endl;
		else cout << 1 << endl;
		return 0;
	}
	
	if(k-1 >= n) cout << -1 << endl;
	else if(a[k-1] == a[k]) cout << -1 << endl;
	else cout << a[k-1] << endl;
	return 0;
}