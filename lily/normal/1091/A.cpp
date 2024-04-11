#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long LL;
typedef long double LD;
#define x first
#define y second
#define mp(a, b) make_pair(a, b)
#define read(a) scanf("%d", &a)


int n;

int y, b , r;

int main() {
	cin >> y >> b >> r;
	int ans = min(r - 2, min(b - 1, y));
	cout << (ans >= 1 ? 3 + ans * 3 : -1) << endl;

	return 0;
}