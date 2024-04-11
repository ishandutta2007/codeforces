#include <algorithm>
#include <cmath>
#include <cstring>
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
    int n, m, p;
    cin >> n >> m >> p;
    int pos1 = -1, pos2 = -1;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        if (a % p != 0 && pos1 == -1)
            pos1 = i;
    }
    for (int i = 0; i < m; i++) {
        int b;
        cin >> b;
        if (b % p != 0 && pos2 == -1)
            pos2 = i;
    }
    cout << pos1 + pos2 << '\n';
}