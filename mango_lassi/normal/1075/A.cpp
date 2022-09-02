#include <iostream>
using namespace std;
typedef long long ll;

int main() {
	ll n;
	ll x1, x2;
	cin >> n >> x1 >> x2;
	ll white_dist = max(x1-1, x2-1);
	ll black_dist = max(n-x1, n-x2);
	if (white_dist <= black_dist) cout << "White\n";
	else cout << "Black\n";
}