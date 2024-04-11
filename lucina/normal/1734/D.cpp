#include<bits/stdc++.h>
using namespace std;
const int nax = 3e5 + 10;
const int64_t INF = 1e17;
int n, k;
int64_t a[nax];


bool solve() {
    cin >> n >> k;
    for (int i = 1 ; i <= n ; ++ i) {
        cin >> a[i];
    }

    int64_t sum = 0, min_neg = 0;
    vector <pair <int64_t, int64_t>> x, y;

    for (int i = k + 1 ; i <= n ; ++ i) {
        sum += a[i];
        if (sum >= 0) {
            x.emplace_back(sum, min_neg);
            sum = 0;
            min_neg = 0;
        } else {
            min_neg = min(min_neg, sum);
        }
    }
    int64_t need_x = 0, need_y = 0;
    if (sum < 0) need_x = -min_neg;

    sum = 0, min_neg = 0;

    for (int i = k - 1 ; i >= 1 ; -- i) {
        sum += a[i];
        if (sum >= 0) {
            y.emplace_back(sum, min_neg);
            sum = 0;
            min_neg = 0;
        } else {
            min_neg = min(min_neg, sum);
        }
    }
    if (sum < 0) need_y = -min_neg;
    int64_t X = a[k];
    reverse(x.begin(), x.end()), reverse(y.begin(), y.end());

    while (true) {
        if (!x.empty()) {
            if (X + x.back().second >= 0) {
                X += x.back().first;
                x.pop_back();
                continue;
            }
        }
        if (!y.empty()) {
            if (X + y.back().second >= 0) {
                X += y.back().first;
                y.pop_back();
                continue;
            }
        }
        break;
    }
    if (x.empty() && X >= need_x) return true;
    if (y.empty() && X >= need_y) return true;
    return false;

    /**
        |           |

        There's no merit going left to right

        Considering it as two seperate arrays split by k

        [neg, neg, neg|S             ]
    */
}

int main() {
    cin.tie(0)->sync_with_stdio(false);
    int T;

    for (cin >> T ; T -- ;) {
        cout << (solve() ? "YES" : "NO") << '\n';
    }
}