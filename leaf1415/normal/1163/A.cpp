#include <iostream>

using namespace std;

int n, m;

int main(void)
{
	cin >> n >> m;
	if(m == 0) cout << 1 << endl;
	else cout << min(m, n-m) << endl;
	return 0;
}