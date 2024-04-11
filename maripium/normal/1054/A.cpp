#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	int x, y, z, t1, t2, t3; cin >> x >> y >> z >> t1 >> t2 >> t3;
	int stairs = abs(x - y) * t1;
	int eve = abs(z - x) * t2 + 3 * t3 + abs(x - y) * t2;
	cout << (eve <= stairs ? "YES" : "NO") << '\n';
}