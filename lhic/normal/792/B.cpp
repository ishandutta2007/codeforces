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

int main() {
	int n, k;
	cin >> n >> k;
	vector<int> vv;
	for (int i = 0; i < n; ++i)
		vv.push_back(i + 1);
	for (int i = 0; i < k; ++i) {
		int a;
		cin >> a;
		a %= vv.size();
		for (int j = 0; j < a; ++j)
			rotate(vv.begin(), vv.begin() + 1, vv.end());
		cout << vv[0] << " ";
		vv.erase(vv.begin());
	}
	cout << "\n";
	return 0;
}