#include <algorithm>
#include <cassert>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <string>
#include <vector>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

// #define int long long
#define all(a) a.begin(), a.end()
#define pb push_back
#define eb emplace_back
#define mp make_pair

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    array<array<int, 4>, 3> arr;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            cin >> arr[i][j];
        }
    }

    auto in = [](int L2, int R2, int L1, int R1) {
        return L1 <= L2 && R2 <= R1;
    };

    bool fnd = false;
    if (in(arr[0][0], arr[0][2], arr[1][0], arr[1][2]) && in(arr[0][0], arr[0][2], arr[2][0], arr[2][2])) {
        if (arr[1][1] > arr[2][1]) {
            swap(arr[1], arr[2]);
        }
        if (arr[1][1] <= arr[0][1] && arr[2][1] <= arr[1][3] && arr[0][3] <= arr[2][3]) {
            fnd = true;
        }
        fnd |= in(arr[0][1], arr[0][3], arr[1][1], arr[1][3]);
        fnd |= in(arr[0][1], arr[0][3], arr[2][1], arr[2][3]);
    }
    if (in(arr[0][1], arr[0][3], arr[1][1], arr[1][3]) && in(arr[0][1], arr[0][3], arr[2][1], arr[2][3])) {
        if (arr[1][0] > arr[2][0]) {
            swap(arr[1], arr[2]);
        }
        if (arr[1][0] <= arr[0][0] && arr[2][0] <= arr[1][2] && arr[0][2] <= arr[2][2]) {
            fnd = true;
        }
        fnd |= in(arr[0][0], arr[0][2], arr[1][0], arr[1][2]);
        fnd |= in(arr[0][0], arr[0][2], arr[2][0], arr[2][2]);
    }
    fnd |= (in(arr[0][0], arr[0][2], arr[1][0], arr[1][2]) && in(arr[0][1], arr[0][3], arr[1][1], arr[1][3]));
    swap(arr[1], arr[2]);
    fnd |= (in(arr[0][0], arr[0][2], arr[1][0], arr[1][2]) && in(arr[0][1], arr[0][3], arr[1][1], arr[1][3]));
    cout << (fnd ? "NO\n" : "YES\n");
}