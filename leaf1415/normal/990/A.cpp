#include <iostream>
#define llint long long

using namespace std;

llint n, m, a, b;

int main(void)
{
	cin >> n >> m >> a >> b;
	cout << min( ((n+m-1)/m*m - n)*a, (n-n/m*m)*b ) << endl;
	return 0;
}