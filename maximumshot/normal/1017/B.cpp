#ifdef debug
#define _GLIBCXX_DEBUG
#endif

#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) begin(x), end(x)

typedef unsigned int ui;
typedef long long ll;
typedef long double ld;
typedef pair< int, int > pii;
typedef pair< long long, long long > pll;

const int inf = 1e9;
const ll inf64 = 1e18;

int get(int x, int y, int z, int w) {
    int mask1 = (x << 0) | (y << 1);
    int mask2 = (z << 0) | (w << 1);
    return mask1 | mask2;
}

ll fa[2][2][2][2];
ll cnt[2][2];

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    int n;
    string a, b;

    cin >> n >> a >> b;

    for(int i = 0;i < n;i++) {
        int x = a[i] - '0';
        int y = b[i] - '0';
        for(int z = 0;z < 2;z++) {
            for(int w = 0;w < 2;w++) {
                fa[z][w][x][y] += cnt[z][w];
            }
        }
        cnt[x][y]++;
    }

    ll res = 0;

    for(int x = 0;x < 2;x++) {
        for(int y = 0;y < 2;y++) {
            for(int z = 0;z < 2;z++) {
                for(int w = 0;w < 2;w++) {
                    if(get(x, y, z, w) == get(y, x, z, w)) continue;
                    res += fa[x][z][y][w];
                }
            }
        }
    }

    cout << res << "\n";

    return 0;
}