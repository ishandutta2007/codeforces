#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll a, b, c, d; 

int main() {
	cin >> a >> b >> c >> d;
	ll tmp = a / b;
	ll a1 = tmp * b, a2 = (tmp + 1) * b;
	cout << min((a2 - a) * c, (a - a1) * d) << endl;
	return 0;
}