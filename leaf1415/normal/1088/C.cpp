#include <iostream>

using namespace std;

int n;
int a[2005];

int main(void)
{
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	
	cout << n+1 << endl;
	
	cout << 1 << " " << n << " " << 100005 << endl;
	for(int i = 1; i <= n; i++) a[i] += 100005;
	
	for(int i = 1; i <= n; i++){
		cout << 2 << " " << i << " " << a[i]-i << endl;
	}
	return 0;
}