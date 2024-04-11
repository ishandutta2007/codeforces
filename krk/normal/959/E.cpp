#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <map>
#include <iomanip>
using namespace std;

typedef long long ll;

ll n;

int main() {
    cin >> n;
    ll res = 0, cur = 1;
    while (n > 1) {
        res += n / 2 * cur;
        n = (n + 1) / 2;
        cur *= 2;
    }
    cout << res << endl;
	return 0;
}