#include <algorithm>
#include <cassert>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <functional>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <string>
#include <vector>

using namespace std;
using ll = long long;

void Main();

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(10);
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    Main();
#ifdef LOCAL
    cout << "\nTime: " << (int)ceil((double)1000 * clock() / CLOCKS_PER_SEC) << " ms";
#endif
}

int n, k;
int cnt_odd, cnt_even;
vector<int> a;

bool check(int val) {
    vector<int> next(n, n);
    int cur = n;
    for (int i = n - 2; i >= 0; i--) {
        if (a[i + 1] <= val) {
            cur = i + 1;
        }
        next[i] = cur;
    }
    {
        int aa = 0, bb = 0;
        int pos = (a[0] <= val ? 0 : next[0]);
        while (pos != n && (aa < cnt_odd || bb < cnt_even)) {
            assert(a[pos] <= val);
            aa++;
            pos++;
            if (pos < n && bb != cnt_even) {
                bb++;
                if (pos < n) {
                    pos = next[pos];
                }
            }
        }
        if (aa == cnt_odd && bb == cnt_even) {
            return true;
        }
    }
    {
        int aa = 0, bb = 0;
        int pos = 0;
        while (pos != n && (aa < cnt_odd || bb < cnt_even)) {
            aa++;
            pos = next[pos];
            if (pos < n && bb != cnt_even) {
                pos++;
                bb++;
            }
        }
        if (aa == cnt_odd && bb == cnt_even) {
            return true;
        }
    }
    return false;
}

void Main() {
    cin >> n >> k;
    cnt_odd = (k + 1) / 2;
    cnt_even = k - cnt_odd;
    a.resize(n);
    for (auto &el : a) {
        cin >> el;
    }
    int L = *min_element(a.begin(), a.end()) - 1;
    int R = *max_element(a.begin(), a.end());
    while (R - L > 1) {
        int mid = (L + R) / 2;
        if (check(mid)) {
            R = mid;
        } else {
            L = mid;
        }
    }
    cout << R << '\n';
}