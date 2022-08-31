#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <bitset>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <queue>

#define mp make_pair
#define pb push_back


typedef long long ll;
typedef long double ld;

using namespace std;

#ifndef LOCAL
#define cerr _cer
struct _cert
{
    template <typename T> _cert& operator << (T) { return *this; }
};
_cert _cer;
#endif

template <typename T> void dprint(T begin, T end) {
    for (auto i = begin; i != end; i++) {
		cerr << (*i) << " ";
    }
    cerr << "\n";
}

int n;
int a[220000];

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%d", a + i);
	sort(a, a + n);
	ll bst = a[n - 1] - a[0];
	ll cnt = 0;
	for (int i = 0; i < n - 1; ++i) {
		ll l = a[i + 1] - a[i];
		if (bst > l)
			bst = l, cnt = 0;
		if (bst == l)
			++cnt;
	}
	cout << bst << " " << cnt << "\n";
	return 0;
}