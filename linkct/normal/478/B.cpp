#include <iostream>
using namespace std;
typedef long long int ll;

ll n, m;

int main(){
	cin >> n >> m;
	cout << ((n / m + 1) * (n / m) / 2) * (n % m) + (n / m) * (n / m - 1) / 2 * (m - n % m) << ' ' << (n - m + 1) * (n - m) / 2 << endl;
	return 0;
}