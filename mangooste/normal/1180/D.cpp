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
    int n, m;
    cin >> n >> m;
    int L = 1, R = n;
    while (R > L) {
        int down = 1, up = m;
        int cur = 0;
        while (up > 0) {
            if (cur == 0)
                cout << L << ' ' << down++ << '\n';
            else
                cout << R << ' ' << up-- << '\n';
            cur ^= 1;
        }
        L++, R--;
    }
    if (R == L)
        for (int i = 0, Li = 1, Ri = m; i < m; i++)
            if (i % 2 == 0)
                cout << L << ' ' << Li++ << '\n';
            else
                cout << L << ' ' << Ri-- << '\n';
}