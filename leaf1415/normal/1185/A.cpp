#include <iostream>
#include <algorithm>
#define llint long long

using namespace std;

llint a[3], d;

int main(void)
{
	for(int i = 0; i < 3; i++) cin >> a[i];
	cin >> d;
	sort(a, a+3);
	cout << max(d-(a[1]-a[0]), 0LL) + max(d-(a[2]-a[1]), 0LL) << endl;
	return 0;
}