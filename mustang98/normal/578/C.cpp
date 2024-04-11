#include <bits/stdc++.h>

#define F first
#define S second
#define PB push_back
#define MP make_pair

using namespace std;

typedef long long ll;
typedef long double ld;

const int max_n = 200111;

int a[max_n];
ld b[max_n];
int n;

ld max_sub_sum() {
    ld ans = 0;
    ld cur_sub = 0;
    for (int i = 0; i < n; ++i) {
        cur_sub += b[i];
        if (cur_sub < 0) {
            cur_sub = 0;
        }
        ans = max(ans, cur_sub);
    }
    return ans;
}

ld check(ld x) {
    for (int i = 0; i < n; ++i) {
        b[i] = a[i] - x;
    }
    ld ans1 = max_sub_sum();
    for (int i = 0; i < n; ++i) {
        b[i] = -b[i];
    }
    return max(ans1, max_sub_sum());
}

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        scanf("%d", a + i);
    }
    ld l = -1e6, r = 1e6;

    for (int i = 0; i < 100; ++i) {
        ld mid1 = l + (r - l) / 3;
        ld mid2 = l + 2 * (r - l) / 3;
        if (check(mid1) > check(mid2)) {
            l = mid1;
        } else {
            r = mid2;
        }
    }
    cout << fixed << setprecision(10) << check(l);
}