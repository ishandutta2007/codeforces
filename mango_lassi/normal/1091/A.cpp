#include <iostream>
using namespace std;
typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	ll a, b, c;
	cin >> a >> b >> c;
	ll add = min(a, min(b-1, c-2));
	cout << add + add+1 + add+2 << '\n'; 
}