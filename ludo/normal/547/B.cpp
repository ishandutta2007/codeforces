#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iostream>
#include <set>
#include <string>
#include <utility>
#include <vector>

#ifdef LOCAL
#include <cassert>
#endif // LOCAL

using namespace std;

#define INF 2147483647
#define MOD 1000000007
#define MAX 200000

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<pii, pii> qii;

int n, a[MAX];

int l[MAX], r[MAX], ans[MAX + 1];

int stck[MAX], stck_size;

#undef LOCAL

int main()
{
#ifdef LOCAL
    assert(freopen("input.txt", "r", stdin));
#else
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
#endif // LOCAL

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	stck_size = 0;
	for (int i = 0; i < n; i++) {
		while (stck_size > 0 && a[stck[stck_size - 1]] >= a[i]) {
			stck_size--;
		}
		l[i] = (stck_size == 0) ? -1 : stck[stck_size - 1];
		stck[stck_size++] = i;
	}

	stck_size = 0;
	for (int i = n; --i >= 0;) {
		while (stck_size > 0 && a[stck[stck_size - 1]] >= a[i]) {
			stck_size--;
		}
		r[i] = (stck_size == 0) ? n : stck[stck_size - 1];
		stck[stck_size++] = i;
	}

	for (int i = 0; i < n; i++) {
		int len = r[i] - l[i] - 1;
		if (a[i] > ans[len]) {
			ans[len] = a[i];
		}
	}

//	ofstream out("debug.txt");
//	for (int i = 0; i < n; i++) {
//		out << i << ": "  << l[i] << ", " << r[i] << endl;
//	}

	for (int i = n; i > 0; i--) {
		if (ans[i] > ans[i - 1]) {
			ans[i - 1] = ans[i];
		}
	}

	for (int i = 1; i <= n; i++) {
		cout << ans[i] << ' ';
	}
    return 0;
}