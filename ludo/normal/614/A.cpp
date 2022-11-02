#include <iostream>

using namespace std;

typedef long long ll;

int main()
{
	ll a, b, c;
	cin >> a >> b >> c;
	ll r = 1;
	bool first = true;
	while (r <= b) {
		if (r >= a) {
			if (first) first = false;
			else cout << " ";

			cout << r;
		}
		if (r > b / c) {
			break;
		}
		r = (r * c);
	}
	if (first) cout << "-1";
	cout << endl;
    return 0;
}