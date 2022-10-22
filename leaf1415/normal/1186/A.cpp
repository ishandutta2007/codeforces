#include <iostream>

using namespace std;

int n, m, k;

int main(void)
{
	cin >> n >> m >> k;
	if(n <= min(m, k)) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}