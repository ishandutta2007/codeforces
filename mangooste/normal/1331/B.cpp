#include <algorithm>
#include <cmath>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

using ll = long long;
using namespace std;

// #define int long long
#define all(a) a.begin(), a.end()

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int a;
    cin >> a;
    for (int i = 2; i <= a; i++) {
        if (a % i)
            continue;
        while (a % i == 0) {
            cout << i;
            a /= i;
        }
    }
}