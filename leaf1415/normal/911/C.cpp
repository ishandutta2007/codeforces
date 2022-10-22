#include <iostream>
#include <algorithm>

using namespace std;

int a[3];

int main(void)
{
	cin >> a[0] >> a[1] >> a[2];
	sort(a, a+3);
	
	if(a[0] == 1) goto yes;
	if(a[0] == 2 && a[1] == 2) goto yes;
	if(a[0] == 2 && a[1] == 4 && a[2] == 4) goto yes;
	if(a[0] == 3 && a[1] == 3 && a[2] == 3) goto yes;
	cout << "NO" << endl;
	return 0;
	
	yes:;
	cout << "YES" << endl;
	return 0;
}