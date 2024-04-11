#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int w1, h1, w2, h2;
	cin >> w1 >> h1 >> w2 >> h2;

	int res = 0;
	res += h1 + h2 + 2; // Left side
	res += w1 + w2; // Bottom and Top sides
	res += h1 + h2 + 2; // Right side
	res += abs(w1 - w2); // Middle
	cout << res << '\n';
}