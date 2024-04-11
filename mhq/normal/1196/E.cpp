#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int add = (int)1e6 + 10;
int need = 0;
map < pair < int, int >, bool > mp;
void print(int x, int y) {
    if (mp.count({x, y})) return;
    mp[make_pair(x, y)] = true;
    cout << x + need + add << " " << y + add << '\n';
}
const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};
void solve() {
    int b, w;
    cin >> b >> w;
    need = 0;
    if (b < w) {
        swap(b, w);
        need ^= 1;
    }
    mp.clear();
    if (b > 3 * w + 1) {
        cout << "NO" << '\n';
        return;
    }
    cout << "YES" << '\n';
    if (b - w <= 1) {
        for (int i = 0; i < b + w; i++) {
            print(i + 1, 0);
        }
        return;
    }
    if ((b + w) % 2 == 0) {
        int k = (b - w) / 2;
        int a = (3 * w - b) / 2;
        for (int i = 0; i < k; i++) {
            print(2 * i, 0);
            for (int p = 0; p < 4; p++) {
                if (a == 0 && p == 3 && i == k - 1) {
                }
                else {
                    print(2 * i + dx[p], dy[p]);
                }
            }
        }
        for (int i = 2; i <= 2 * a; i++) {
            print(-i, 0);
        }
    }
    else {
        int k = (b - w - 1) / 2;
        int a = (3 * w + 1 - b) / 2;
        for (int i = 0; i < k; i++) {
            print(2 * i, 0);
            for (int p = 0; p < 4; p++) {
                print(2 * i + dx[p], dy[p]);
            }
        }
        for (int i = 2; i <= 2 * a + 1; i++) {
            print(-i, 0);
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    int tst;
    cin >> tst;
    while (tst--) solve();
    return 0;
}