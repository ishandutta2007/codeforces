#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
	int n, m, k;
	cin >> n >> m >> k;
	k--;
	cout << k / (2 * m) + 1 << " " << (k % (2 * m)) / 2 + 1 << " " << (k % 2 ? "R" : "L") << endl;
}