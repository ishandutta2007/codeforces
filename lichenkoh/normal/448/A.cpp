#include <iostream>
using namespace std;
#define ll long long
int main()
{
	ll a1, a2, a3, b1, b2, b3, n;
	cin >> a1; cin >> a2; cin >> a3;
	cin >> b1; cin >> b2; cin >> b3;
	cin >> n;
	ll a = a1+a2+a3;
	ll b = b1+b2+b3;
	ll needed = ((a+4)/5) + ((b+9)/10);
	if (needed <= n) {
		cout << "YES" << endl;
	}
	else {
		cout << "NO" << endl;
	}
}