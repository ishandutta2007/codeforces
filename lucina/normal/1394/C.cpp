#include<bits/stdc++.h>
using namespace std;
int const nax = 5e5 + 10;
const int INF = 1e8;
char s[nax];
int n;
constexpr pair <bool, tuple <int, int, int>> fail = make_pair(false, make_tuple(-1, -1, -1));

void read(pair <int, int> &x) {
    cin >> s;
    int len = strlen(s);
    x.first = count(s, s + len, 'B');
    x.second = len - x.first;
}

pair <bool, tuple <int, int, int>> make_shit(int rad, int a, int b) {
    return make_pair(true, make_tuple(rad, a, b));
}

int glob_min_x = INF, glob_max_x = -INF;
int glob_min_y = INF, glob_max_y = -INF;
int glob_min_yx = INF, glob_max_yx = -INF;

pair <bool, tuple <int, int, int>> test(int rad) {
    int min_x = max(0, glob_max_x - rad);
    int max_x = glob_min_x + rad;
    int min_y = max(0, glob_max_y - rad);
    int max_y = glob_min_y + rad;
    int min_yx = glob_max_yx - rad;
    int max_yx = glob_min_yx + rad;

    if (min_x > max_x || min_y > max_y || min_yx > max_yx) return fail;

    int lx = min_x, ly = min_y, hx = max_x, hy = max_y;

    auto in_rect = [&](int x, int y)->bool {
        return x >= lx && x <= hx && y >= ly && y <= hy;
    };

    #define I_hate_geometry if (in_rect(cx, cy) && max(cx, cy) > 0) return make_shit(rad, cx, cy);

    int cx, cy;
    cx = hx, cy = max_yx + hx;
    I_hate_geometry
    cx = hx, cy = min_yx + hx;
    I_hate_geometry
    cy = hy, cx = hy - max_yx;
    I_hate_geometry
    cy = hy, cx = hy - min_yx;
    I_hate_geometry

    return fail;
}

int main () {
    cin.tie(0)->sync_with_stdio(false);
    cin >> n;


    for (int i = 1 ; i <= n ; ++ i) {
        static pair <int, int> buf;
        read(buf);
        glob_min_x = min(glob_min_x, buf.first);
        glob_max_x = max(glob_max_x, buf.first);
        glob_min_y = min(glob_min_y, buf.second);
        glob_max_y = max(glob_max_y, buf.second);
        glob_min_yx = min(glob_min_yx, buf.second - buf.first);
        glob_max_yx = max(glob_max_yx, buf.second - buf.first);
    }

    int l = 0, r = 5e5 + 10;
    tuple <int, int, int> ans = make_tuple(-1, -1, -1);

    while (l <= r) {
        int mid = l + r >> 1;
        auto [result, p] = test(mid);
        if (result) {
            ans = p;
            r = mid - 1;
        } else l = mid + 1;
    }

    const auto &[val, a, b] = ans;
    cout << val << '\n';
    cout << string(a, 'B') << string(b, 'N') << '\n';

}
/**
    similar <=> number of 'A' and 'B' are equal
    4 operations
    remove one char
    remove 'AB' or 'BA'
    add char to the end of string
    add 'AB' or 'BA' at the en
    We notice the order of character doesn't matter.
    The problem reduces to transform pair
    (x, y)->(a, b)
    you can do these operations
    (x, y)->(x - 1, y - 1) if (x > 0 && y > 0)
    (x, y)->(x + 1, y + 1)
    (x, y)->(x + 1, y)
    (x, y)->(x, y + 1)
    (x, y)->(x - 1, y) if (x > 0)
    (x, y)->(x, y - 1)
    let's say we can do at most L operations what area we can achieve

           _ _ _ _ _
        / |          |
      /   |          |
    /     |          |
  /       |          |
/_ _ _ _ _|P_ _ _ _ _|
|         |         /
|         |       /
|         |     /
|         |   /
|         | /
|_ _ _ _ _|/

    A lame hexagon. Note that these areas also bound by (x >= 0 and y >= 0)
    These hexagon are bounded by 6 inequalities.
    y <= x + c1
    y >= x + c2

    y - x >= something
    y - x <= something
    y <= y1
    y >= y2
    x <= x1
    x >= x2

    Well check intersection of these inequalities is not hard.
    Just not forgot that this should be bounded by (x >= 0 and y >= 0)
    And (x = 0, y = 0) is not available...
*/