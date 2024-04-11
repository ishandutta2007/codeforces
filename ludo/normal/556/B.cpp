#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iostream>
#include <queue>
#include <set>
#include <string>
#include <utility>
#include <vector>

using namespace std;

#define INF 2147483647
#define MOD 1000000007
#define MAX 100000

typedef long long ll;
typedef pair<int, int> pii;

int main()
{
#ifdef LOCAL
    assert(freopen("input.txt", "r", stdin));
#else
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
#endif // LOCAL

	int n, diff, a;
	cin >> n;

	bool possible = true;

	for (int i = 0; i < n; i++) {
		cin >> a;
		if (i == 0) {
			diff = a;
		} else {
			int nr = a;
			if (i & 1) {
				nr += diff;
				if (nr >= n) nr -= n;
			} else {
				nr -= diff;
				if (nr < 0) nr += n;
			}
			if (nr != i) {
				possible = false;
				break;
			}
		}
	}

	cout << (possible ? "Yes" : "No") << endl;

    return 0;
}