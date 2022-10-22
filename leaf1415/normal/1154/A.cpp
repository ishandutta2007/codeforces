#include <iostream>
#include <algorithm>

using namespace std;

int a[4];

int main(void)
{
	for(int i = 0; i < 4; i++) cin >> a[i];
	sort(a, a+4);
	
	for(int i = 0; i < 3; i++) cout << a[3]-a[i] << " "; cout << endl;
	return 0;
}