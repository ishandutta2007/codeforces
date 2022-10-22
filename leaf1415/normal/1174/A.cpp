#include <iostream>
#include <algorithm>

using namespace std;

int n;
int a[2005];

int main(void)
{
	cin >> n;
	for(int i = 0; i < 2*n; i++) cin >> a[i];
	sort(a, a+2*n);
	
	if(a[0] == a[2*n-1]) cout << -1 << endl;
	else{
		for(int i = 0; i < 2*n; i++) cout << a[i] << " "; cout << endl;
	}
	return 0;
}