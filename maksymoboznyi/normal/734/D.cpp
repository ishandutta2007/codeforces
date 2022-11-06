#include <bits/stdc++.h>
#define pb push_back
#define int long long
using namespace std;

const int dx[8] = {1, 1, -1, -1, 2, 2, -2, -2};
const int dy[8] = {2, -2, 2, -2, 1, -1, 1, -1};

const int N = 5e5 + 5;

struct cell {
    int x, y;
    char c;
};

bool cmp(cell a, cell b) {
    return abs(a.x) + abs(a.y) < abs(b.x) + abs(b.y);
}

int sign(int v) {
    if (v > 0)
        return 1;
    if (v < 0)
        return -1;
    return 0;
}

bool is_good(cell a) {
    return (a.x == 0 || a.y == 0 || abs(a.x) == abs(a.y));
}

int n;
cell pos, a[N];
map<pair<int, int>, int> is;

signed main()
{
    cin >> n;
    cin >> pos.x >> pos.y;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].c >> a[i].x >> a[i].y;
        a[i].x -= pos.x;
        a[i].y -= pos.y;
    }
    sort(a + 1, a + n + 1, cmp);
    for (int i = 1; i <= n; i++) {
      //  cout << a[i].c << ' ' << a[i].x << ' ' << a[i].y << ' ' << is[{sign(a[i].x), sign(a[i].y)}] << endl;
        if (a[i].c != 'R') {
            if (abs(a[i].x) == abs(a[i].y))
                if (!is[{sign(a[i].x), sign(a[i].y)}])
                    {
                        cout << "YES";
                        return 0;
                    }
        }
        if (a[i].c != 'B') {
            if (a[i].x == 0 && !is[{0, sign(a[i].y)}]) {
                cout << "YES";
                return 0;
            }
            if (a[i].y == 0 && !is[{sign(a[i].x), 0}]) {
                cout << "YES";
                return 0;
            }
        }
        if (is_good(a[i]))
            is[{sign(a[i].x), sign(a[i].y)}] = 1;
    }
    cout << "NO";
    return 0;
}