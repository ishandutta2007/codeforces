#include <iostream>

using namespace std;

int n;
int a[15];

int main(void)
{
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	
	int mn = 100;
	for(int i = 1; i <= n; i++) mn = min(mn, a[i]);
	cout << (a[3]^mn)+2 << endl;
	
	return 0;
}