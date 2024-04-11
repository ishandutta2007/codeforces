#include <set>
#include <map>
#include <cmath>
#include <iostream>
#include <fstream>
#include <unordered_map>
#include <algorithm>
#include <vector>
#include <cassert>
#include <queue>
#include <unordered_set>
#include <chrono>

#define F first
#define S second

using namespace std;
typedef long long ll;
typedef long double ld;

const ll max_n = 200011;

int n, a[max_n], t[max_n];
ll sum_a[max_n], sum_t[max_n], ans[max_n], cnt[max_n];

ll get(int l, int r) {
    ll ans = sum_t[r];
    if (l) ans -= sum_t[l - 1];
    return ans;
}

void update(int a, int l, int r) {
    if (a < t[l]) {
        ans[l] += a;
        return;
    }
    ++cnt[l];
    int first_l = l;
    while (l + 1 != r) {
        int mid = (l + r) / 2;
        if (get(first_l, mid) <= a) {
            l = mid;
        } else {
            r = mid;
        }
    }
    --cnt[r];
    ans[r] += a - get(first_l, l);
    // cout << a << " " << l << endl;
}

int main() {
    cin >> n;
    for (int i =0 ; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    for (int i =0 ; i < n; ++i) {
        scanf("%d", &t[i]);
        sum_t[i] = t[i];
        if (i) sum_t[i] += sum_t[i - 1];
    }
    for (int i =0 ; i < n; ++i) {
        update(a[i], i, n);
    }
    int c = 0;
    for (int i = 0; i < n; ++i) {
        c += cnt[i];
        printf("%I64d ", 1LL * c * t[i] + ans[i]);
        //cout << ans[i] << " " << cnt[i] << endl;
    }
    return 0;
}